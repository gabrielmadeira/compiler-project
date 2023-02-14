// SEMANTICA VERIFICATION

#include "semantic.h"
#include <stdio.h>

int SemanticErrors = 0;

void setDeclarations(AST *node) {
    int i;
    if(!node) return;
    for(i=0; i<MAX_SONS; i++){
        setDeclarations(node->son[i]); // process childrean first
    }

    // check this node

    switch(node->type){
        case AST_GVAR:
        case AST_GARR:
        case AST_LDCF: // test and set
            if(node->symbol){
                if(node->symbol->type != SYMBOL_LIT_IDENTIFIER) {
                    fprintf(stderr, "Semantic Error: varible %s redeclared.\n", 
                    node->symbol->text);
                    ++SemanticErrors;
                }
                node->symbol->type = SYMBOL_VAR;
                if(node->son[0]) {
                    if(node->son[0]->type == AST_INTE)
                        node->symbol->datatype = DATAYPE_INTE;
                    if(node->son[0]->type == AST_CARA)
                        node->symbol->datatype = DATAYPE_CARA;
                    if(node->son[0]->type == AST_REAL)
                        node->symbol->datatype = DATAYPE_REAL;
                }
            }
            break;
        default: break;
    }
}
void checkUndeclared(void) {
    SemanticErrors += hashCheckUndeclared();
}

int getSemanticErrors(void) {
    return SemanticErrors;
}

int isNumber(AST *son) {
    // Valid as numbers (arithmetic)
    if((son->type == AST_ADD ||
        son->type == AST_SUB ||
        (son->type == AST_SYMBOL &&
            ((son->symbol->type == SYMBOL_LIT_INTE) 
            || (son->symbol->type == SYMBOL_VAR
                    && son->symbol->datatype == DATAYPE_INTE))) ||
        (son->type == AST_FCALL &&
            son->symbol->datatype == DATAYPE_INTE)
    
    ))
        return 1;
    else
        return 0;
}

void checkOperands(AST* node) {
    int i;
    if(!node) return;
    for(i=0; i<MAX_SONS; i++){
        checkOperands(node->son[i]); 
    }

    switch(node->type){
        case AST_ADD: // IF OPERANDS ARE NOT VALID
            if(!isNumber(node->son[0])) {
                fprintf(stderr, "Semantic Error: invalid left operand for ADD.\n");
                ++SemanticErrors;
            }
            if(!isNumber(node->son[1])) {
                fprintf(stderr, "Semantic Error: invalid right operand for ADD.\n");
                ++SemanticErrors;
            }
            break;
    }
}

void semanticVerification(AST* node) {
    setDeclarations(node);
    checkUndeclared();
    checkOperands(node);
}

/*
            (!(node->son[0]->type == AST_ADD ||
                node->son[0]->type == AST_SUB ||
                (node->son[0]->type == AST_SYMBOL &&
                    node->son[0]->symbol->type == SYMBOL_LIT_IDENTIFIER) ||
                (node->son[0]->type == AST_FCALL &&
                    node->son[0]->symbol->datatype == DATAYPE_INTE)
            
            ))
*/