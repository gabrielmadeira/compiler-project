/*
	Gabriel Madeira (00322863)
*/

#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include "ast.h"
#include "semantic.h"

extern FILE *yyin;
FILE *outputFile;

extern AST *mainNode;

int yyparse();

int getLineNumber();
void initMe();

int main(int argc, char **argv) {
	
	if(argc<3){
		fprintf(stderr, "Call: etapa3 inputName outputName\n"); 
		exit(1);
	}
	if(0==(yyin = fopen(argv[1],"r"))){
		fprintf(stderr, "Cannot open file %s\n", argv[1]);
		exit(2);	
	}
	if(0==(outputFile = fopen(argv[2],"w"))){
		fprintf(stderr, "Cannot open file %s\n", argv[1]);
		exit(2);	
	}

	initMe();

	yyparse();

	printf("\nDecompiling...\n");
	astDecompile(mainNode);

	printf("\nPerforming Semantic Verification...\n");
	semanticVerification(mainNode);

	int semanticErrors = getSemanticErrors();
	if(semanticErrors > 0) {
		fprintf(stderr, "%d Semantic errors detected, exiting...\n", semanticErrors);
		exit(4);	
	}

	printf("\nAST Content:\n");
	astPrint(mainNode,0);

	printf("\nHash Content:\n");
	hashPrint();

	printf("\nFile had %d lines\n", getLineNumber());
	printf("\nSuccess!\n\n");

	exit(0);
}
