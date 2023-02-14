// SEMANTICA VERIFICATION

#ifndef SEMANTIC_HEADER
#define SEMANTIC_HEADER

#include "ast.h"
#include "hash.h"

extern int SemanticErrors;

void setDeclarations(AST *node);
void checkUndeclared(void);
int getSemanticErrors(void);
void checkOperands(AST* node);

void semanticVerification(AST* node);


#endif