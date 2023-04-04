/*
	Gabriel Madeira (00322863)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
        case AST_LES: fprintf(stderr, "AST_LES"); break;
        case AST_GRE: fprintf(stderr, "AST_GRE"); break;
        case AST_AND: fprintf(stderr, "AST_AND"); break;
        case AST_OR: fprintf(stderr, "AST_OR"); break;
        case AST_NOT: fprintf(stderr, "AST_NOT"); break;
        case AST_LE: fprintf(stderr, "AST_LE"); break;
        case AST_GE: fprintf(stderr, "AST_GE"); break;
        case AST_EQ: fprintf(stderr, "AST_EQ"); break;
        case AST_DIF: fprintf(stderr, "AST_DIF"); break;
        case AST_ASS: fprintf(stderr, "AST_ASS"); break;
        case AST_LDCG: fprintf(stderr, "AST_LDCG"); break;
        case AST_LDCF: fprintf(stderr, "AST_LDCF"); break;
        case AST_LCMD: fprintf(stderr, "AST_LCMD"); break;
        case AST_ARAS: fprintf(stderr, "AST_ARAS"); break;
        case AST_ENTSE: fprintf(stderr, "AST_ENTSE"); break;
        case AST_ENTSNSE: fprintf(stderr, "AST_ENTSNSE"); break;
        case AST_ENQ: fprintf(stderr, "AST_ENQ"); break;
        case AST_ESCR: fprintf(stderr, "AST_ESCR"); break;
        case AST_RET: fprintf(stderr, "AST_RET"); break;
        case AST_GVAR: fprintf(stderr, "AST_GVAR"); break;
        case AST_GARR: fprintf(stderr, "AST_GARR"); break;
        case AST_LEXP: fprintf(stderr, "AST_LEXP"); break;
        case AST_LEEXP: fprintf(stderr, "AST_LEEXP"); break;
        case AST_LESTR: fprintf(stderr, "AST_LESTR"); break;
        case AST_ACALL: fprintf(stderr, "AST_ACALL"); break;
        case AST_FCALL: fprintf(stderr, "AST_FCALL"); break;
        case AST_PAR: fprintf(stderr, "AST_PAR"); break;
        case AST_BLOCK: fprintf(stderr, "AST_BLOCK"); break;
        case AST_FPL: fprintf(stderr, "AST_FPL"); break;
        case AST_FCPL: fprintf(stderr, "AST_FCPL"); break;
        case AST_ENTRADA: fprintf(stderr, "AST_ENTRADA"); break;
        case AST_INTE: fprintf(stderr, "AST_INTE"); break;
        case AST_CARA: fprintf(stderr, "AST_CARA"); break;
        case AST_REAL: fprintf(stderr, "AST_REAL"); break;
        default: fprintf(stderr, "AST_UNKNOWN(%d)",node->type); break;
    }

    if(node->symbol != 0)
        fprintf(stderr, ",%s)\n", node->symbol->text);
    else
        fprintf(stderr, ",0)\n");
    for (i=0; i<MAX_SONS; ++i)
        astPrint(node->son[i], level+1);
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
            fprintf(outputFile, "~");
            astDecompile(node->son[0]);
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
            fprintf(outputFile, "entrada ");
            break;
        case AST_ACALL:
            fprintf(outputFile, "%s[",node->symbol->text);
            astDecompile(node->son[0]);
            fprintf(outputFile, "]");
            break;
        case AST_FCALL:
            fprintf(outputFile, "%s(",node->symbol->text);
            astDecompile(node->son[0]);
            fprintf(outputFile, ")");
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
            astDecompile(node->son[3]);
            break;
        case AST_LCMD:
            astDecompile(node->son[0]);
            fprintf(outputFile, ";\n");
            astDecompile(node->son[1]);
            break;
        case AST_ASS:
            fprintf(outputFile, "%s",node->symbol->text);
            fprintf(outputFile, "=");
            astDecompile(node->son[0]);
            break;
        case AST_ARAS:
            fprintf(outputFile, "%s[",node->symbol->text);
            astDecompile(node->son[0]);
            fprintf(outputFile, "]=");
            astDecompile(node->son[1]);
            break;
        case AST_ENTSE:
            fprintf(outputFile, "entaum ");
            astDecompile(node->son[0]);
            fprintf(outputFile, " se (");
            astDecompile(node->son[1]);
            fprintf(outputFile, ")");
            break;
        case AST_ENTSNSE:
            fprintf(outputFile, "entaum ");
            astDecompile(node->son[0]);
            fprintf(outputFile, " senaum ");
            astDecompile(node->son[1]);
            fprintf(outputFile, " se (");
            astDecompile(node->son[2]);
            fprintf(outputFile, ")");
            break;
        case AST_ENQ:
            astDecompile(node->son[0]);
            fprintf(outputFile, "enquanto (");
            astDecompile(node->son[1]);
            fprintf(outputFile, ")");
            break;
        case AST_ESCR:
            fprintf(outputFile, "escreva ");
            astDecompile(node->son[0]);
            break;
        case AST_RET:
            fprintf(outputFile, "retorne ");
            astDecompile(node->son[0]);
            break;
        case AST_GVAR:
            astDecompile(node->son[0]);
            fprintf(outputFile, " %s",node->symbol->text);
            fprintf(outputFile, "=");
            astDecompile(node->son[1]);
            break;
        case AST_GARR:
            astDecompile(node->son[0]);
            fprintf(outputFile, " %s[",node->symbol->text);
            astDecompile(node->son[1]);
            fprintf(outputFile, "] ");
            astDecompile(node->son[2]);
            break;
        case AST_LEXP:
        case AST_LEEXP:
        case AST_FCPL:
            astDecompile(node->son[0]);
            fprintf(outputFile, " ");
            astDecompile(node->son[1]);
            break;
        case AST_LESTR:
            fprintf(outputFile, "%s ",node->symbol->text);
            astDecompile(node->son[0]);
            break;
        case AST_BLOCK:
            fprintf(outputFile, " {\n");
            astDecompile(node->son[0]);
            fprintf(outputFile, " }\n");
            break;
        case AST_FPL:
            astDecompile(node->son[0]);
            fprintf(outputFile, " %s ",node->symbol->text);
            astDecompile(node->son[1]);
            break;
        case AST_INTE:
            fprintf(outputFile, "inte");
            break;
        case AST_CARA:
            fprintf(outputFile, "cara");
            break;
        case AST_REAL:
            fprintf(outputFile, "real");
            break;
    }
}

char *convertStrToId(char *str) {
    int i;
    char *modStr = (char *) calloc(strlen(str) + 1, sizeof(char));
    strcpy(modStr, str);

    for(i = 0; modStr[i]; ++i) {
        if(!((modStr[i] >= 'a' && modStr[i] <= 'z') || 
            (modStr[i] >= 'A' && modStr[i] <= 'Z') ||
            (modStr[i] >= '0' && modStr[i] <= '9'))) {
            int g = abs(modStr[i]);
            //modStr[i] = '_';
            char newChar = 'a'+(g%26);
            modStr[i] = newChar;
        }
    }

    return modStr;
}

void printDecAsm(AST* node, FILE *fout) {
	if(!node) return;

    switch(node->type) {
        case AST_FPL:
            fprintf(fout, "\t.globl _%s\n"
							"_%s: .long 0\n", node->symbol->text, node->symbol->text);
            break;
        case AST_GVAR: 
            fprintf(fout, "\t.globl _%s\n"
							"_%s: .long %s\n", node->symbol->text, node->symbol->text, node->son[1]->symbol->text);
            break;
        case AST_GARR: 
            fprintf(fout, "\t.globl _%s\n_%s:\n", node->symbol->text, node->symbol->text);
            AST* LEXPNode = node->son[2];
            while(LEXPNode){
                fprintf(fout,"\t.long %s\n", LEXPNode->son[0]?LEXPNode->son[0]->symbol->text:"");
                LEXPNode = LEXPNode->son[1];
            }
            break;
        case AST_SYMBOL: 
            if(node->symbol->type != SYMBOL_VAR && node->symbol->asmDefined != 1) {
                fprintf(fout, "\t.globl _%s\n"
							    "_%s: .long %s\n", node->symbol->text, node->symbol->text, node->symbol->text);
                node->symbol->asmDefined = 1;
            }
            break;
        case AST_LESTR:
            if(node->symbol->asmDefined != 1) {
                char *convertedStr = convertStrToId(node->symbol->text);
                fprintf(fout,   "_%s_l:\n\t.string %s\n\t.section .data.rel.local,\"aw\"\n"
                                "_%s: .quad _%s_l\n"
                                ""
                            , convertedStr, node->symbol->text, convertedStr, convertedStr);
                node->symbol->asmDefined = 1;
            }
            break;
        default: break;
    }

    for(int i=0; i<MAX_SONS; i++) {
        printDecAsm(node->son[i], fout);
    }
}