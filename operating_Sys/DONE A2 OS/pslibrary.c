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

void displayPrint(char *s1, char *s2, int size){
    float lowRx1 = 0;
    float lowRx2 = 0;
    float avgLength = 0;
    int countx1 = 0;
    int countx2 = 0;
    int totalx1 = 0;
    int totalx2 = 0;
    int largerNum;
    int i;
    float avgNum = 0;
    for (i = 0; i < size; i++)
    {
        if (s1[i] == '\0')
        {
            totalx1 = i--;
            printf("\n");
            break;
        }
        if (s1[i] == 'r')
        {
            lowRx1++;
        }
        else if (s1[i] == 'R')
        {
            countx1++;
        }
        printf("%c", s1[i]);
    }
    for(i = 0; i < size; i++)
    {
        if(s2[i] == '\0')
        {
            totalx2 = i--;
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
    avgNum = (lowRx1 + lowRx2) / 2;
    if (countx1 < countx2)
    {
        largerNum = countx2;
    }
    else {
        largerNum = countx1;
    }
    avgLength = (countx1 + countx2) / largerNum;
    //printf("\n\nLength: %0.5f\n\n", avgLength);
    printf("%0.0f %0.0f %0.1f %0.5f\n", lowRx1, lowRx2,avgNum, avgLength); 
}

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
      if ((state2 == WAITING) && (ioLeft2 == 0)) {
          state2 = READY;
          cpuLeft2 = z2;
          //...
      }  
                                    /* if both ready, depends on algorithm */
      if ( (state1 == READY) && (state2 == READY)) {
          state1 = RUNNING; // only this?
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

  /* end of main for loop */
}
//6 3 4
//5 2 3

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

                                  

                                     /* handle one ready and CPU available */
      else if ( (state1 == READY) && (state2 != RUNNING)) {
         state1 = RUNNING;
        // qleft = quantum;
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
            state2 = RUNNING; // only this?
            state1 = READY;
         }   
        /* if ((cpuLeft1 < cpuLeft2) && (ioLeft1 == 0)) {  // second two checks for cpu bursts after io bursts so shortest goes first
            state1 = RUNNING; 
         } 
         if ((cpuLeft2 < cpuLeft1) && (ioLeft2 == 0)) { 
            state2 = RUNNING; // only this?
         }   */
         
      }  
                                     /* handle one ready and CPU available */
      else if ( (state1 == READY) && (state2 != RUNNING)) {
         state1 = RUNNING;
        // qleft = quantum;
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
         state1 = READY;
         //state2= READY; //NOT 100% sure
         if (cpuLeft2 > 0)
         {
            state2 = RUNNING; //JP
            qleft = quantum;
         }
      }  
      if ((state2 == RUNNING) && (qleft == 0) ) { //INPUT CODE JP
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
      if ((state2 == WAITING) && (ioLeft2 == 0)) {//INPUT CODE JP
          state2 = READY;
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
      else if ( (state2 == READY) && (state1 != RUNNING)) { //INPUT CODE JP
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



