#include <stdlib.h>

#include "multilevelQueueScheduler.h"

/* createSchedule
 * input: none
 * output: a schedule
 *
 * Creates and return a schedule struct.
 */
schedule* createSchedule( )
{
    /* TODO: initialize data in schedule */
    schedule* newSchedule = (schedule*)malloc(sizeof(schedule));
    newSchedule->backgroundQ = createQueue(newSchedule);
    newSchedule->foregroundQ = createQueue(newSchedule);
    newSchedule->clock = 0;

    return newSchedule; /* TODO: Replace with your return value */
}
/*******************************************************************************/
/* isScheduleUnfinished
 * input: a schedule
 * output: bool (true or false)
 *
 * Check if there are any processes still in the queues.
 * Return TRUE if there is.  Otherwise false.
 */
bool isScheduleUnfinished( schedule *ps )
{
    /* TODO: check if there are any process still in a queue.  Return TRUE if there is. */
  if(!isEmpty(ps->foregroundQ) || !isEmpty(ps->backgroundQ) ) 
   {  
       return true;// or 0 means FALSE and 1 means TRUE
   }
  else
  {
     return false; 
  }
}
/*******************************************************************************/
/* addNewProcessToSchedule
 * input: a schedule, a string, an int, a priority
 * output: void
 *
 * Create a new process with the provided name, runtime, and priority.
 * Add that process to the appropriate queue
 */
void addNewProcessToSchedule( schedule *ps, char *processName, int runtime, priority p ) 
{ //may be because free function isnt make just yet
    /* TODO: complete this function.
    The functions "initializeProcessData" in processSimulator.c will be useful in completing this. */
    processData* newProcessData= initializeProcessData(processName);
    ps->clock++;
    process* newProcess = (process *)malloc (sizeof(process));
    
    /********************Assigning variables into new process*****************************/
    newProcess->data = newProcessData;
    newProcess->processName = processName;
    newProcess->runtime = runtime;
    newProcess->pri = p;   
    newProcess->continuousRun = 0;
    newProcess->arrivalTime = 0;
    //printf("This is arrival Time: %p\n", newProcess->arrivalTime);
   /*************Checks if its FOREGROUND OR BACKGROUND*************/
    if (p == 0)
    {
        enqueue(ps->foregroundQ, newProcess);  
    }
    else 
    {
        newProcess->arrivalTime = ps->clock;
        enqueue(ps->backgroundQ, newProcess);
    }
}

/*******************************************************************************/
/* simulateNextTimeStep
 * input: a schedule
 * output: a string
 *
 * Use the schedule to determine the next process to run.
 * If process being run starts a new process it will return a string.
 * This function should just return this string.
 */
char* simulateNextTimeStep( schedule *ps ) // not getting promoted and if in foreground with background isnt promoting or being read. 
{ // the arrival time isnt updating in foreground. and is only updating in background else
    /* TODO: complete this function.
    The function "runProcessForOneTimeStep", "promoteProcess", and "freeProcessData"
    in processSimulator.c will be useful in completing this. */
    
    process* foregroundP = getNext(ps-> foregroundQ);
    process* backgroundP = getNext(ps->backgroundQ);
    process* temp, *temp2;
    char* ret;
    //ps->clock++; causes seg fault here if you combine it with backgroundP
     //backgroundP->arrivalTime = ps->clock; causes seg fault here
    /*****************************this one handles foreground******************************/
    if(!isEmpty(ps->foregroundQ)) 
    {    
        ret = runProcessForOneTimeStep(foregroundP->processName, foregroundP->data);
        foregroundP->continuousRun++;
        foregroundP->runtime--;
        ps->clock++;
         /**********Checks background process while in foreground for promotion********/    
       // printf("This is arrival time: %d # Process Name: %s\n", backgroundP->arrivalTime, backgroundP->processName);
       // printf("\n");
        if( ps->clock - backgroundP->arrivalTime >= 50 ) //meant to do subtract and equal 50 when its time
        {
         //   printf("promote FG\n");
            promoteProcess(backgroundP->processName, backgroundP->data);
            temp = dequeue(ps->backgroundQ);           
            enqueue(ps->foregroundQ, temp);    
        }
        /********************************************************************************/
        if (foregroundP->runtime <= 0) // less than 0 it ends and frees
        {
            temp2 = dequeue(ps->foregroundQ);
            freeProcessData(temp2->data);
            free(temp2->processName);
            free(temp2);
            return ret; 
        } 
        
        if (foregroundP->continuousRun == 5) // run time 0-5 then enqueues
        {
            temp2 = dequeue(ps->foregroundQ);
            temp2->continuousRun = 0;
            enqueue(ps->foregroundQ, temp2);
        }
        
        return ret;
    }
    
    /***********************this one handles background********************/
    else 
    {   
        ret = runProcessForOneTimeStep(backgroundP->processName, backgroundP->data);
        ps->clock++;
        backgroundP->runtime--;
        backgroundP->arrivalTime++;
        //ps->clock++; 
        
       if (backgroundP->runtime <= 0) //checks if runtime becomes zero
       {
            temp = dequeue(ps->backgroundQ);
            freeProcessData(temp->data);
            free(temp->processName);
            free(temp);
            return ret;   
        } 
        // printf("ps->clock out of if statement: %d \n", ps->clock);
         //printf("\n");
         
         /**********Checks background process for promotion********/    
        if ((ps->clock - backgroundP->arrivalTime) >= 50 ) 
        {
        //    printf("Promote BG\n");
            promoteProcess(backgroundP->processName, backgroundP->data);
            temp = dequeue(ps->backgroundQ);
            
            enqueue(ps->foregroundQ, temp);        
        } 
         
        //return ret;
    }

    return ret; /* TODO: Replace with your return value */
}

/*******************************************************************************/
/* freeSchedule
 * input: a schedule
 * output: none
 *
 * Free all of the memory associated with the schedule.
 */
void freeSchedule( schedule *ps ) 
{
    /* TODO: free any data associated with the schedule.
    the function "freeQueue" in queue.c will be useful in completing this.
    You may also want to call "freeProcessData" for any processes still left in your queues */   
    process* final;
    
    /*******************checks if foreground is empty/frees then dequeues after*************************/
    while (!isEmpty(ps->foregroundQ)) 
    {
        final = dequeue(ps->foregroundQ);
        freeProcessData(final->data);
        free(final->processName);
        free(final);
    }
    
    freeQueue(ps->foregroundQ);
    
    /******************checks if background is empty/frees then dequeues and frees schedule*************/
    while (!isEmpty(ps->backgroundQ))
    {
        final = dequeue(ps->backgroundQ);
        freeProcessData(final->data);
        free(final->processName);
        free(final);
    }
    
    freeQueue(ps->backgroundQ);
    free(ps); //frees schedule
         
}
