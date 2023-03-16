/*
	Gabriel Madeira (00322863)
*/

#ifndef TACS_HEADER
#define TACS_HEADER

#include <stdio.h>
#include "hash.h"
#include "ast.h"

#define TAC_SYMBOL 1

#define TAC_ADD 2
#define TAC_SUB 3
#define TAC_MUL 4
#define TAC_DIV 5
#define TAC_LES 6
#define TAC_GRE 7
#define TAC_AND 8
#define TAC_OR 9
#define TAC_NOT 10
#define TAC_LE 11
#define TAC_GE 12
#define TAC_EQ 13
#define TAC_DIF 14

#define TAC_MOVE 15
#define TAC_VAR 16
#define TAC_MOVEVEC 17
#define TAC_VEC 18
#define TAC_LEXP 19
#define TAC_ACALL 20
#define TAC_LABEL 21
#define TAC_BEGINFUN 22
#define TAC_ENDFUN 23
#define TAC_IFZ 24
#define TAC_JUMP 25
#define TAC_CALL 26
#define TAC_ARG 27
#define TAC_RET 28
#define TAC_PRINT 29
#define TAC_PRINTL 30
#define TAC_READ 31
#define TAC_PARAM 32

typedef struct tac_node
{
    int type;
    HASH *res;
    HASH *op1;
    HASH *op2;
    struct tac_node *prev;
    struct tac_node *next;
} TAC;

TAC *tacCreate(int type, HASH * res, HASH *op1, HASH *op2);
void tacPrintSingle(TAC *tac);
void tacPrintBackwards(TAC *tac);
TAC *tacJoin(TAC* l1, TAC* l2);

// code generation

TAC *generateCode(AST * node, HASH *currentLoopLabel);

TAC* tacReverse(TAC *tac);
void generateAsm(TAC *first, AST *mainNode);

#endif