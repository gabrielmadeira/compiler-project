// SEMANTICA VERIFICATION

#include "semantic.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int SemanticErrors = 0;


int convertToDatatype(int type) {
    if(type == AST_INTE)
        return DATAYPE_INTE;
    if(type == AST_CARA)
        return DATAYPE_CARA;
    if(type == AST_REAL)
        return DATAYPE_REAL;
    return -1;
}

void setDeclarations(AST *node) {
    
    if(!node) return;

    for(int i=0; i<MAX_SONS; i++){
        setDeclarations(node->son[i]); 
    }

    int type;
    char typeDesc[10];
    int isParam = 0;

    switch(node->type){
        case AST_GVAR:
            type = SYMBOL_VAR;
            strcpy(typeDesc, "variable");
            break;
        case AST_GARR:
            type = SYMBOL_VECTOR;
            strcpy(typeDesc, "vector");
            break;
        case AST_LDCF: 
            type = SYMBOL_FUNCTION;
            strcpy(typeDesc, "function");
            break;
        case AST_FPL:
            type = SYMBOL_VAR;
            isParam = 1;
        default: 
            return;
            break;
    }
    if(node->symbol){
        if(!isParam && node->symbol->type != SYMBOL_LIT_IDENTIFIER) {
            fprintf(stderr, "Semantic Error: %s %s redeclared.\n", 
            typeDesc,node->symbol->text);
            SemanticErrors++;
        }
        node->symbol->type = type;
        node->symbol->dec = node;
        if(node->son[0])
            node->symbol->datatype = convertToDatatype(node->son[0]->type);
    }
}
void checkUndeclared(void) {
    SemanticErrors += hashCheckUndeclared();
}

int getSemanticErrors(void) {
    return SemanticErrors;
}

int isNumber(AST *node) {
    // Valid as numbers (arithmetic)
    return (node->type == AST_ADD ||
            node->type == AST_SUB ||
            (node->type == AST_SYMBOL &&
                ((node->symbol->type == SYMBOL_LIT_INTE || node->symbol->type == SYMBOL_LIT_CARA)
                    || (node->symbol->type == SYMBOL_VAR
                            && (node->symbol->datatype == DATAYPE_INTE || node->symbol->datatype == DATAYPE_CARA)))) ||
            (node->type == AST_FCALL &&
                (node->symbol->datatype == DATAYPE_INTE || node->symbol->datatype == DATAYPE_CARA))
    
    );
}

int isFloat(AST *node) {
    return (node->type == AST_ADD ||
            node->type == AST_SUB ||
            (node->type == AST_SYMBOL &&
                (node->symbol->type == SYMBOL_LIT_REAL
                    || (node->symbol->type == SYMBOL_VAR
                            && node->symbol->datatype == DATAYPE_REAL))) ||
            (node->type == AST_FCALL &&
                node->symbol->datatype == DATAYPE_REAL)
    
    );
}

int isBool(AST *node) {
    return (node->type == AST_LES || node->type == AST_GRE || node->type == AST_AND
            || node->type == AST_OR || node->type == AST_NOT || node->type == AST_LE
            || node->type == AST_GE || node->type == AST_EQ || node->type == AST_DIF

    );
}

int checkExpressions(AST *node, const char *expType) {
    if(isBool(node)) {
        if(node->son[0] && node->son[1]) {
            if(checkExpressions(node->son[0], expType) && checkExpressions(node->son[1], expType)) return 1;
            if(!isNumber(node->son[0]) && !isFloat(node->son[0])) {
                fprintf(stderr, "Semantic Error: invalid left operand for %s.\n", expType);
                SemanticErrors++;    
                return 0;
            }
            if(!isNumber(node->son[1]) && !isFloat(node->son[1])) {
                fprintf(stderr, "Semantic Error: invalid right operand for %s.\n", expType);
                SemanticErrors++;    
                return 0;
            } 
            if((isNumber(node->son[0]) != isNumber(node->son[1])) &&
				(isFloat(node->son[0]) != isFloat(node->son[1]))) 
            {
                fprintf(stderr, "Semantic Error: left and right operands do not match.\n");
                SemanticErrors++;    
                return 0;
            }
            return 1;
        }
    }
    return 0;
}

void checkOperands(AST* node) {
    
    if(!node) return;

    char stringType[5];
    switch(node->type){
        case AST_ADD: strcpy(stringType,"ADD"); break;
        // if(!isNumber(node->son[0])) {
        //     fprintf(stderr, "Semantic Error: invalid left operand for ADD.\n");
        //     SemanticErrors++;
        // }
        // if(!isNumber(node->son[1])) {
        //     fprintf(stderr, "Semantic Error: invalid right operand for ADD.\n");
        //     SemanticErrors++;
        // }
        // break;
    }
    if(!checkExpressions(node, stringType)) {
        for(int i=0; i<MAX_SONS; i++){
            checkOperands(node->son[i]); 
        }
    }
}

void checkCorrectUse(AST* node) { //check nature - garantir que var,vetor,funcao seja usadada como var,vetor,funcao
    if(!node) return;

    switch(node->type){
        case AST_VARCALL: 
            if((node->son[0] || (node->symbol->type != SYMBOL_VAR)) && node->symbol->type != SYMBOL_LIT_IDENTIFIER) {
                fprintf(stderr, "Semantic Error: incorrect use, %s is not a variable.\n", node->symbol->text);
                SemanticErrors++;
            }
            break;
        case AST_FCALL:
            if(node->symbol->type != SYMBOL_FUNCTION && node->symbol->type != SYMBOL_LIT_IDENTIFIER) {
                fprintf(stderr, "Semantic Error: incorrect use, %s is not a function.\n", node->symbol->text);
                SemanticErrors++;
            }
            break;
        case AST_ACALL: 
            if((!node->son[0] || node->symbol->type != SYMBOL_VECTOR) && node->symbol->type != SYMBOL_LIT_IDENTIFIER) {
                fprintf(stderr, "Semantic Error: incorrect use, this element is not a vector.\n");
                SemanticErrors++;
            }
            break;
        default: break;
    }
    for(int i=0; i<MAX_SONS; i++){
        checkCorrectUse(node->son[i]); 
    }
}

void checkReturn(AST* node, int currentFuncDatatype) {
    if(!node) return;

    if(node->type == AST_LDCF) {
        currentFuncDatatype = node->symbol->datatype;
    }
    if(node->type == AST_RET) {
        if(!node->son[0] || (node->son[0]->symbol && ((node->son[0]->symbol->type == -1 && (node->son[0]->symbol->datatype != currentFuncDatatype)) ||
        ((currentFuncDatatype == DATAYPE_INTE || currentFuncDatatype == DATAYPE_CARA) && !isNumber(node->son[0])) || 
        (currentFuncDatatype == DATAYPE_REAL && (node->son[0]->symbol->type != SYMBOL_LIT_REAL && node->son[0]->symbol->datatype != DATAYPE_REAL)))) ||
        isBool(node->son[0]))
        {
            fprintf(stderr, "Semantic Error: invalid type in function return.\n");
            SemanticErrors++;
        }
    }
    
    for(int i=0; i<MAX_SONS; i++){
        checkReturn(node->son[i], currentFuncDatatype); 
    }
}

AST* get_expr_leaf(AST* node){ while (node->son[0] != NULL) node = node->son[0]; return node; }

void checkFuncArguments(AST *node) {
    if(!node) return;

    if(node->type == AST_FCALL && node->symbol->type == SYMBOL_FUNCTION) {
        AST *darg = node->symbol->dec->son[1];
        AST *carg = node->son[0];

        while(darg && carg) {
            AST* cleaf = get_expr_leaf(carg);
            if(((darg->symbol->datatype == DATAYPE_CARA || darg->symbol->datatype == DATAYPE_INTE) && !isNumber(cleaf)) ||
            (darg->symbol->datatype == DATAYPE_REAL && (cleaf->symbol->type != SYMBOL_LIT_REAL && cleaf->symbol->datatype != DATAYPE_REAL))) 
            {
                fprintf(stderr, "Semantic Error: invalid datatype in function argument.\n");
                SemanticErrors++;
            }
            darg = darg->son[1];
            carg = carg->son[1];
        }
        if(!darg && carg) {
            fprintf(stderr, "Semantic Error: Too many arguments in function call.\n");
            SemanticErrors++;
        } else if(darg && !carg) {
            fprintf(stderr, "Semantic Error: Few arguments in function call.\n");
            SemanticErrors++;
        }
    }
    
    for(int i=0; i<MAX_SONS; i++){
        checkFuncArguments(node->son[i]); 
    }
}

void checkVector(AST* node, int vsize, int current, int dtype) {
    if(!node) return;

    if(node->type == AST_GARR) {
        vsize = atoi(node->son[1]->symbol->text);
        dtype = convertToDatatype(node->son[0]->type);
        current = 0;
    }

    if(node->type == AST_LEXP) {
        current++;
        if((dtype == DATAYPE_REAL && node->son[0]->symbol->type != SYMBOL_LIT_REAL) ||
            (current > vsize) || isBool(node)) // || node->son[0]->symbol->type == SYMBOL_LIT_STRING
        {
            fprintf(stderr, "Semantic Error: invalid vector values.\n");
            SemanticErrors++;
        }
    }
    
    for(int i=0; i<MAX_SONS; i++){
        checkVector(node->son[i], vsize, current, dtype);
    }
}

void checkVectorIndex(AST* node) {
    if(!node) return;

    if(node->type == AST_GARR && node->symbol->dec != NULL) {
        int decsize = atoi(node->symbol->dec->son[1]->symbol->text);
        int indsize, isInteger = 0;
        if(node->son[0]->symbol->type == SYMBOL_LIT_INTE) { isInteger = 1; indsize = atoi(node->son[0]->symbol->text); }
        if(!isNumber(node->son[0])) {
            fprintf(stderr, "Semantic Error: invalid datatype in vector index.\n");
            SemanticErrors++;
        } else if(isInteger && (indsize >= decsize)) {
            fprintf(stderr, "Semantic Error: index value is greater than the declared range.\n");
            SemanticErrors++;
        }
    }
    
    for(int i=0; i<MAX_SONS; i++){
        checkVectorIndex(node->son[i]); 
    }
}

void semanticVerification(AST* node) {
    setDeclarations(node);
    checkUndeclared();
    checkOperands(node);
    
    checkVectorIndex(node);
	checkVector(node,0,0,0);

    checkCorrectUse(node); // natureza
    checkReturn(node, -1);

    checkFuncArguments(node);
}
