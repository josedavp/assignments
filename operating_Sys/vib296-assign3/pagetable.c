#include <stdio.h>
#include "pagetable.h"
/*
    This will manage the page table for the process
*/

/*FUNCTION 1 HERE */ 

void managePagetable(int currentTime, PTE physicalPageTable[],int physicalPageTableSize, PTE virtualPageTable[],int virtualPageTableSize, FILE* outfile, unsigned long VA,int pageNum, unsigned long PA)
{
    unsigned long offSet;
    int i;
   

    pageNum = VA >> 7;
    offSet = VA & 127;
    
    int indexOfReplacePage = 0;

    if(virtualPageTable[pageNum].validBit == 0) { //page fault occurred //check your virtual
        virtualPageTable[pageNum].pagefaultcnt++; //if it occurs increase fault count
       
        for (i = 1; i < physicalPageTableSize; i++) //find physical page 
        {   //check if their are free frames
            if (physicalPageTable[i].validBit == 0) 
            {
                indexOfReplacePage = i; 
                break;
            }
             //if not find the LRU page and replace it
            int deltaTimeCurrent = currentTime - physicalPageTable[i].timeLastUsed;
            int deltaTimeOfOldestPage = currentTime - physicalPageTable[indexOfReplacePage].timeLastUsed; 
            if (deltaTimeCurrent > deltaTimeOfOldestPage) 
            {
                    indexOfReplacePage = i;
            }
        }
        //invalidate virtual page reference
        virtualPageTable[pageNum].validBit = 0;
        
    }
    else { //page fault did not occur
       
        //NOTHING IS NEEDED HERE

    }
    //update physical page table
    physicalPageTable[indexOfReplacePage].validBit = 1;
    physicalPageTable[indexOfReplacePage].timeLastUsed = currentTime;
    //update virtual page table
    virtualPageTable[pageNum].validBit = 1;
    virtualPageTable[pageNum].frameNum = indexOfReplacePage;
    
    PA = (indexOfReplacePage << 7) | offSet; //not 7?

    fwrite(&PA, sizeof(unsigned long), 1 , outfile);

}