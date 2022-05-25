/*
    airport-program.c
    Project 1
    Jose Pague

    This is the driver for the airport program. It is displays the main menu presenting a selection of options     
    for the user to get information about the airports in the system. The main function will then call functions
    in airport.c to calculate and retrieve information, which will then be printed here. 
 */
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "airport-program.h"
#include "airport.h"

static int length = 0;

/* 
    printMenu
    ---------------------------
    This function prints the main menu.
    Returns: Nothing
 */

/***************************************************************************/

void printMenu() {
    printf("\n#########################################\n");
    printf("\tAirport Program Menu\n");
    printf("#########################################\n");
    printf("\t1 - Get Airport Information\n");
    printf("\t2 - Get Airport Listing\n");
    printf("\t3 - Get Distance Between Two Airports\n");
    printf("\t4 - Find Airports Within Range\n");
    printf("\t0 - Quit\n");
    printf("Enter your selection: ");
}
/***************************************************************************/
/*
    main 
    ---------------------------
    This is the main driver of your program. See the comments below on how to complete the driver. 
    Returns: 0 
 */

/***************************************************************************/

int main(int argc, char *argv[]) {
    Airport airports[ MAX ];
    int choice;
    // Airport airports[ AIRPORTS ];
    int length = fillAirports(airports);
    while (TRUE) {
        /* call the function to print the menu */
        printMenu();
        /* ask the user to input their selection */
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Issue is not printing name, latitude or longitude etc. only -9999999 and code
                ;
                /*  
                 1. Ask the user to enter a 3-letter airport code.
                 2. Call findAirport()                                           
                 3. If either airport's latitude or longitude of -99999, that means the airport was not found. In that case, print out an error.              
                 4. Print the airport information    
                 */
                
                char code[4];

                printf("\nEnter airport code: ");
                scanf("%s", code);
                //printf("%s", code);

                Airport found = findAirport(airports, length, code);
                if (found.latitude == -999999 || found.longitude == -999999) 
                {
                    printf("No airports were found");

                } 
                else 
                {
                    printAirport(found);
                }
                break;

            case 2:

                /*
                    Call the printAirports() function 
                 */
                printf("\n");
                printAirports(airports, length);
                printf("\n");

                break;

            case 3:
                /*                                                                                                      
                1. Ask the user to enter a 3-letter airport code.                                                           
                2. Ask the user to enter another 3-letter airport code. 
                3. Call findAirport() twice (for each of the airports entered)                                              
                4. If either airport's latitude or longitude of -99999, that means the airport was not found. In that case, print out an error. Otherwise, call the calculateDistance() function.                                                       
                5. Print out the distance.                                                                                  
                 */
                ;
                char code1[4];
                char code2[4];

                printf("Enter airport 1 code: ");
                scanf("%s", code1);

                printf("Enter airport 2 code: ");
                scanf("%s", code2);
                
                Airport found1 = findAirport(airports, length, code1);
                Airport found2 = findAirport(airports, length, code2);

                if (found1.latitude == -999999 || found1.longitude == -999999 || found2.latitude == -999999 || found2.longitude == -999999) 
                {
                    printf("error");
                    continue;
                } 
                else 
                {
                    printf("The distance between");  
                    double distance = calculateDistance(found1, found2);
                    printf(" %s and %s ", found1.name, found2.name);
                    printf(" is %lf miles.", distance);
                }
                break;
                
            case 4:
                /*  
                    1. Ask the user to enter a 3-letter airport code, 
                    2. Ask the user to enter a range in miles (integer)
                    3. Call findAirport() to find the struct for that Airport 
                    4. Call findInRange() to get an array of Airports within the range
                    5. Print the return array of Airport, if the array's length is empty state that no airports were found
                 */
                ;
                int range; 
                char code3[4];
                //code3 = NULL;
                 
                printf("Enter airport code: ");
                scanf("%s", code3);            
                
                printf("Enter range in miles: ");
                scanf("%d", &range);
                       
                found = findAirport(airports, length, code3);
                
                Airport output[MAX];
                int resultsLength = 0;
                findInRange ( airports, length, found , range , output, &resultsLength);
                
                if (resultsLength == 0)
                {
                    printf("No airports were found");
                }
                else {
                    findInRange ( airports, length, found , range , output, &resultsLength);
                    printAirports( output, resultsLength);   
                    //printf("%d", resultsLength);
                }
                break;
            case 0:
                printf("Good-bye!\n");
                return 0;
        }
    }

    return 0;
}

