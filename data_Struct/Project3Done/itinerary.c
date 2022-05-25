/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "itinerary.h"

/*
  
 *create()
 --------------------------------------------------------
 This function creates new nodes using the inputted code.
    Return: newNode
 
 */

Destination *create( char *code )
{
    Destination *newNode= (Destination *) malloc(sizeof(Destination)); 
    
    strcpy(newNode->airCode, code );
    
    return newNode;
    
}
/**********************************************************/
/*
 
 *insertAfter()
 --------------------------------------------------------
 This function inserts the a node within the linked list.
    Return: head
 
 */
Destination *insertAfter( Destination *head, Destination *node, char *key ) 
{
    /* dynamically create a new Node */ 
    Destination *p = head;
    
    if ( head == NULL )
    {
        head = node; 
        return head;                                            
    } 
    
    if (strcmp( key, "ZZZ") == 0)
    {
          node->next = head;
          head = node;
          
          return head;
    }
    else if (head == NULL )
    {
        return head;
    }
    
     //similar to find function
    for (p = head; p->next != NULL; p= p->next) 
    {
        if ( strcmp(p->airCode, node->airCode) == 0)
        {
            return head;
        }
        if(strcmp(p->airCode, key) == 0)
        {          
            node->next = p->next;
            p->next = node;
            return head;
        }
        
    }
    
    p->next = node;
    return head;
}

/**********************************************************/
/*
 
 *find()
 --------------------------------------------------------
 This function locates a specific node and if it does not exist returns NULL.
    Return: ptr 
    or 
    Return: NULL
 
*/
Destination *find( Destination *head, char *key )
{
    Destination *ptr;
    /* go through each node and check to the value against the key */
    for( ptr = head; ptr != NULL; ptr = ptr->next )
    {
        if(strcmp(ptr->airCode, key) == 0)
        {
            return ptr;
        }

        
        // create else that says if not found then print error and break
    }
    /* if we reach this part, that means the value was not found */   
    return NULL; 
    
}

/**********************************************************/
/*

*removeNode()
 --------------------------------------------------------
 This function removes a specific node from the linked list.
    Return: head

 */
Destination *removeNode( Destination *head, char *key ) // not done
{           
    Destination *prev;
    Destination *current;
    Destination *delete = find(head, key);
       
        if ( delete == NULL)
        {
            return head; // better to return as NULL
        }
        if (delete == head)
        {
            current = head->next;
            free(head);
            return current;
        }
    for (current = head; current->next != NULL; current = current->next)
        {
        
            prev = current; 
            if (strcmp(current->next->airCode, key) == 0)
            {
                prev->next = delete->next;
                return head;
            }
           
        }

        prev->next = current->next;
        free(delete);
       
        printf("destination was removed");
        return head;
}

/**********************************************************/
/*
 
 *print()
 --------------------------------------------------------
 This function prints the entire linked list.
    Returns nothing
 
*/
void print( Destination *head )
{
    Destination *ptr;
    /* this for loop goes through each node from head until the end,
       and prints out each value */
    printf("Destinations in Itinerary\n");
    
    for( ptr = head; ptr != NULL; ptr = ptr->next )
    {
        printf( "%s\n", ptr->airCode ); 
    }
    
}

/**********************************************************/
/*
 
 printItinerary()
 --------------------------------------------------------
 This function prints the entire linked list along with a count of how many segments there are.
    Returns Nothing 
 
*/
void printItinerary( Destination *head)
{
    Destination *ptr = head;
    
    printf("Itinerary\n");
    if ( head == NULL)
    {
        printf("Could not find Airport Codes\n");
        return;
    }
    
    int count = 0;
    for ( ptr = head; ptr!= NULL; ptr= ptr->next)
    {
        //need a counter;
        printf("%s-%s\n", ptr->airCode, ptr->next->airCode); 
        count++;
    }
    printf("\n"); 
    printf("Total Segments: %d", count);
    
}

/**********************************************************/
/*

*destruct()
 --------------------------------------------------------
 This function deallocates and "deletes" the entire linked list.
    Return: NULL
 
*/
Destination *destruct( Destination *head)
{
    Destination *temp; 
     while( head != NULL )
    {
        
        temp = head;   /* set temporary pointer */
        head = head->next;        /* advance the temp to the next item */
        free(temp );      /* free the current pointer */
   
     }
    free(head);
    printf("Itinerary cleared."); 
    return NULL; 
    
}

/* option 2 recursive way
 void *destruct2( Destination * head ) // recursive way
 {
    if ( head != NULL )
    {
        destruct2(head->next);
        free(head);
    }
}
 */

/*
 
Destination *destruct (Destination *head)
{
    head = NULL;
    return head;
}
   
*/

/**********************************************************/
/*
 
 printMenu()
 --------------------------------------------------------
 This function contains a print of the entire Menu for this program.
    Returns Nothing
 
*/
void printMenu()
{
    printf( "\n#########################################\n" );
    printf( "#            Trip Planner Menu          #\n" );
    printf( "#########################################\n" );
    printf( " 1 - Insert a Destination\n" );
    printf( " 2 - Remove a Destination\n" );
    printf( " 3 - Print Destinations\n" );
    printf( " 4 - Print Itinerary\n" );
    printf( " 5 - Clear Itinerary\n" );
    printf( " 0 - Quit\n" );
    printf( "Enter your selection: " );
}


