/*
	Gabriel Madeira (00322863)
*/

#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
//#include "lex.yy.h"

extern FILE *yyin;
FILE *outputFile;

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

	printf("\nHash Content:\n");
	hashPrint();

	printf("\nFile had %d lines\n", getLineNumber());
	printf("\nSuccess!\n\n");

	exit(0);
}
