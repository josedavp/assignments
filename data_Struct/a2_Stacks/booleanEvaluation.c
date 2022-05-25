#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "stack.h"
#include "booleanEvaluation.h"
#include "booleanWithError.h"

/* evaluatePostfix
 * input: a postfix expression
 * output: T, F, or E
 *
 * Uses a stack to evaluates the postfix expression and returns the result as a string where "T" denotes true and "F" denotes false.
 * If the postfix expression is invalid it returns "E" to denote an error has occurred.
 */
char *evaluatePostfix( char *str ) 
{
    Stack *s = createStack();
    char *x;
    char *op1, *op2;
    int val;
    boolean a;
    x = additionalMemory(strtok(str, " "));
    
    int stackCount = 0;
    while(x != NULL) 
    { 
       
        if (strcmp(x, "T")==0 || strcmp(x,"F")==0)
        {          
            push(s, x); 
            stackCount++;
        }
        else if (strcmp(x, "NOT")==0) 
        {
            if (isEmpty(s))
            {
                freeStackElements(s);
                freeStack(s);
                return booleanToString(ERROR);
            }
            else 
            {
                op1 = pop(s);
                op2 = NULL;
             
                val = switchCase(x);
              
                answerRetrieval(s, op1, op2, val); //seg fault  
            }
        }
        else if(strcmp(x, "NOT") != 0)
        {
            op1 = pop(s); 
            op2 = pop(s); 
            if (op1 == NULL || op2 == NULL)
            {
                freeStackElements(s);
                freeStack(s);
                return booleanToString(ERROR);
            }
         
            val = switchCase(x);
            answerRetrieval(s, op1, op2, val); 
            stackCount--;
            stackCount--;
        }//end Binaries
       
        //if(x != NULL) free(x);
        x = additionalMemory(strtok(NULL, " "));
        
        if (x == NULL)
        {
            char * ptr = additionalMemory(pop(s));
            
            if (isEmpty(s) == TRUE)
            {
                
                freeStackElements(s);
                freeStack(s);
                a = stringToBoolean(ptr);       
                return booleanToString(a);
            }
            else 
            {
                printTheStack(s);
                freeStackElements(s);
                freeStack(s);
                return booleanToString(ERROR);
            }
        }
    }//end while loop
    freeStackElements(s);
    freeStack(s);
    return booleanToString( ERROR );
} //end of function
/******************************************************************************/
void answerRetrieval(Stack *s, char *op1, char *op2, int value) //correct equations and thats all
{
    boolean r1 = stringToBoolean(op1);
    boolean r2 = stringToBoolean(op2);
    free(op1);
    if(op2 != NULL) free(op2);
    switch(value)
    {
        case 0://AND
          //  printf("This is r1: %d\n This is also r2: %d\n", r1, r2);
                    
           if ( r2 && r1)
            {
                push(s, booleanToString(TRUE));  
            }
            else 
            {
                push(s, booleanToString(FALSE));       
            }
            break;
        case 1: // NAND
            if (!(r2 && r1))
            {
                push(s, booleanToString(TRUE));           
            }
            else 
            {
                push(s, booleanToString(FALSE));           
            }
            break;
        case 2: // OR
            if ( r2 || r1)
            {
                push(s, booleanToString(TRUE));          
            }
            else 
            {
                push(s, booleanToString(FALSE));             
            }
            break;
        case 3: // NOR
            if (!(r2 || r1))
            {
                push(s, booleanToString(TRUE));         
            }
            else
            {
                push(s, booleanToString(FALSE));         
            }
            break;
        case 4: // XOR
            if (r2 != r1)
            {
                push(s,booleanToString(TRUE));            
            }
            else 
            {
                push(s, booleanToString(FALSE));           
            }
            break;
        case 5: // COND
            if (!r2 || r1)
            {
                push(s, booleanToString(TRUE));
            }
            else
            {
                push(s, booleanToString(FALSE));              
            }
            break;
        case 6: // BICOND
            if (r2 == r1)
            {
                push(s, booleanToString(TRUE));             
            }
            else 
            {
                push(s,booleanToString(FALSE));         
            }
            break;
        case 7: // NOT
            if (!r1)
            {
                push(s, booleanToString(TRUE));            
            }
            else 
            {
                push(s,booleanToString(FALSE));
            }
            break;
        case 8:
        default:
            printf("Oh so I see you are approaching me?");
            break;
    }
} // end of function
  
/********************************************************************/
/* postfixToInfix
 * input: a postfix expression
 * output: the equivalent infix expression
 *
 * Uses a stack to convert str to its equivalent expression in infix.
 * You can assume that the postfix expression is valid
 */
char *postfixToInfix( char *str ) 
{
    Stack *s = createStack();
    char *x;
    char *op1, *op2, *dest, *result;
    
    x = additionalMemory(strtok(str, " "));
    
    
    while (x != NULL)
    {
        
        if (strcmp(x, "T")==0 || strcmp(x,"F")==0)
        {          
            push(s, x); 
        }
        else if (strcmp(x, "NOT")==0) 
        {
            op1 = pop(s);
            if (op1 == NULL)
            {
                freeStackElements(s);
                freeStack(s);
                return booleanToString(ERROR);
            }
            
            dest = (char *) malloc( strlen(op1) + strlen(x) + 6 ); //makes exact space requirement I hope
            
            strcat (dest, "( ");
            strcat (dest, x);
            strcat (dest, " ");
            strcat (dest, op1);
            strcat (dest, " )");
            
            push(s, dest);

            free(x);
        } // end of Unary
        else if(strcmp(x, "NOT") != 0) // Binaries
        {
            op2 = pop(s); 
            op1 = pop(s); 
            
            if (op1 == NULL || op2 == NULL)
            {
                return booleanToString(ERROR);
            }
            dest = (char *) malloc( strlen(op1) + strlen(x) + strlen(op2) + 7 ); //makes exact space requirement I hope
        
            strcat (dest, "( "); 
            strcat (dest, op1);
            strcat (dest, " ");
            strcat (dest, x);
            strcat (dest, " ");
            strcat (dest, op2);
            strcat (dest, " )");
            
            push(s, dest);
            free(x);
        } // end of Binaries
        
        x = additionalMemory(strtok(NULL, " "));
    }
    
    result = pop(s);
    
    if (isEmpty(s) != TRUE) 
    {
        freeStackElements(s);
        freeStack(s);
        return booleanToString(ERROR);
    }
    
    freeStackElements(s);
    freeStack(s);
    return result;

}//end of function
/********************************************************************/











/********************************************************************/
int switchCase( char* x )
{
    //printf("Inside switchCase, %s\n", x);
    int value;
    if(strcmp(x, "AND")==0)
    {
        value = 0;
    }
    if( strcmp(x, "NAND")==0)
    {
        value = 1;
    }
    if (strcmp(x, "OR")==0)
    {
        value = 2;
    }
    if( strcmp(x, "NOR")==0)
    {
        value = 3;
    }
    if (strcmp( x, "XOR")==0)
    {
        value = 4;
    }
    if (strcmp(x, "COND")==0)
    {
        value = 5;
    }
    if (strcmp(x, "BICOND")==0)
    {
        value = 6;
    }
    if (strcmp(x, "NOT")==0)
    {
        value = 7;
    }

    return value;
}// end of function
/********************************************************************/
void printTheStack(Stack *s)
{
    char *ptr;
    
    while (isEmpty(s) != TRUE)
    {
        ptr = pop(s);
        printf("OK: %s\n", ptr);
        free(ptr);
    }
}// end of function
/********************************************************************/
char* additionalMemory (char *str)
{
    if(str == NULL) 
    {
        return NULL;
    }
    char *x = (char*) malloc(strlen(str));
    strcpy(x,str);
    return x;
}// end of function
/********************************************************************/
