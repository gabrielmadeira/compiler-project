/*
	Gabriel Madeira (00322863)
*/

#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	return node;
}

void hashPrint(void) {
	HASH * node;
	for (int i=0; i<HASH_SIZE; i++)
		for(node=Table[i]; node; node = node->next)
			printf("Table[%d] has %s\n", i, node->text);
} 
