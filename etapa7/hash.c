/*
	Gabriel Madeira (00322863)
*/

#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int labelSerial = 0;
int tempSerial = 0;

HASH *Table[HASH_SIZE];

void hashInit(void) {
	int i=0;
	for (i=0; i<HASH_SIZE; i++) Table[i]=0;
}

int hashAddress(char *text) {
	int address = 1;
	int i=0;
	for (i=0; i<strlen(text); i++)
		address = (address*text[i])%HASH_SIZE + 1;
	return address-1;
}

HASH *hashFind(char *text) {
	HASH *node;
	int address = hashAddress(text);
	for (node=Table[address]; node; node = node->next)
		if (strcmp(node->text,text)==0)
			return node;
	return 0;
}

HASH *hashInsert(int type, char *text) {
	int address = hashAddress(text);;
	HASH *node;

	if((node = hashFind(text)) != 0)
		return node;

	node = (HASH*) calloc(1,sizeof(HASH));
	node->type = type;
	node->text = (char*) calloc (strlen(text)+1,sizeof(char));
	strcpy(node->text,text);
	node->next = Table[address];
	Table[address] = node;

	if(node->type == SYMBOL_LIT_INTE)
		node->datatype = DATATYPE_INTE;
	else if(node->type == SYMBOL_LIT_CARA)
		node->datatype = DATATYPE_CARA;
	else if(node->type == SYMBOL_LIT_REAL)
		node->datatype = DATATYPE_REAL;

	return node;
}

void hashPrint(void) {
	HASH * node;
	for (int i=0; i<HASH_SIZE; i++)
		for(node=Table[i]; node; node = node->next)
			printf("Table[%d] has %s, with datatype %d\n", i, node->text, node->datatype);
} 

int hashCheckUndeclared(void) {
	int undeclared = 0;
	HASH * node;
	for (int i=0; i<HASH_SIZE; i++)
		for(node=Table[i]; node; node = node->next){
			if(node->type == SYMBOL_LIT_IDENTIFIER){
				printf("Semantic Error: symbol %s undeclared.\n", node->text);
				undeclared++;
			}
		}
	return undeclared;
}

int getTempSerial() {
	return tempSerial;
}

HASH *makeTemp(void) {
	char buffer[256] = "";
	sprintf(buffer, "_temp%d",tempSerial++);
	return hashInsert(SYMBOL_VAR, buffer);
}

HASH *makeLabel(void) {
	char buffer[256] = "";
	sprintf(buffer, "_label%d",labelSerial++);
	return hashInsert(SYMBOL_LABEL, buffer);
}

// void printAsm(FILE *fout) {
// 	HASH * node;
// 	fprintf(fout, "## DATA SECTION\n"
// 						"\t.data\n\n");
// 	for (int i=0; i<HASH_SIZE; i++)
// 		for(node=Table[i]; node; node = node->next) {
// 			// TODO: fazer para vetor
// 			if(node->type == SYMBOL_VAR || node->type == SYMBOL_LIT_INTE || node->type == SYMBOL_LIT_CARA) 
// 				fprintf(fout, "\t.globl _%s\n"
// 							"_%s: .long %s\n", node->text, node->text, node->);
// 			if(node->type == SYMBOL_LIT_INTE || node->type == SYMBOL_LIT_CARA) 
// 				fprintf(fout, "\t.globl _%s\n"
// 							"_%s: .long %s\n", node->text, node->text, node->text);
// 			//printf("Table[%d] has %s, with datatype %d\n", i, node->text, node->datatype);	
// 		}
// }