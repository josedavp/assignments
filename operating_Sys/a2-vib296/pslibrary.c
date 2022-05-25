#include "pslibrary.h"
#include <stdio.h>
#define READY  0
#define RUNNING  1
#define WAITING  2
#define DONE  3

static char stateChars[] = {'r','R','w','\0'};

/* 1) handle state changes:
         running process completes CPU burst
         running process has quantum expire
         IO complete
   2) do context switch if necessary
         both ready
         one ready and CPU free
   3) append appropriate characters to character arrays
         avoid putting in multiple string terminators
*/
/* assume s1 and s2 point to buffers with enough space to hold the result */
/* assume that the int parameters are strictly greater than 0 */
/*****************DISPLAYS THE OUTPUT FOR EACH OF THE FOUR FUNCTIONS**************/
void displayPrint(char *s1, char *s2, int size){
    float lowRx1 = 0; //gets x1 low r's
    float lowRx2 = 0;//gets x2 low r's
    float avgLength = 0;
    int countx1 = 0; //x1 used for uppercase R's
    int countx2 = 0;//x2 used for uppercase R's
    int largerNum; //used to obtain longest string
    int i;
    float avgNum = 0; //used to get avg r's
    /**********READS THROUGH THE ARRAYS AND PRINTS ITS CONTENTS*****/
    for (i = 0; i < size; i++)
    {
        if (s1[i] == '\0') // stops reading uneccessary part of array
        {
            printf("\n"); //Line needed for assignment
            break;
        }
        if (s1[i] == 'r') //These are used to count r's, and R's
        {
            lowRx1++;
        }
        else if (s1[i] == 'R')
        {
            countx1++;
        }
        printf("%c", s1[i]);//prints string
    }
    /*****SAME AS ABOVE FOR LOOP JUST FOR SECOND ARRAY*****/
    for(i = 0; i < size; i++)
    {
        if(s2[i] == '\0')
        {
            printf("\n");
            break;
        }
        if (s2[i] == 'r')
        {
            lowRx2++; 
        }
        else if (s1[i] == 'R')
        {
            countx2++;
        }
        printf("%c", s2[i]);
    }

    avgNum = (lowRx1 + lowRx2) / 2; //used to get avg r's

    if (countx1 < countx2) //checks to see which is longest string for later in avgLength
    {
        largerNum = countx2;
    }
    else {
        largerNum = countx1;
    }
    avgLength = (countx1 + countx2) / largerNum; //used to get avg length of string
    //printf("\n\nLength: %0.5f\n\n", avgLength);
    printf("%0.0f %0.0f %0.1f %0.5f\n", lowRx1, lowRx2,avgNum, avgLength); 
}
/******************************************************************************/
void fcfs(char *s1, char *s2, int x1, int y1, int z1,
                                            int x2, int y2, int z2) {
   int i;                                   /* next string position (time) */
   int state1 = READY;                            /* start with both ready */
   int state2 = READY;
   int cpuLeft1 = x1;                       /* P1 next CPU burst remaining */
   int cpuLeft2 = x2;                       /* P2 next CPU burst remaining */
   int ioLeft1 = y1;        /* P1 next IO burst remaining, 0 if no more IO */
   int ioLeft2 = y2;        /* P2 next IO burst remaining, 0 if no more IO */

   for (i=0; (state1 != DONE) || (state2 != DONE); i++) {
                                /* running process completes its CPU burst */
      if ((state1 == RUNNING) && (cpuLeft1 == 0)) {
         if (ioLeft1 == 0) {
            state1 = DONE;
            s1[i] = stateChars[state1];            /* terminate the string */
         }
         else
            state1 = WAITING;
      }
      else if ((state2 == RUNNING) && (cpuLeft2 == 0) ) {
         if (ioLeft2 == 0) {
            state2 = DONE;
            s2[i] = stateChars[state2];            /* terminate the string */
         }
         else
            state2 = WAITING;
      }
     
                                                     /* handle IO complete */
      if ((state1 == WAITING) && (ioLeft1 == 0)) { 
          state1 = READY;
          cpuLeft1 = z1;
      }  
      //used to check if io if done. If so then state will be made READY
      if ((state2 == WAITING) && (ioLeft2 == 0)) { 
          state2 = READY; 
          cpuLeft2 = z2;
          //...
      }  
                                    /* if both ready, depends on algorithm */
        //***********FOR fcfs starts with state1****************/
      if ( (state1 == READY) && (state2 == READY)) {
          state1 = RUNNING; 
      }  
                                     /* handle one ready and CPU available */
      else if ( (state1 == READY) && (state2 != RUNNING)) {
         state1 = RUNNING;
      }  
      else if ( (state2 == READY) && (state1 != RUNNING)) { //same as state1 above
        state2 = RUNNING; //starts running cpu burst for state2
        // ...
      }  
        /* insert chars in string, but avoid putting in extra string terminators */
      if (state1 != DONE)
         s1[i] = stateChars[state1];
      if (state2 != DONE)
         s2[i] = stateChars[state2];
                                                        /* decrement counts */
      if (state1 == RUNNING)
         cpuLeft1--;
      if (state1 == WAITING)
         ioLeft1--;
      if (state2 == RUNNING)
         cpuLeft2--;
      if (state2 == WAITING)
         ioLeft2--;
   }    

  /* end of main for loop */
}

/******************************************************************************/
void sjf (char *s1, char *s2, int x1, int y1, int z1, int x2, int y2, int z2)
{
      int i;                                   /* next string position (time) */
   int state1 = READY;                            /* start with both ready */
   int state2 = READY;
   int cpuLeft1 = x1;                       /* P1 next CPU burst remaining */
   int cpuLeft2 = x2;                       /* P2 next CPU burst remaining */
   int ioLeft1 = y1;        /* P1 next IO burst remaining, 0 if no more IO */
   int ioLeft2 = y2;        /* P2 next IO burst remaining, 0 if no more IO */

   for (i=0; (state1 != DONE) || (state2 != DONE); i++) {
                                /* running process completes its CPU burst */
      if ((state1 == RUNNING) && (cpuLeft1 == 0)) {
         if (ioLeft1 == 0) {
            state1 = DONE;
            s1[i] = stateChars[state1];            /* terminate the string */
         }
         else
            state1 = WAITING;
      }
      else if ((state2 == RUNNING) && (cpuLeft2 == 0) ) {
         if (ioLeft2 == 0) {
            state2 = DONE;
            s2[i] = stateChars[state2];            /* terminate the string */
         }
         else
            state2 = WAITING;
      }
                                                     /* handle IO complete */
      if ((state1 == WAITING) && (ioLeft1 == 0)) {
          state1 = READY;
          cpuLeft1 = z1;
      }  
      if ((state2 == WAITING) && (ioLeft2 == 0)) {
          state2 = READY;
          cpuLeft2 = z2;
          //...
      }  
                                    /* if both ready, depends on algorithm */
        if ( (state1 == READY) && (state2 == READY))
        {  
            if ((cpuLeft1 <= cpuLeft2)) { //checks to see which state will run first. Goes with shortest process 
                state1 = RUNNING; 
            } 
            else { 
                state2 = RUNNING; 
            }
        }   
                                     /* handle one ready and CPU available */
      else if ( (state1 == READY) && (state2 != RUNNING)) {
         state1 = RUNNING;
      }  
      else if ( (state2 == READY) && (state1 != RUNNING)) {
        state2 = RUNNING;
        // ...
      }  
   /* insert chars in string, but avoid putting in extra string terminators */
      if (state1 != DONE)
         s1[i] = stateChars[state1];
      if (state2 != DONE)
         s2[i] = stateChars[state2];
                                                        /* decrement counts */
      if (state1 == RUNNING)
         cpuLeft1--;
      if (state1 == WAITING)
         ioLeft1--;
      if (state2 == RUNNING)
         cpuLeft2--;
      if (state2 == WAITING)
         ioLeft2--;
   }         

}

/******************************************************************************/
void psjf (char *s1, char *s2, int x1, int y1, int z1, int x2, int y2, int z2)
{
    int i;                                   /* next string position (time) */
   int state1 = READY;                            /* start with both ready */
   int state2 = READY;
   int cpuLeft1 = x1;                       /* P1 next CPU burst remaining */
   int cpuLeft2 = x2;                       /* P2 next CPU burst remaining */
   int ioLeft1 = y1;        /* P1 next IO burst remaining, 0 if no more IO */
   int ioLeft2 = y2;        /* P2 next IO burst remaining, 0 if no more IO */

   for (i=0; (state1 != DONE) || (state2 != DONE); i++) {
                                /* running process completes its CPU burst */
      if ((state1 == RUNNING) && (cpuLeft1 == 0)) {
         if (ioLeft1 == 0) {
            state1 = DONE;
            s1[i] = stateChars[state1];            /* terminate the string */
         }
         else
            state1 = WAITING;
      }
      else if ((state2 == RUNNING) && (cpuLeft2 == 0) ) {
         if (ioLeft2 == 0) {
            state2 = DONE;
            s2[i] = stateChars[state2];            /* terminate the string */
         }
         else
            state2 = WAITING;
      }
                                                     /* handle IO complete */
      if ((state1 == WAITING) && (ioLeft1 == 0)) {
          state1 = READY;
          cpuLeft1 = z1;
      }  
      if ((state2 == WAITING) && (ioLeft2 == 0)) {
          state2 = READY;
          cpuLeft2 = z2;
          //...
      }  
                                    /* if both ready, depends on algorithm */
      if ( (state1 == READY) && (state2 == READY)) {
          if ((cpuLeft1 <= cpuLeft2)) { //think of second part since it needed to finish lowest cpu first then go to second cpu
            state1 = RUNNING; 
            state2 = READY;
         } 
         else { //first two checks for first cpu burst before io burst
            state2 = RUNNING; 
            state1 = READY;
         }   
         
      }  
                                     /* handle one ready and CPU available */
      else if ( (state1 == READY) && (state2 != RUNNING)) {
         state1 = RUNNING;
      }  
      else if ( (state2 == READY) && (state1 != RUNNING)) {
        state2 = RUNNING;
        // ...
      }  
   /* insert chars in string, but avoid putting in extra string terminators */
      if (state1 != DONE)
         s1[i] = stateChars[state1];
      if (state2 != DONE)
         s2[i] = stateChars[state2];
                                                        /* decrement counts */
      if (state1 == RUNNING)
         cpuLeft1--;
      if (state1 == WAITING)
         ioLeft1--;
      if (state2 == RUNNING)
         cpuLeft2--;
      if (state2 == WAITING)
         ioLeft2--;
   }         

}

/******************************************************************************/
void rr (char *s1, char *s2,int quantum, int x1, int y1, int z1, int x2, int y2, int z2)
{
   int i;                                   /* next string position (time) */
   int state1 = READY;                            /* start with both ready */
   int state2 = READY;
   int cpuLeft1 = x1;                       /* P1 next CPU burst remaining */
   int cpuLeft2 = x2;                       /* P2 next CPU burst remaining */
   int ioLeft1 = y1;        /* P1 next IO burst remaining, 0 if no more IO */
   int ioLeft2 = y2;        /* P2 next IO burst remaining, 0 if no more IO */
   int qleft = quantum;

   for (i=0; (state1 != DONE) || (state2 != DONE); i++) {
      
      /************************************************************************/
                                /* running process completes its CPU burst */
      if ((state1 == RUNNING) && (cpuLeft1 == 0)) {
         if (ioLeft1 == 0) {
            state1 = DONE;
            s1[i] = stateChars[state1];            /* terminate the string */
         }
         else
            state1 = WAITING;
      }
      else if ((state2 == RUNNING) && (cpuLeft2 == 0) ) {
         if (ioLeft2 == 0) {
            state2 = DONE;
            s2[i] = stateChars[state2];            /* terminate the string */
         }
         else
            state2 = WAITING;
      }
      /**********************ISSUE HAS TO BE HERE************************/
                                     /* running process has quantum expire */
      if ((state1 == RUNNING) && (qleft == 0) ) { //INPUT CODE JP
         state1 = READY; //changes state1 to READY after quantum has completed its countdown
         if (cpuLeft2 > 0) //if the state2 still isn't complete then it runs state2
         {
            state2 = RUNNING; //JP
            qleft = quantum; //resets quantum
         }
      }  
      if ((state2 == RUNNING) && (qleft == 0) ) { //same as above
         state2 = READY;
         if (cpuLeft1 > 0)
         {
            state1 = RUNNING; //JP
            qleft = quantum;
         }
      }  

      /************************************************************************/
                                                      /* handle IO complete */
      if ((state1 == WAITING) && (ioLeft1 == 0)) {
          state1 = READY;
          cpuLeft1 = z1;
      }  
      if ((state2 == WAITING) && (ioLeft2 == 0)) {//INPUT CODE JP...same as above
          state2 = READY; //similar to fcfs only with quantum involved this time
          cpuLeft2 = z2;
          //...
      }  
      /************************************************************************/
                                      /* if both ready, depends on algorithm */
      if ( (state1 == READY) && (state2 == READY)) { //INPUT CODE JP
            state1 = RUNNING; 
            qleft = quantum; 
      }  
                                     /* handle one ready and CPU available */
      else if ( (state1 == READY) && (state2 != RUNNING)) {
         state1 = RUNNING;
         qleft = quantum;
      }  
      else if ( (state2 == READY) && (state1 != RUNNING)) { //INPUT CODE JP..same as above
         state2 = RUNNING;
         qleft = quantum;
      }

      /************************************************************************/
   /* insert chars in string, but avoid putting in extra string terminators */
      if (state1 != DONE)
         s1[i] = stateChars[state1];
      if (state2 != DONE)
         s2[i] = stateChars[state2];
                                                        /* decrement counts */
      qleft--;                   /* OK to decrement even if nothing running */
      if (state1 == RUNNING)
         cpuLeft1--;
      if (state1 == WAITING)
         ioLeft1--;
      if (state2 == RUNNING)
         cpuLeft2--;
      if (state2 == WAITING)
         ioLeft2--;
   }                                               /* end of main for loop */

}



