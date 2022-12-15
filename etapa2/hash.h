/*
	Gabriel Madeira (00322863)
*/

#ifndef HASH_HEADER
#define HASH_HEADER

#define HASH_SIZE 997

typedef struct hash_node
{
	int type;
	char *text;
	struct hash_node *next;
} HASH;

void hashInit(void);
int hashAddress(char *text);
HASH *hashFind(char *text);
HASH *hashInsert(int type, char *text);
void hashPrint(void);

#endif