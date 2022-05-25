#include <stdio.h>
#include <stdlib.h>
#include "pslibrary.h"

int main (int argc, char *argv[])
{
    if (argc != 8 ) 
    {
        fprintf(stderr, "Missing the requirement of arguments"); //or maybe just missing enough parameters
        return 1;
    }
    int i;
    int sumR = 0;
    int lowR = 0;

    /*
    for (i = 0; i <= argc-1; i++) 
    {
        printf("THIS is argc %d: %s\n", i, argv[i]);
    }
    */

    printf("CS 3424 Assignment 2 program was written by Jose Pague\n");
    
    /********************/
    int q = atoi(argv[1]);
    int x1 = atoi(argv[2]);
    int y1 = atoi(argv[3]);
    int z1 = atoi(argv[4]);
    int x2 = atoi(argv[5]);
    int y2 = atoi(argv[6]);
    int z2 = atoi(argv[7]);
    /********************/

    int size =  x1 + y1 + z1 + x2 + y2 + z2;
    char s1[size];
    char s2[size];

    int countX1 = 0;
    int countX2 = 0;
    /***************FUNCTIONS******************/
   

    /**********PRINTS FIRST FUNCTION***********/
    printf("\nschedule fcfs: \n");
    fcfs(s1, s2, x1,  y1, z1, x2, y2, z2);
    displayPrint(s1,s2, size);

    /**********PRINTS SECOND FUNCTION***********/
    printf("\nschedule sjf: \n");
    sjf(s1, s2, x1,  y1, z1, x2, y2, z2);
    
    displayPrint(s1,s2, size);
    
    /**********PRINTS THIRD FUNCTION***********/
    printf("\nschedule psjf: \n");
    psjf(s1, s2, x1,  y1, z1, x2, y2, z2);
    displayPrint(s1,s2, size);

    /**********PRINTS FOURTH FUNCTION***********/
    printf("\n/********************FUNCTION FOR RR************************/\n"); //delete later just to help see rr
    printf("\nschedule rr: \n");
    rr(s1, s2,q, x1,  y1, z1, x2, y2, z2);
    displayPrint(s1,s2, size);
    printf("\n/********************FUNCTION FOR RR************************/\n"); //delete later just to help see rr
}
