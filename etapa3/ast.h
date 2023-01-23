/*
	Gabriel Madeira (00322863)
*/

#ifndef AST_HEADER
#define AST_HEADER


#include "hash.h"

#define AST_SYMBOL 1
#define AST_ADD 2
#define AST_SUB 3
#define AST_MUL 4
#define AST_DIV 5
#define AST_LES 6
#define AST_GRE 7
#define AST_AND 8
#define AST_OR 9
#define AST_NOT 10
#define AST_LE 11
#define AST_GE 12
#define AST_EQ 13
#define AST_DIF 14
#define AST_ASS 15
#define AST_LDCG 16
#define AST_LDCF 17
#define AST_LCMD 18
#define AST_ARAS 19
#define AST_ENTSE 20
#define AST_ENTSNSE 21
#define AST_ENQ 22
#define AST_ESCR 23
#define AST_RET 24
#define AST_GVAR 25
#define AST_GARR 26
#define AST_LEXP 27
#define AST_LEEXP 28
#define AST_LESTR 29
#define AST_ACALL 30
#define AST_FCALL 31
#define AST_PAR 32
#define AST_BLOCK 33
#define AST_FPL 34
#define AST_FCPL 35
#define AST_ENTRADA 36
#define AST_INTE 37
#define AST_CARA 38
#define AST_REAL 39

#define MAX_SONS 4

typedef struct ast_node
{
    int type;
    HASH * symbol; // ponteiro para hash
    struct ast_node* son[MAX_SONS];
} AST;

AST * astCreate(int type, HASH * symbol, AST* son0, AST* son1, AST* son2, AST* son3);
void astPrint(AST* node, int level);
void astDecompile(AST* node);


#endif