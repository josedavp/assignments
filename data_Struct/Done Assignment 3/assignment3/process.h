#ifndef _process_h
#define _process_h

typedef enum priority { FOREGROUND, BACKGROUND } priority;

typedef struct processData
{
    char name[21];
    char TLN[4];
    int heap[30];
}  processData;

/* struct process (only accessed in student written code)
 *
 * The data associated with a specific process.
 * At minimum you need to track the process name,
 * and the number of cycles process still needs to run.
 *
 * Hint: It may help to store how many time steps happened before
 * a process was added to the schedule.
 */
typedef struct process
{
    //TODO: Put the data for your process here!
     char* processName; //name of the process
    int runtime; // run cycles required to complete process
    processData* data; // data
    enum priority pri; //priority  
    int arrivalTime; // to track 0 - 50 timesteps when it arrives current - arrival
    int continuousRun; // constant, various 0-5
    
}  process;

#endif
