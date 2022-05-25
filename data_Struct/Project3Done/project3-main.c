#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "itinerary.h"

/* 
 * project3-main.c
 * Project3 
 * Jose Pague
 * 
 * This is the driver for the entire program. It displays the main menu along with optional choices to add, 
 * delete, destruct linked lists for Airport Codes.
 */

int main( int argc, char *argv[] )
{
 	/* declare all your variables here */
 	int choice;
        char code[4];
        char key[4];

        Destination *head = NULL;
        Destination *newNode;
    
	while( TRUE ) // needs to be fixed to handle invalid input
	{ 
		printMenu();

        /* adapt the scanf() to handle invalid input */
        scanf( "%d", &choice ); 
        
        
        switch( choice )
        {
            case 1: 
                /* 
                   1) Ask the user to enter the new airport code to add
                   2) If the list is empty, call create() and insertAfter() to create and 
                      insert it into the linked list. Print out a message saying that 
                      a new itinerary was created. 
                   3) If the list is not empty, ask the user where in the list they want
                      to add the node. The user will enter the airport code in which this
                      new node will be added AFTER in the linked list. Then, call create()
                      and insertAfter() to create and insert it into the linked list. 
                     	3.1) If the user enters ZZZ as the airport code, it will add 
                      	     the new node to the beginning and if the user enters an
                      	     airport code, it adds the new node to the end. 
                     	3.2) An airport code cannot appear one right after another in the
                      		 itinerary. If the new airport code and the after airport code
                      		 or the same, print out an error and do not allow the add
                        3.3) Recall that insertAfter() returns NULL if it was unable
                		     to insert the new node. Your code must address this error.
                   4) Print a message success message if an airport code was added
                */
                
           
                if(head == NULL)
                {
                printf("Enter the airport code for the destination: ");
                scanf("%s", code);
                newNode = create(code); 
                head = insertAfter(head, newNode, code);
                }
                else 
                {
                printf("Enter the airport code for the destination: ");
                scanf("%s", code);
                printf("Enter the airport code for which new destination is added after.\n");
                printf("Enter ZZZ to add to beginning of the list: ");
                scanf("%s", key);
                    if (strcmp(key, code) == 0 )
                    {
                    printf("Error Duplicate");
                    }
                    else 
                    {
                     newNode = create(code); 
                    head = insertAfter(head, newNode, key);    
                    }               
                }
                                                                                                                                      
                break;
            case 2: // need to complete ;
                /* 
                   1) Ask the user to enter an airport code
                   2) Check to see if the airport code exists in the list with find(), if 
                      it does not exist, print an error and break;
                   3) Call remove() the airport code from the list  
                   4) Print a message saying the destination was removed
                */
                
                // create an if statement if it does not exist and print error
                
                //if( ) would you put a strcmp for find(head, code2) ??
                //or can I print an error within the function find?
              
                printf("Enter the airport code for the destination: ");
                scanf("%s", code);
                
                if (find(head, code) != NULL)
                {
                head = removeNode(head, code); 
                }
                else
                {
                    printf("Error\n");
                }
                break;
            case 3: 
                /* call print() */
                print(head);
                break;
            case 4:
                /* call printItinerary() */
                printItinerary(head); 
                break;
            case 5:
                /* call destruct() */
                destruct( head );  
                head = NULL;
                break;
            case 0:
                /* print a farewell message and call destruct() */
                destruct( head );
                printf("Good-bye");
                return 1;
            default:
                /* print a message saying that the input choice was not valid */
                printf("Invalid choice");
                break;
        }
	}
        free(head);
        free(newNode);
    return 0;
}