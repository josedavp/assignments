#ifndef _booleanEvaluation_h
#define _booleanEvaluation_h

#include <stdio.h>
#include <string.h>
#include "stack.h"
#include "booleanWithError.h"

char *evaluatePostfix( char *str );
char *postfixToInfix( char *str );
void answerRetrieval(Stack *s, char *op1, char *op2, int value);
int switchCase( char *x );
char* additionalMemory (char *str);
void printTheStack(Stack *s);

#endif
