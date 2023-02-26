/*
	Gabriel Madeira (00322863)
*/

#ifndef SEMANTIC_HEADER
#define SEMANTIC_HEADER

#include "ast.h"
#include "hash.h"

extern int SemanticErrors;

int convertToDatatype(int type);
int integerOrChar(int datatype);
int datatypeCompatible(int datatype1, int datatype2);
int checkSize(AST* node, int size);
int checkVectorElements(AST *node, int datatype);
void setDeclarations(AST *node);
void checkUndeclared(void);
int getSemanticErrors(void);
int arithmetic(int type);
int calcDatatype(int type1, int type2);
int relational(int type);
int logical(int type);
void checkOperands(AST* node);
AST* findDeclaration(char * name, AST * node);
int calcNumberOfArguments(AST *node);
int compareNumberOfArguments(AST *node, AST *declaration);
void compareCalledArguments(AST *node, AST *declaration);
void checkWrite(AST *node);
void checkCorrectUse(AST* node);
void checkCompatibleReturn(AST *node, int datatype);
void checkReturn(AST* node);
void semanticVerification(AST* node);

#endif