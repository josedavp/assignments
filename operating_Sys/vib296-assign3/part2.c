#include <stdio.h>
#include "pagetable.h"

/*
    This is the new main program
*/


/*ONLY NEED 2 FUNCTIONS MAYBE? AND A COUNT SYSTEM */ 
int main (int argc, char* argv[]) 
{
    unsigned long VA, PA;
    unsigned long frameNum; 
    unsigned long pageSize = 0;//this is meant for page size
    int currentTime = 0; //used for LRU
    int pagefaultCount = 0; //counts for pages faults
    int i;
    
    FILE* infile = fopen(argv[1], "rb+");
    FILE* outfile = fopen(argv[2], "wb+");

    if (infile == NULL) 
    {
        printf("Error file could not be opened");
        return -1;
    }
    //v in memory i not-in memory
    /********POPULATE PAGETABLE FIRST************/
    int virtualPageTableSize = 32;
    int physicalPageTableSize = 8;

    PTE virtualPageTable[virtualPageTableSize];
    PTE physicalPageTable[physicalPageTableSize];

    for(i = 0; i < virtualPageTableSize; i++)
    {
        virtualPageTable[i].validBit = 0;
        virtualPageTable[i].pagefaultcnt = 0;
    }
    for (i = 0; i < physicalPageTableSize; i++)
    {
        physicalPageTable[i].validBit = 0;
        physicalPageTable[i].pagefaultcnt = 0;
    }

    /**********************************/
  


    while (fread(&VA, sizeof(unsigned long), 1, infile))
    {
        managePagetable(currentTime,physicalPageTable,physicalPageTableSize, virtualPageTable, virtualPageTableSize, outfile, VA, pageSize, PA); //right? counter would be initialized outside while loop to prevent counter from resetting as it loops through infile
        currentTime++; 
    }
    
    return 0;
}