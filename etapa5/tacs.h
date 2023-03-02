// tacs.h

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

#define TAC_MOVE
#define TAC_MOVEVEC
#define TAC_ACALL
#define TAC_LABEL
#define TAC_BEGINFUN
#define TAC_ENDFUN
#define TAC_IFZ
#define TAC_JUMP
#define TAC_CALL
#define TAC_ARG
#define TAC_RET
#define TAC_PRINT
#define TAC_READ

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

TAC *generateCode(AST *node);

#endif