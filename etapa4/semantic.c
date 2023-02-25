/*
    Gabriel Madeira (00322863)
*/

#include "semantic.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int SemanticErrors = 0;
AST *Root;

int convertToDatatype(int type) {
    if(type == AST_INTE)
        return DATATYPE_INTE;
    if(type == AST_CARA)
        return DATATYPE_CARA;
    if(type == AST_REAL)
        return DATATYPE_REAL;
    return -1;
}

int integerOrChar(int datatype) {
    return (datatype == DATATYPE_INTE || datatype == DATATYPE_CARA);
}

int datatypeCompatible(int datatype1, int datatype2) {
    return datatype1 == datatype2 || (integerOrChar(datatype1) && integerOrChar(datatype2));
}

int checkSize(AST* node, int size) {
	if(node != 0) {
		return checkSize(node->son[1], size + 1);
		if(node->son[1] != 0) return size;
	}

	return size;
}

int checkVectorElements(AST *node, int datatype) {
    if(node) {
		if((node->son[0]->type != AST_SYMBOL) || !datatypeCompatible(node->son[0]->symbol->datatype, datatype)) 
            return 0;
		if(node->son[1]) 
            return checkVectorElements(node->son[1], datatype);
	}

	return 1;
}

void setDeclarations(AST *node) {
    
    if(!node) return;

    switch(node->type){
        case AST_GVAR:
            if(node->symbol->type != SYMBOL_LIT_IDENTIFIER) {
                fprintf(stderr, "Semantic Error: variable %s redeclared.\n", 
                node->symbol->text);
                SemanticErrors++;
            }
            node->symbol->type = SYMBOL_VAR;
            //node->symbol->dec = node;
            //if(node->son[0])
            node->symbol->datatype = convertToDatatype(node->son[0]->type);

            if(!datatypeCompatible(node->symbol->datatype, node->son[1]->symbol->datatype)){
				fprintf(stderr, "Semantic Error: variable %s declaration not compatible (%d %d) \n", node->symbol->text, node->symbol->datatype, node->son[1]->symbol->datatype);
				SemanticErrors++;
			}
            break;
        case AST_GARR:
            if(node->symbol->type != SYMBOL_LIT_IDENTIFIER) {
                fprintf(stderr, "Semantic Error: vector %s redeclared.\n", 
                node->symbol->text);
                SemanticErrors++;
            }
            node->symbol->type = SYMBOL_VECTOR;
            //node->symbol->dec = node;
            if(node->son[0])
                node->symbol->datatype = convertToDatatype(node->son[0]->type);

            int size = checkSize(node->son[2], 0);
            int declaredSize = atoi(node->son[1]->symbol->text);

            if(declaredSize != size) {
                fprintf(stderr, "Semantic Error: vector %s declaration size is not compatible \n", node->symbol->text);
                SemanticErrors++;
            }

			if(!checkVectorElements(node->son[2], node->symbol->datatype)) {
				fprintf(stderr, "Semantic Error: vector %s element not compatible \n", node->symbol->text);
				SemanticErrors++;
			}
            break;
        case AST_LDCF: 
            if(node->symbol->type != SYMBOL_LIT_IDENTIFIER) {
                fprintf(stderr, "Semantic Error: function %s redeclared.\n", 
                node->symbol->text);
                SemanticErrors++;
            }
            //fprintf(stderr, "FUNCTION %s DEFINED\n",node->symbol->text);
            node->symbol->type = SYMBOL_FUNCTION;
            //node->symbol->dec = node;
            if(node->son[0])
                node->symbol->datatype = convertToDatatype(node->son[0]->type);
            break;
        case AST_FPL:
            if(node->symbol->type != SYMBOL_LIT_IDENTIFIER) {
                fprintf(stderr, "Semantic Error: function var %s redeclared.\n", 
                node->symbol->text);
                SemanticErrors++;
            }
            node->symbol->type = SYMBOL_VAR; // AST_FPL??
            //node->symbol->dec = node;
            if(node->son[0])
                node->symbol->datatype = convertToDatatype(node->son[0]->type);
        default: 
            break;
    }

    for(int i=0; i<MAX_SONS; i++){
        setDeclarations(node->son[i]); 
    }
            
}
void checkUndeclared(void) {
    SemanticErrors += hashCheckUndeclared();
}

int getSemanticErrors(void) {
    return SemanticErrors;
}

int isAritmeticOp(int nodetype) {
    return (nodetype == AST_ADD || nodetype == AST_SUB || nodetype == AST_MUL || nodetype == AST_DIV);
}

int getDatatype(int type1, int type2) {
    return (type1 > type2) ? type1 : type2;
}

int isRelationalOp(int nodetype) {
    return (nodetype == AST_LES || nodetype == AST_GRE || nodetype == AST_EQ || nodetype == AST_LE || nodetype == AST_GE || nodetype == AST_DIF);
}

int isLogicalOp(int nodetype) {
    return (nodetype == AST_AND || nodetype == AST_OR || nodetype == AST_NOT);
}

void checkOperands(AST* node) {
    if(!node) return;

    for(int i=0; i<MAX_SONS; i++){
        checkOperands(node->son[i]); 
    }

    if(node->type == AST_SYMBOL) {
        if(node->symbol->type == SYMBOL_VECTOR || node->symbol->type == SYMBOL_FUNCTION) {
            fprintf(stderr, "Semantic Error: %s is not a variable \n", node->symbol->text);
            SemanticErrors++;
        }

        node->datatype = node->symbol->datatype;
        
    } else if(node->type == AST_FCALL || node->type == AST_ACALL) {
        node->datatype = node->symbol->datatype;
    } else if(node->type == AST_PAR) {
        node->datatype = node->son[0]->datatype;
    } else if(isAritmeticOp(node->type)) {
        AST* son0 = node->son[0];
        AST* son1 = node->son[1];
        
        if(!datatypeCompatible(son0->datatype, son1->datatype) || son0->datatype == DATATYPE_BOOL || son1->datatype == DATATYPE_BOOL) {
            fprintf(stderr, "Semantic Error: arithmetic operation with incompatible data types.\n");
            SemanticErrors++;
        }
    
        node->datatype = getDatatype(son0->datatype, son1->datatype);
    
    } else if(isRelationalOp(node->type)) {

        AST* son0 = node->son[0];
        AST* son1 = node->son[1];
        
        if(!datatypeCompatible(son0->datatype, son1->datatype) || son0->datatype == DATATYPE_BOOL || son1->datatype == DATATYPE_BOOL) {
            fprintf(stderr, "Semantic Error: relational operation with incompatible data types.\n");
            SemanticErrors++;
        }

        node->datatype = DATATYPE_BOOL;

    } else if(isLogicalOp(node->type)) {

        if (node->type == AST_NOT) {
            if(node->son[0]->datatype != DATATYPE_BOOL) {
                fprintf(stderr, "Semantic Error: logical operation with incompatible data types.\n");
                SemanticErrors++;
            }

        } else if(node->son[0]->datatype != DATATYPE_BOOL || node->son[1]->datatype != DATATYPE_BOOL) {
            fprintf(stderr, "Semantic Error: logical operation with incompatible data types.\n");
            SemanticErrors++;
        }
        
        node->datatype = DATATYPE_BOOL;
    } else if(node->type == AST_ENTRADA) {
        node->datatype = DATATYPE_INTE;
    }
}

AST* findDeclaration(char * name, AST * node) {
	if(node->symbol != NULL && strcmp(node->symbol->text, name) == 0) return node;

	for(int i = 0; i < MAX_SONS; i++) {
        if(node->son[i] == 0) continue;
		if(node->son[i] == NULL) return NULL;
		AST *finding = findDeclaration(name, node->son[i]);
		if(finding != NULL) return finding;
	}

	return NULL;
}

int getNumberOfArguments(AST *node) {
	if(node == 0) return 0;

	return (node->son[1] != 0) ? 1 + getNumberOfArguments(node->son[1]) : 0;
}

int validateNumberOfArguments(AST *node, AST *declaration) {
	int numberOfCalledArguments = getNumberOfArguments(node->son[0]);
	int numberOfDeclaredArguments = getNumberOfArguments(declaration->son[1]);	

	if(numberOfCalledArguments != numberOfDeclaredArguments) {
	    fprintf(stderr, "Semantic error (line %d): Incompatible number of arguments.\n", node->lineNumber);
		SemanticErrors++;
		return 0;
	}

	return 1;
}

void compareCalledArguments(AST *node, AST *declaration) {
	if(node->son[0] != 0) {
		if(!datatypeCompatible(node->son[0]->datatype, declaration->symbol->datatype)) {
			fprintf(stderr, "Semantic Error (line %d): Incompatible argument types\n", node->lineNumber);
			SemanticErrors++;
		}
		
        if(node->son[0]->type == AST_SYMBOL) {
            if(node->son[0]->symbol->type == SYMBOL_FUNCTION) {
				fprintf(stderr, "Semantic Error (line %d): Cannot pass function as argument\n", node->lineNumber);
				SemanticErrors++;
            } else if(node->son[0]->symbol->type == SYMBOL_VECTOR) {
		        fprintf(stderr, "Semantic Error (line %d): Cannot pass vector as argument\n", node->lineNumber);
			    SemanticErrors++;
            }
        }

		if(node->son[1] != 0) compareCalledArguments(node->son[1], declaration->son[1]);
	}
}

void validateFunction(AST *node) {
	AST* declaration = findDeclaration(node->symbol->text, Root);
    	
	if(declaration == 0 || declaration->type != AST_LDCF) {
        fprintf(stderr, "Semantic Error (line %d): only functions can be called, %s is not a function.\n", node->lineNumber, node->symbol->text);
        SemanticErrors++;
	} 
    else if(validateNumberOfArguments(node, declaration)) {
        if(declaration->son[1]) compareCalledArguments(node->son[0], declaration->son[1]);					
	}
}

void checkWrite(AST *node) {
    if (node == 0) return;

    // if(node->son[0]->type == AST_SYMBOL) { 
    //     if(node->son[0]->symbol->type == SYMBOL_FUNCTION) {
    //         fprintf(stderr, "Semantic Error (line %d): Cannot print function\n", node->lineNumber);
    //         SemanticErrors++;
    //     } else if(node->son[0]->symbol->type == SYMBOL_VECTOR) {
    //         fprintf(stderr, "Semantic Error (line %d): Cannot print vector\n", node->lineNumber);
    //         SemanticErrors++;
    //     }
    // }

    checkWrite(node->son[1]);
}

void checkCorrectUse(AST* node) { //check nature - garantir que var,vetor,funcao seja usadada como var,vetor,funcao
    if(!node) return;

    switch(node->type){
        case AST_ASS: // PRECISA?
            if(node->symbol->type != SYMBOL_VAR) {
                fprintf(stderr, "Semantic Error (line %d): attribution must be to a scalar variable.\n", node->lineNumber);
		        SemanticErrors++;
            }

			if(!datatypeCompatible(node->symbol->datatype, node->son[0]->datatype)) {
				fprintf(stderr, "Semantic Error (line %d): attribution with incompatible data type.\n", node->lineNumber);
				SemanticErrors++;
			}
            break;
        case AST_ARAS:
            if(node->symbol->type != SYMBOL_VECTOR) {
           	    fprintf(stderr, "Semantic Error (line %d): indexing only allowed for vectors.\n", node->lineNumber);
	           	SemanticErrors++;
            }

            if(!datatypeCompatible(node->symbol->datatype, node->son[1]->datatype)) {
		        fprintf(stderr, "Semantic Error (line %d): attribution with incompatible data type.\n", node->lineNumber);
                SemanticErrors++;
			}

	        if(!integerOrChar(node->son[0]->datatype)) {
		        fprintf(stderr, "Semantic Error (line %d): index must be an integer.\n", node->lineNumber);
                SemanticErrors++;
            }
            break;
        //case AST_VARCALL: 
            // if((node->son[0] || (node->symbol->type != SYMBOL_VAR)) && node->symbol->type != SYMBOL_LIT_IDENTIFIER) {
            //     fprintf(stderr, "Semantic Error: incorrect use, %s is not a variable.\n", node->symbol->text);
            //     SemanticErrors++;
            // }
        //    break;
        case AST_FCALL:
            // if(node->symbol->type != SYMBOL_FUNCTION && node->symbol->type != SYMBOL_LIT_IDENTIFIER) {
            //     fprintf(stderr, "Semantic Error: incorrect use, %s is not a function.\n", node->symbol->text);
            //     SemanticErrors++;
            // }
            validateFunction(node);
            break;
        case AST_ACALL: 
            // if((!node->son[0] || node->symbol->type != SYMBOL_VECTOR) && node->symbol->type != SYMBOL_LIT_IDENTIFIER) {
            //     fprintf(stderr, "Semantic Error: incorrect use, this element is not a vector.\n");
            //     SemanticErrors++;
            // }
            
            AST* declaration = findDeclaration(node->symbol->text, Root);
            if(declaration == 0 || declaration->type != AST_GARR) {
                fprintf(stderr, "Semantic Error (line %d): %s is not a vector.\n", node->lineNumber, node->symbol->text);
            }

            if(node->son[0]->datatype != DATATYPE_CARA && node->son[0]->datatype != DATATYPE_INTE) {
            	fprintf(stderr, "Semantic Error (line %d): wrong type of expression or index\n", node->lineNumber);
            	SemanticErrors++;
			} 
            break;
        case AST_ESCR:
            checkWrite(node);
            break;
        case AST_ENTSE:
        case AST_ENTSNSE:
        case AST_ENQ:
            if(node->son[1]->datatype != DATATYPE_BOOL) {
		        fprintf(stderr, "Semantic Error (line %d): condition must be a boolean expression.\n", node->lineNumber);
				SemanticErrors++;
            }
            break;
        default: break;
    }


    for(int i=0; i<MAX_SONS; i++){
        checkCorrectUse(node->son[i]); 
    }
}

void isReturnCompatible(AST *node, int datatype) {
	if(node == 0) return;
	
	if(node->type == AST_RET) {
		if(!datatypeCompatible(node->son[0]->datatype, datatype)) {
			printf("Semantic Error (line %d): return statement with wrong datatype.\n", node->lineNumber);
			SemanticErrors++;
		}
	}

	for(int i = 0; i < MAX_SONS; i++) isReturnCompatible(node->son[i], datatype);
	
}

void checkReturn(AST* node) {
    if(node != 0 && node->type == AST_LDCF) isReturnCompatible(node, node->symbol->datatype);

	for(int i = 0; i < MAX_SONS; i++) {
		if(node->son[i] == 0) break;
		checkReturn(node->son[i]);
	}
}

void semanticVerification(AST* node) {
    Root = node;
    fprintf(stderr, "Set declarations... \n");
    setDeclarations(node);
    fprintf(stderr, "Check operands... \n");
    checkOperands(node);
    fprintf(stderr, "Check undeclared... \n");
    checkUndeclared();
    fprintf(stderr, "Check correct use... \n");
    checkCorrectUse(node); 
    fprintf(stderr, "Check return... \n");
    checkReturn(node);
}
