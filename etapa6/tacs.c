/*
	Gabriel Madeira (00322863)
*/

#include <stdio.h>
#include <stdlib.h>
#include "tacs.h"
#include "semantic.h"

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
        case AST_NOT: result = makeBinaryOp(TAC_NOT, code); break;
        case AST_LE: result = makeBinaryOp(TAC_LE, code); break;
        case AST_GE: result = makeBinaryOp(TAC_GE, code); break;
        case AST_EQ: result = makeBinaryOp(TAC_EQ, code); break;
        case AST_DIF: result = tacJoin(code[0], tacCreate(TAC_DIF,makeTemp(),code[0]?code[0]->res:0,0)); break;

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
        case AST_LDCF: result = makeFunction(tacCreate(TAC_SYMBOL, node->symbol, 0, 0), code[1], code[2]); break;
        case AST_FPL: result = tacJoin(code[1], tacCreate(TAC_PARAM, node->symbol, 0, 0)); break; 
        case AST_FCALL: result = tacJoin(code[0], tacCreate(TAC_CALL, makeTemp(), node->symbol, 0)); break;
        case AST_FCPL: result = tacJoin(tacJoin(code[0], tacCreate(TAC_ARG, code[0]?code[0]->res:0, 0, 0)),code[1]); break; 
        
        case AST_ENTSE: result = makeIfThen(code[1], code[0], 0); break;
        case AST_ENTSNSE: result = makeIfThen(code[1], code[0], code[2]); break;
        case AST_ENQ: result = makeWhile(code[1], code[0], currentLoopLabel); break;

        default: result = tacJoin(code[0], tacJoin(code[1], tacJoin(code[2], code[3]))); break; // return the union of code for all subtrees
    }

    return result;
}

TAC* tacReverse(TAC *tac) {
    TAC* t = tac;
    for(t = tac; t->prev; t = t->prev)
        t->prev->next = t;
    return t;
}

void generateAsm(TAC *first, AST *mainNode) {
    TAC *tac;
    FILE *fout;
    fout = fopen("out.s","w");

    // Init
    fprintf(fout,"## FIXED INIT\n"
                ".scanIntStr: .string	\"%%d\"\n"
                ".printIntStr: .string	\"%%d\\n\"\n"
                ".printStringStr: .string \"%%s\\n\"\n");


    // Each tac

    for(tac = first; tac; tac = tac->next) {
        switch(tac->type) {
            case AST_SYMBOL: break;
            case TAC_BEGINFUN: 
                fprintf(fout,"## TAC_BEGINFUN\n"
                                "\t.globl %s\n"
                            "%s:\n"
                                "\tpushq %%rbp\n"
                                "\tmovq %%rsp, %%rbp\n", tac->res->text, tac->res->text);
                break;
            case TAC_ENDFUN: 
                fprintf(fout,"## TAC_ENDFUN\n" 
                                "\tpopq %%rbp\n"
                                "\tret\n");
                break;

            case TAC_PRINTL: // TODO: fazer para printstring
                fprintf(fout,"## TAC_PRINTINT\n"
                                "\tmovl _%s(%%rip), %%esi\n"
                                "\tleaq .printIntStr(%%rip), %%rax\n"
                                "\tmovq %%rax, %%rdi\n"
                                "\tcall printf@PLT\n",tac->res->text);
                break;


            case TAC_ADD: fprintf(fout,"## TAC_ADD\n" 
                                            "\tmovl _%s(%%rip), %%edx\n"
                                            "\tmovl _%s(%%rip), %%eax\n"
                                            "\taddl %%edx, %%eax\n"
                                            "\tmovl %%eax, _%s(%%rip)\n"
                                    , tac->op1->text, tac->op2->text, tac->res->text);
                
                break;
            case TAC_SUB: fprintf(fout,"## TAC_SUB\n"
                                            "\tmovl _%s(%%rip), %%edx\n"
                                            "\tmovl _%s(%%rip), %%eax\n"
                                            "\tsubl %%edx, %%eax\n"
                                            "\tmovl %%eax, _%s(%%rip)\n"
                                , tac->op1->text, tac->op2->text, tac->res->text); 
                
                break;
            case TAC_MUL: fprintf(fout,"## TAC_MUL\n"
                                            "\tmovl _%s(%%rip), %%edx\n"
                                            "\tmovl _%s(%%rip), %%eax\n"
                                            "\timull %%edx, %%eax\n"
                                            "\tmovl %%eax, _%s(%%rip)\n"
                                , tac->op1->text, tac->op2->text, tac->res->text); 
                
                break;
            case TAC_DIV: fprintf(fout,"## TAC_DIV\n"
                                            "\tmovl _%s(%%rip), %%eax\n"
                                            "\tmovl _%s(%%rip), %%ecx\n"
                                            "\tcltd\n"
                                            "\tidivl %%ecx\n"
                                            "\tmovl %%eax, _%s(%%rip)\n"
                                , tac->op1->text, tac->op2->text, tac->res->text); 
                
                break;
            case TAC_LES: fprintf(fout,"## TAC_LES\n"
                                            "\tmovl _%s(%%rip), %%edx\n"
                                            "\tmovl _%s(%%rip), %%eax\n"
                                            "\tcmpl	%%eax, %%edx\n"
                                            "\tsetl %%al\n"
                                            "\tmovzbl %%al, %%eax\n"
                                            "\tmovl %%eax, _%s(%%rip)\n"
                                , tac->op1->text, tac->op2->text, tac->res->text); 
                
                break;
            case TAC_GRE: fprintf(fout,"## TAC_GRE\n"
                                            "\tmovl _%s(%%rip), %%edx\n"
                                            "\tmovl _%s(%%rip), %%eax\n"
                                            "\tcmpl	%%eax, %%edx\n"
                                            "\tsetg %%al\n"
                                            "\tmovzbl %%al, %%eax\n"
                                            "\tmovl %%eax, _%s(%%rip)\n"
                                , tac->op1->text, tac->op2->text, tac->res->text); 
                
                break;
            case TAC_AND: fprintf(fout,"## TAC_AND\n" 
                                            "\tmovl _%s(%%rip), %%edx\n"
                                            "\tmovl _%s(%%rip), %%eax\n"
                                            "\tandl %%edx, %%eax\n"
                                            "\tmovl %%eax, _%s(%%rip)\n"
                                    , tac->op1->text, tac->op2->text, tac->res->text);
                
                break;
            case TAC_OR: fprintf(fout,"## TAC_OR\n" 
                                            "\tmovl _%s(%%rip), %%edx\n"
                                            "\tmovl _%s(%%rip), %%eax\n"
                                            "\torl %%edx, %%eax\n"
                                            "\tmovl %%eax, _%s(%%rip)\n"
                                    , tac->op1->text, tac->op2->text, tac->res->text);
                
                break;
            case TAC_NOT: fprintf(fout,"## TAC_NOT\n"
                                            "\tmovl _%s(%%rip), %%eax\n"
                                            "\ttestl %%eax, %%eax\n"
                                            "\tsete %%al\n"
                                            "\tmovzbl %%al, %%eax\n"
                                            "\tmovl %%eax, _%s(%%rip)\n"
                                        , tac->op1->text, tac->res->text); 
                break;
            case TAC_LE: fprintf(fout,"## TAC_LE\n"
                                            "\tmovl _%s(%%rip), %%edx\n"
                                            "\tmovl _%s(%%rip), %%eax\n"
                                            "\tcmpl	%%eax, %%edx\n"
                                            "\tsetle %%al\n"
                                            "\tmovzbl %%al, %%eax\n"
                                            "\tmovl %%eax, _%s(%%rip)\n"
                                , tac->op1->text, tac->op2->text, tac->res->text); 
                
                break;
            case TAC_GE: fprintf(fout,"## TAC_GE\n"
                                            "\tmovl _%s(%%rip), %%edx\n"
                                            "\tmovl _%s(%%rip), %%eax\n"
                                            "\tcmpl	%%eax, %%edx\n"
                                            "\tsetge %%al\n"
                                            "\tmovzbl %%al, %%eax\n"
                                            "\tmovl %%eax, _%s(%%rip)\n"
                                , tac->op1->text, tac->op2->text, tac->res->text); 
                
                break;
            case TAC_EQ: fprintf(fout,"## TAC_EQ\n"
                                            "\tmovl _%s(%%rip), %%edx\n"
                                            "\tmovl _%s(%%rip), %%eax\n"
                                            "\tcmpl	%%eax, %%edx\n"
                                            "\tsete %%al\n"
                                            "\tmovzbl %%al, %%eax\n"
                                            "\tmovl %%eax, _%s(%%rip)\n"
                                , tac->op1->text, tac->op2->text, tac->res->text); 
                
                break;
            case TAC_DIF: fprintf(fout,"## TAC_DIF\n"
                                            "\tmovl _%s(%%rip), %%edx\n"
                                            "\tmovl _%s(%%rip), %%eax\n"
                                            "\tcmpl	%%eax, %%edx\n"
                                            "\tsetne %%al\n"
                                            "\tmovzbl %%al, %%eax\n"
                                            "\tmovl %%eax, _%s(%%rip)\n"
                                , tac->op1->text, tac->op2->text, tac->res->text); 
                
                break;
            case TAC_MOVE: fprintf(fout,"## TAC_MOVE\n" 
                                            "\tmovl _%s(%%rip), %%eax\n"
                                            "\tmovl %%eax, _%s(%%rip)\n"
                                        , tac->op1->text, tac->res->text); 
                break;
            case TAC_VAR: break; //fprintf(fout,"TAC_VAR");
            case TAC_MOVEVEC: fprintf(fout,"## TAC_MOVEVEC\n" 
                                            "\tmovl _%s(%%rip), %%eax\n"
                                            "\tmovl %%eax, %d+_%s(%%rip)\n"
                                        , tac->op2->text, atoi(tac->op1->text)*4, tac->res->text); 
            case TAC_VEC: break; // fprintf(fout,"TAC_VEC"); // Iterar inicialização do vetor printando
            case TAC_LEXP: break; // fprintf(fout,"TAC_LEXP");
            case TAC_ACALL: fprintf(fout,"## TAC_ACALL\n" 
                                            "\tmovl %d+_%s(%%rip), %%eax\n"
                                            "\tmovl %%eax, _%s(%%rip)\n"
                                        , atoi(tac->op2->text)*4, tac->op1->text, tac->res->text); 
                break;
            case TAC_LABEL: fprintf(fout,"## TAC_LABEL\n"
                                            ".%s:\n"
                                        , tac->res->text); 
                break;
            case TAC_IFZ: fprintf(fout,"## TAC_IFZ\n"
                                            "\tmovl _%s(%%rip), %%eax\n"
                                            "\ttestl %%eax, %%eax\n"
                                            "\tje .%s\n"
                                        , tac->op1->text, tac->res->text); 
                break;
            case TAC_JUMP: fprintf(fout,"## TAC_JUMP\n"
                                            "jmp .%s\n"
                                        , tac->res->text); 
                break;
            case TAC_CALL: fprintf(fout,"## TAC_CALL\n");  // move para argumentos globais da função 
                            // iterar argumentos
                AST* funcParam = findDeclaration(tac->op1->text, mainNode);
                funcParam = funcParam->son[1];
                TAC *aux = tac->prev; 
                while(funcParam) {
                    fprintf(fout, "\tmovl _%s(%%rip), %%eax\n"
                                    "\tmovl %%eax, _%s(%%rip)\n"
                                    , aux->res->text, funcParam->symbol->text);
                    funcParam = funcParam->son[1];
                    aux = aux->prev;
                }

                            fprintf(fout, "\tcall %s\n" // chamar func, move do registrador definido X para variável temporaria
                                            "\tmovl	%%eax, _%s(%%rip)\n"
                                    , tac->op1->text, tac->res->text); 
                break;
            case TAC_ARG: break; // fprintf(fout,"## TAC_ARG\n")
            case TAC_RET: fprintf(fout,"## TAC_RET\n" // colocar em um registrador definido X
                                            "\tmovl _%s(%%rip), %%eax\n"
                                    , tac->res->text); 
                break;
            case TAC_PRINT: break; //fprintf(fout,"TAC_PRINT");
            case TAC_READ: fprintf(fout,"## TAC_READ\n" //scanf 1 inteiro
                                            "\tleaq _%s(%%rip), %%rax\n"
                                            "\tmovq %%rax, %%rsi\n"
                                            "\tleaq .scanIntStr(%%rip), %%rax\n"
                                            "\tmovq %%rax, %%rdi\n"
                                            "\tmovl $0, %%eax\n"
                                            "\tcall __isoc99_scanf@PLT\n"
                                        , tac->res->text); 
                                        
                break;
            case TAC_PARAM: break; //fprintf(fout,"TAC_PARAM");

            default: fprintf(fout,"## TAC UNKNOW ERROR %d\n",tac->type); break;
        }
    }

    // Declarations
    fprintf(fout, "## DATA SECTION\n"
						"\t.data\n\n");
    printDecAsm(mainNode, fout);
    // Dec Temp Vars
    int nTemp = getTempSerial();
    for(int i=0; i<nTemp; i++) {
        fprintf(fout, "\t.globl __temp%d\n"
						"__temp%d: .long 0\n", i, i);
    }
}