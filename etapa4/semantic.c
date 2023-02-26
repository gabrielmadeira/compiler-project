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
            node->symbol->type = SYMBOL_FUNCTION;
            if(node->son[0])
                node->symbol->datatype = convertToDatatype(node->son[0]->type);
            break;
        case AST_FPL:
            if(node->symbol->type != SYMBOL_LIT_IDENTIFIER) {
                fprintf(stderr, "Semantic Error: function var %s redeclared.\n", 
                node->symbol->text);
                SemanticErrors++;
            }
            node->symbol->type = SYMBOL_VAR;
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

int arithmetic(int type) {
    return type == AST_ADD || type == AST_SUB || type == AST_MUL || type == AST_DIV;
}

int calcDatatype(int type1, int type2) {
    if(type1 > type2) return type1;
    return type2;
}

int relational(int type) {
    return type == AST_LES || type == AST_GRE || type == AST_EQ || type == AST_LE || type == AST_GE || type == AST_DIF;
}

int logical(int type) {
    return type == AST_AND || type == AST_OR || type == AST_NOT;
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
    } else if(arithmetic(node->type)) {
        AST* son0 = node->son[0];
        AST* son1 = node->son[1];
        
        if(!datatypeCompatible(son0->datatype, son1->datatype) || son0->datatype == DATATYPE_BOOL || son1->datatype == DATATYPE_BOOL) {
            fprintf(stderr, "Semantic Error: arithmetic operation with incompatible data types.\n");
            SemanticErrors++;
        }
    
        node->datatype = calcDatatype(son0->datatype, son1->datatype);
    
    } else if(relational(node->type)) {

        AST* son0 = node->son[0];
        AST* son1 = node->son[1];
        
        if(!datatypeCompatible(son0->datatype, son1->datatype) || son0->datatype == DATATYPE_BOOL || son1->datatype == DATATYPE_BOOL) {
            fprintf(stderr, "Semantic Error: relational operation with incompatible data types.\n");
            SemanticErrors++;
        }

        node->datatype = DATATYPE_BOOL;

    } else if(logical(node->type)) {

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
	if(node->symbol != NULL && !strcmp(node->symbol->text, name)) 
        return node;

	for(int i = 0; i < MAX_SONS; i++) {
        if(node->son[i] == 0) continue;
		if(node->son[i] == NULL) return NULL;
		AST *finding = findDeclaration(name, node->son[i]);
		if(finding != NULL) return finding;
	}

	return NULL;
}

int calcNumberOfArguments(AST *node) {
	if(node == 0) 
        return 0;

    if(node->son[1] != 0)
        return calcNumberOfArguments(node->son[1]) + 1;

	return 0;
}

int compareNumberOfArguments(AST *node, AST *declaration) {
	int numberOfCalledArguments = calcNumberOfArguments(node->son[0]);
	int numberOfDeclaredArguments = calcNumberOfArguments(declaration->son[1]);	

	if(numberOfCalledArguments != numberOfDeclaredArguments) {
	    fprintf(stderr, "Semantic Error: incompatible number of arguments.\n");
		SemanticErrors++;
		return 0;
	}

	return 1;
}

void compareCalledArguments(AST *node, AST *declaration) {
	if(node->son[0] != 0) {
		if(!datatypeCompatible(node->son[0]->datatype, declaration->symbol->datatype)) {
			fprintf(stderr, "Semantic Error: incompatible argument types.\n");
			SemanticErrors++;
		}
		
        if(node->son[0]->type == AST_SYMBOL) {
            if(node->son[0]->symbol->type == SYMBOL_FUNCTION) {
				fprintf(stderr, "Semantic Error: cannot pass function as argument.\n");
				SemanticErrors++;
            } else if(node->son[0]->symbol->type == SYMBOL_VECTOR) {
		        fprintf(stderr, "Semantic Error: cannot pass vector as argument.\n");
			    SemanticErrors++;
            }
        }

		if(node->son[1] != 0) compareCalledArguments(node->son[1], declaration->son[1]);
	}
}

void checkWrite(AST *node) {
    if (node == 0) return;
    checkWrite(node->son[1]);
}

void checkCorrectUse(AST* node) { 
    if(!node) return;

    AST* declaration;

    switch(node->type){
        case AST_ASS: 
            if(node->symbol->type != SYMBOL_VAR) {
                fprintf(stderr, "Semantic Error: attribution must be to a scalar variable.\n");
		        SemanticErrors++;
            }

			if(!datatypeCompatible(node->symbol->datatype, node->son[0]->datatype)) {
				fprintf(stderr, "Semantic Error: attribution with incompatible data type.\n");
				SemanticErrors++;
			}
            break;
        case AST_ARAS:
            if(node->symbol->type != SYMBOL_VECTOR) {
           	    fprintf(stderr, "Semantic Error: indexing only allowed for vectors.\n");
	           	SemanticErrors++;
            }

            if(!datatypeCompatible(node->symbol->datatype, node->son[1]->datatype)) {
		        fprintf(stderr, "Semantic Error: attribution with incompatible data type.\n");
                SemanticErrors++;
			}

	        if(!integerOrChar(node->son[0]->datatype)) {
		        fprintf(stderr, "Semantic Error: index must be an integer.\n");
                SemanticErrors++;
            }
            break;
        case AST_FCALL:
            declaration = findDeclaration(node->symbol->text, Root);
    	
            if(declaration == 0 || declaration->type != AST_LDCF) {
                fprintf(stderr, "Semantic Error: only functions can be called, %s is not a function.\n", node->symbol->text);
                SemanticErrors++;
            } else if(compareNumberOfArguments(node, declaration)) {
                if(declaration->son[1]) 
                    compareCalledArguments(node->son[0], declaration->son[1]);					
            }
            break;
        case AST_ACALL: 
            declaration = findDeclaration(node->symbol->text, Root);
            if(declaration == 0 || declaration->type != AST_GARR) {
                fprintf(stderr, "Semantic Error: %s is not a vector.\n", node->symbol->text);
            }

            if(node->son[0]->datatype != DATATYPE_CARA && node->son[0]->datatype != DATATYPE_INTE) {
            	fprintf(stderr, "Semantic Error: wrong type of expression or index\n");
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
		        fprintf(stderr, "Semantic Error: condition must be a boolean expression.\n");
				SemanticErrors++;
            }
            break;
        default: break;
    }


    for(int i=0; i<MAX_SONS; i++){
        checkCorrectUse(node->son[i]); 
    }
}

void checkCompatibleReturn(AST *node, int datatype) {
	if(node == 0) return;
	
	if(node->type == AST_RET) {
		if(!datatypeCompatible(node->son[0]->datatype, datatype)) {
			printf("Semantic Error: return statement with wrong datatype.\n");
			SemanticErrors++;
		}
	}

	for(int i = 0; i < MAX_SONS; i++) checkCompatibleReturn(node->son[i], datatype);
	
}

void checkReturn(AST* node) {
    if(node != 0 && node->type == AST_LDCF) checkCompatibleReturn(node, node->symbol->datatype);

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
