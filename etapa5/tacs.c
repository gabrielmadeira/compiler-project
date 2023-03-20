/*
	Gabriel Madeira (00322863)
*/

#include <stdio.h>
#include <stdlib.h>
#include "tacs.h"

TAC * tacCreate(int type, HASH *res, HASH *op1, HASH *op2) {
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
        case TAC_MUL: fprintf(stderr,"TAC_MUL"); break;
        case TAC_DIV: fprintf(stderr,"TAC_DIV"); break;
        case TAC_LES: fprintf(stderr,"TAC_LES"); break;
        case TAC_GRE: fprintf(stderr,"TAC_GRE"); break;
        case TAC_AND: fprintf(stderr,"TAC_AND"); break;
        case TAC_OR: fprintf(stderr,"TAC_OR"); break;
        case TAC_NOT: fprintf(stderr,"TAC_NOT"); break;
        case TAC_LE: fprintf(stderr,"TAC_LE"); break;
        case TAC_GE: fprintf(stderr,"TAC_GE"); break;
        case TAC_EQ: fprintf(stderr,"TAC_EQ"); break;
        case TAC_DIF: fprintf(stderr,"TAC_DIF"); break;
        case TAC_MOVE: fprintf(stderr,"TAC_MOVE"); break;
        case TAC_VAR: fprintf(stderr,"TAC_VAR"); break;
        case TAC_MOVEVEC: fprintf(stderr,"TAC_MOVEVEC"); break;
        case TAC_VEC: fprintf(stderr,"TAC_VEC"); break;
        case TAC_LEXP: fprintf(stderr,"TAC_LEXP"); break;
        case TAC_ACALL: fprintf(stderr,"TAC_ACALL"); break;
        case TAC_LABEL: fprintf(stderr,"TAC_LABEL"); break;
        case TAC_BEGINFUN: fprintf(stderr,"TAC_BEGINFUN"); break;
        case TAC_ENDFUN: fprintf(stderr,"TAC_ENDFUN"); break;
        case TAC_IFZ: fprintf(stderr,"TAC_IFZ"); break;
        case TAC_JUMP: fprintf(stderr,"TAC_JUMP"); break;
        case TAC_CALL: fprintf(stderr,"TAC_CALL"); break;
        case TAC_ARG: fprintf(stderr,"TAC_ARG"); break;
        case TAC_RET: fprintf(stderr,"TAC_RET"); break;
        case TAC_PRINT: fprintf(stderr,"TAC_PRINT"); break;
        case TAC_PRINTL: fprintf(stderr,"TAC_PRINTL"); break;
        case TAC_READ: fprintf(stderr,"TAC_READ"); break;
        case TAC_PARAM: fprintf(stderr,"TAC_PARAM"); break;
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

TAC *makeBinaryOp(int opType, TAC* code[]) {
    return tacJoin(tacJoin(code[0],code[1]), tacCreate(opType,makeTemp(),code[0]?code[0]->res:0,code[1]?code[1]->res:0));
}

TAC *makeIfThen(TAC *expr, TAC *cmdIf, TAC *cmdElse) { //TODO
    HASH *ifLabel = makeLabel();

    TAC *ifTac = tacCreate(TAC_IFZ,ifLabel,expr?expr->res:0,0);
    TAC *labelTac = tacCreate(TAC_LABEL,ifLabel,0,0);

    if(cmdElse) {
        HASH *elseLabel = makeLabel();
        TAC *elseLabelTac = tacCreate(TAC_LABEL,elseLabel,0,0);
        TAC *elseJumpTac = tacCreate(TAC_JUMP, elseLabel, 0, 0);
        return tacJoin(tacJoin(tacJoin(tacJoin(tacJoin(tacJoin(expr, ifTac), cmdIf), elseJumpTac), labelTac), cmdElse), elseLabelTac);
    }else{
        return tacJoin(tacJoin(tacJoin(expr, ifTac), cmdIf),labelTac);
    }
}

TAC *makeWhile(TAC* expr, TAC* cmd, HASH *whileLabel) { //TODO
    HASH *jumpLabel = makeLabel();

	TAC *whileTac = tacCreate(TAC_IFZ, jumpLabel, expr?expr->res:0, 0);
	TAC *whileLabelTac = tacCreate(TAC_LABEL, whileLabel, 0, 0);
	TAC *jumpTac = tacCreate(TAC_JUMP, whileLabel, 0, 0);
	TAC *jumpLabelTac= tacCreate(TAC_LABEL, jumpLabel, 0, 0);

	return tacJoin(tacJoin(tacJoin(tacJoin(tacJoin(whileLabelTac, expr), whileTac), cmd), jumpTac), jumpLabelTac);
}

TAC *makeFunction(TAC *fTac, TAC *params, TAC *block) {
    return tacJoin(tacJoin(tacJoin(tacCreate(TAC_BEGINFUN, fTac->res, 0, 0), params), block), tacCreate(TAC_ENDFUN, fTac->res, 0, 0));
}

// code generation

TAC *generateCode(AST * node, HASH *currentLoopLabel) {
    if(!node) return 0;

    TAC* result = 0;
    TAC *code[MAX_SONS];
    if(node->type == AST_ENQ) {
		currentLoopLabel = makeLabel();
	}

    // process children first
    for(int i=0; i<MAX_SONS; i++){
        code[i] = generateCode(node->son[i], currentLoopLabel); 
    }

    // check this node
    switch(node->type){
        case AST_SYMBOL: result = tacCreate(TAC_SYMBOL,node->symbol,0,0); break;
        
        case AST_ADD: result = makeBinaryOp(TAC_ADD, code); break;
        case AST_SUB: result = makeBinaryOp(TAC_SUB, code); break;
        case AST_MUL: result = makeBinaryOp(TAC_MUL, code); break;
        case AST_DIV: result = makeBinaryOp(TAC_DIV, code); break;
        case AST_LES: result = makeBinaryOp(TAC_LES, code); break;
        case AST_GRE: result = makeBinaryOp(TAC_GRE, code); break;
        case AST_AND: result = makeBinaryOp(TAC_AND, code); break;
        case AST_OR: result = makeBinaryOp(TAC_OR, code); break;
        case AST_NOT: result = tacJoin(code[0], tacCreate(TAC_NOT,makeTemp(),code[0]?code[0]->res:0,0)); break;
        case AST_LE: result = makeBinaryOp(TAC_LE, code); break;
        case AST_GE: result = makeBinaryOp(TAC_GE, code); break;
        case AST_EQ: result = makeBinaryOp(TAC_EQ, code); break;
        case AST_DIF: result = makeBinaryOp(TAC_DIF, code); break; 

        case AST_ASS: result = tacJoin(code[0], tacCreate(TAC_MOVE,node->symbol,code[0]?code[0]->res:0,0)); break;
        case AST_ARAS: result = tacJoin(code[0], tacJoin(code[1], tacCreate(TAC_MOVEVEC, node->symbol, code[0]?code[0]->res:0, code[1]?code[1]->res:0))); break; 
        case AST_ACALL: result = tacJoin(code[0], tacCreate(TAC_ACALL, makeTemp(), node->symbol, code[0]?code[0]->res:0)); break;
        case AST_RET: result = tacJoin(code[0], tacCreate(TAC_RET, code[0]?code[0]->res:0, 0, 0)); break;
        case AST_ESCR: result = tacJoin(code[0], tacCreate(TAC_PRINT, 0, 0, 0)); break; // TODO string/expr
        case AST_LEEXP: result = tacJoin(code[1], tacJoin(code[0], tacCreate(TAC_PRINTL, code[0]->res, 0, 0))); break;
        case AST_LESTR: result = tacJoin(code[0], tacCreate(TAC_PRINTL, node->symbol, 0, 0)); break;
        case AST_ENTRADA: result = tacCreate(TAC_READ, makeTemp(), 0, 0); break;

        case AST_GVAR: result = tacJoin(code[1], tacCreate(TAC_VAR,node->symbol,code[1]?code[1]->res:0,0)); break;
        case AST_GARR: result = tacJoin(tacCreate(TAC_VEC, node->symbol, code[1]?code[1]->res:0,0), tacJoin(code[1],code[2])); break;
        case AST_LEXP: result = tacJoin(tacCreate(TAC_LEXP, code[0]->res, 0, 0), code[1]); break; // expressão inicialização vetor
        case AST_LDCF: result = tacJoin(makeFunction(tacCreate(TAC_SYMBOL, node->symbol, 0, 0), code[1], code[2]), code[3]); break;
        case AST_FPL: result = tacJoin(tacCreate(TAC_PARAM, node->symbol, 0, 0), code[1]); break; 
        case AST_FCALL: result = tacJoin(code[0], tacCreate(TAC_CALL, makeTemp(), node->symbol, 0)); break;
        case AST_FCPL: result = tacJoin(tacJoin(code[0], tacCreate(TAC_ARG, code[0]?code[0]->res:0, 0, 0)),code[1]); break; 
        
        case AST_ENTSE: result = makeIfThen(code[1], code[0], 0); break;
        case AST_ENTSNSE: result = makeIfThen(code[1], code[0], code[2]); break;
        case AST_ENQ: result = makeWhile(code[1], code[0], currentLoopLabel); break;

        default: result = tacJoin(code[0], tacJoin(code[1], tacJoin(code[2], code[3]))); break; // return the union of code for all subtrees
    }

    return result;
}
