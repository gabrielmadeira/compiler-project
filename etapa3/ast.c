#include <stdio.h>
#include <stdlib.h>
#include "ast.h"

extern FILE *outputFile;

AST * astCreate(int type, HASH * symbol, AST* son0, AST* son1, AST* son2, AST* son3) {
    AST* newnode;
    newnode = (AST*) calloc(1, sizeof(AST));

    newnode->type = type;
    newnode->symbol = symbol;
    newnode->son[0] = son0;
    newnode->son[1] = son1;
    newnode->son[2] = son2;
    newnode->son[3] = son3;
    return newnode;
}


void astPrint(AST* node, int level){
    if(!node) return;
    int i=0;
    
    for(i=0; i<level; ++i)
        fprintf(stderr,"  ");
    fprintf(stderr, "AST(");
    switch (node->type)
    {
        case AST_SYMBOL: fprintf(stderr, "AST_SYMBOL"); break;
        case AST_ADD: fprintf(stderr, "AST_ADD"); break;
        case AST_SUB: fprintf(stderr, "AST_SUB"); break;
        case AST_MUL: fprintf(stderr, "AST_MUL"); break;
        case AST_DIV: fprintf(stderr, "AST_DIV"); break;
        case AST_ASS: fprintf(stderr, "AST_ASS"); break;
        default: fprintf(stderr, "AST_UNKNOWN(%d)",node->type); break;
    }

    if(node->symbol != 0)
        fprintf(stderr, ",%s\n", node->symbol->text);
    else
        fprintf(stderr, ",0\n");
    for (i=0; i<MAX_SONS; ++i)
        astPrint(node->son[i], level+1);
    //for(i=0; i<level; ++i)
    //    fprintf(stderr,"  ");
    //fprintf(stderr,")\n");
}

void astDecompile(AST* node) {
    if(!node) return;
    switch (node->type)
    {
        case AST_SYMBOL: 
            fprintf(outputFile, "%s",node->symbol->text); break;
        case AST_ADD:
            astDecompile(node->son[0]);
            fprintf(outputFile, "+");
            astDecompile(node->son[1]);
            break;
        case AST_SUB:
            astDecompile(node->son[0]);
            fprintf(outputFile, "-");
            astDecompile(node->son[1]);
            break;
        case AST_MUL:
            astDecompile(node->son[0]);
            fprintf(outputFile, "*");
            astDecompile(node->son[1]);
            break;
        case AST_DIV:
            astDecompile(node->son[0]);
            fprintf(outputFile, "/");
            astDecompile(node->son[1]);
            break;
        case AST_LES:
            astDecompile(node->son[0]);
            fprintf(outputFile, "<");
            astDecompile(node->son[1]);
            break;
        case AST_GRE:
            astDecompile(node->son[0]);
            fprintf(outputFile, ">");
            astDecompile(node->son[1]);
            break;
        case AST_AND:
            astDecompile(node->son[0]);
            fprintf(outputFile, "&");
            astDecompile(node->son[1]);
            break;
        case AST_OR:
            astDecompile(node->son[0]);
            fprintf(outputFile, "|");
            astDecompile(node->son[1]);
            break;
        case AST_NOT:
            astDecompile(node->son[0]);
            fprintf(outputFile, "~");
            astDecompile(node->son[1]);
            break;
        case AST_LE:
            astDecompile(node->son[0]);
            fprintf(outputFile, "<=");
            astDecompile(node->son[1]);
            break;
        case AST_GE:
            astDecompile(node->son[0]);
            fprintf(outputFile, ">=");
            astDecompile(node->son[1]);
            break;
        case AST_EQ:
            astDecompile(node->son[0]);
            fprintf(outputFile, "==");
            astDecompile(node->son[1]);
            break;
        case AST_DIF:
            astDecompile(node->son[0]);
            fprintf(outputFile, "!=");
            astDecompile(node->son[1]);
            break;
        case AST_PAR:
            fprintf(outputFile, "(");
            astDecompile(node->son[0]);
            fprintf(outputFile, ")");
            break;
        case AST_ENTRADA:
            fprintf(outputFile, "ENTRADA ");
            break;
        case AST_LDCG:
            astDecompile(node->son[0]);
            fprintf(outputFile, ";\n");
            astDecompile(node->son[1]);
            break;
        case AST_LDCF:
            astDecompile(node->son[0]);
            fprintf(outputFile, " %s (",node->symbol->text);
            astDecompile(node->son[1]);
            fprintf(outputFile, ") ");
            astDecompile(node->son[2]);
            fprintf(outputFile, ";\n");
            astDecompile(node->son[3]);
            break;
        case AST_LCOM:
            astDecompile(node->son[0]);
            fprintf(outputFile, ";\n");
            astDecompile(node->son[1]);
            break;
    }
}
