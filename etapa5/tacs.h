// tacs.h

#ifndef TACS_HEADER
#define TACS_HEADER

#include <stdio.h>
#include "hash.h"
#include "ast.h"

#define TAC_SYMBOL 1
#define TAC_ADD 2
#define TAC_SUB 3
#define TAC_COPY 4
#define TAC_JFALSE 5
#define TAC_JLABEL 6

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