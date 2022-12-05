/*
	Gabriel Madeira (00322863)
*/

%{

	#include "tokens.h"
	#include "hash.h"
	
	int running = 1;
	int lineCount = 1;

%}

%x COMMENT

%%

"cara"		{ return KW_CARA; }
"inte"		{ return KW_INTE; }
"real"		{ return KW_REAL; }

"se"		{ return KW_SE; }
"entaum"	{ return KW_ENTAUM; }
"senaum"	{ return KW_SENAUM; }
"enquanto"	{ return KW_ENQUANTO; }
"entrada"	{ return KW_ENTRADA; }
"escreva"	{ return KW_ESCREVA; }
"retorne"	{ return KW_RETORNE; }

"<="		{ return OPERATOR_LE; }
">="		{ return OPERATOR_GE; }
"=="		{ return OPERATOR_EQ; }
"!="		{ return OPERATOR_DIF; }

[0-9]+					{ hashInsert(LIT_INTEIRO, yytext); return LIT_INTEIRO; }
[0-9]+"."[0-9]+			{ hashInsert(LIT_FLOAT, yytext); return LIT_FLOAT; }
'.'						{ hashInsert(LIT_CHAR, yytext); return LIT_CHAR; }
\"(\\.|[^"\\^(\n)])*\"	{ hashInsert(LIT_STRING, yytext); return LIT_STRING; }


[-;()\[\]{}=+*/<>&|~]	{ return yytext[0]; }
([a-z]|_|".")+([a-z]|[0-9]|_|".")* 		{ hashInsert(TK_IDENTIFIER, yytext); return TK_IDENTIFIER; }

[,\t ]

"\n"		{ lineCount++; }
"///".*		{ BEGIN(COMMENT); }
"//".*
.		{ return TOKEN_ERROR; }


<COMMENT>"\n"		{ lineCount++; }
<COMMENT>.	
<COMMENT>"\\\\\\"	{ BEGIN(INITIAL); }

%%

#include "main.c"

int getLineNumber(void) {
	return lineCount;
}

int isRunning(void) {
	return running;
}

int yywrap() {
	running = 0;
	return 1;
}

void initMe(void) {
	hashInit();
}