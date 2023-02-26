// tacs.h

#include <stdio.h>
#include <stdlib.h>
#include "tacs.h"

TAC * tacCreate(int type, HASH * res, HASH *op1, HASH *op2) {
    TAC* newtac = 0;
    newtac = (TAC*) calloc(1, sizeof(TAC));
    newtac->type = type;
    newtac->res = res;
    newtac->op1 = op1;
    newtac->op2 = op2;
    newtac->prev = 0;
    newtac->next = 0;
    return newtac;
}
void tacPrintSingle(TAC *tac){
    if(!tac) return;
    if(tac->type == TAC_SYMBOL) return;
    fprintf(stderr,"TAC(");
    switch(tac->type) {
        case TAC_SYMBOL: fprintf(stderr,"TAC_SYMBOL"); break;
        case TAC_ADD: fprintf(stderr,"TAC_ADD"); break;
        case TAC_SUB: fprintf(stderr,"TAC_SUB"); break;
        case TAC_COPY: fprintf(stderr,"TAC_COPY"); break;
        case TAC_JFALSE: fprintf(stderr,"TAC_JFALSE"); break;
        case TAC_JLABEL: fprintf(stderr,"TAC_JLABEL"); break;
        default: fprintf(stderr,"TAC_UNKNOW"); break;
    }
    if(tac->res) fprintf(stderr,",%s", tac->res->text); else fprintf(stderr,",0");
    if(tac->op1) fprintf(stderr,",%s", tac->op1->text); else fprintf(stderr,",0");
    if(tac->op2) fprintf(stderr,",%s", tac->op2->text); else fprintf(stderr,",0");
    fprintf(stderr,");\n");
}

void tacPrintBackwards(TAC *tac){
    if(!tac) return;
    tacPrintBackwards(tac->prev);
    tacPrintSingle(tac);
}

TAC *tacJoin(TAC* l1, TAC* l2) {
    TAC *point;
    if(!l1) return l2;
    if(!l2) return l1;

    for(point = l2; point->prev != 0; point = point->prev);

    point->prev = l1;
    return l2;
}

TAC *makeIfThen(TAC *code0, TAC *code1) {
    TAC *jumptac = 0;
    TAC *labeltac = 0;
    HASH *newlabel = 0;
    newlabel = makeLabel();

    jumptac = tacCreate(TAC_JFALSE,newlabel,code0?code0->res:0,0);
    jumptac->prev = code0;
    labeltac = tacCreate(TAC_JLABEL,newlabel,0,0);
    labeltac->prev = code1;
    return tacJoin(jumptac,labeltac);
}

// code generation

TAC *generateCode(AST * node) {
    TAC* result = 0;
    TAC *code[MAX_SONS];

    if(!node) return 0;

    // process children first
    for(int i=0; i<MAX_SONS; i++){
        code[i] = generateCode(node->son[i]); 
    }

    // check this node
    switch(node->type){
        case AST_SYMBOL: result = tacCreate(TAC_SYMBOL,node->symbol,0,0); break;
        case AST_ADD: result = tacJoin(tacJoin(code[0],code[1]), 
                        tacCreate(TAC_ADD,makeTemp(),code[0]?code[0]->res:0,code[1]?code[1]->res:0)); break;
        case AST_ASS: result = tacJoin(code[0], tacCreate(TAC_COPY,node->symbol,code[0]?code[0]->res:0,0)); break;
        case AST_ENTSE: result = makeIfThen(code[0],code[1]); break;
        default: result = tacJoin(code[0], tacJoin(code[1], tacJoin(code[2], code[3]))); break; // return the union of code for all subtrees
    }

    return result;
}
