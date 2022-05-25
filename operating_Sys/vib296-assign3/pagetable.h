#ifndef PAGETABLE_H_
#define PAGETABLE_H_
/*
    This will manage the page table for the process
*/
typedef struct
{
    int pagefaultcnt;
    int validBit;
    unsigned long frameNum;
    int timeLastUsed;

} PTE; //VIRTUAL TABLE

void managePagetable(int currentTime, PTE physicalPageTable[],int physicalPageTableSize, PTE virtualPageTable[],int virtualPageTableSize, FILE* outfile, unsigned long VA,int pageNum, unsigned long PA);

#endif