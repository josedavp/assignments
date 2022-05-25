#include <stdio.h>

int main (int argc, char* argv[]) 
{
    FILE* infile = fopen(argv[1], "rb+");
    FILE* outfile = fopen(argv[2], "wb+");
    
    int pageTable[] = {2,4,1,7,3,5,6};
    int pageNum = 0;
    unsigned long VA, PA;
    unsigned long page_Size, frame_Num, offSet; 



    if (infile == NULL) 
    {
        printf("Error: File could not be opened");
        return -1;
    }

    while(fread(&VA, sizeof(unsigned long), 1 , infile) == 1) 
    { 
        pageNum = VA >> 7;
        offSet = VA & 127;
        //pageNum = VA << 7;// maybe pagNum first then offset
        PA = (pageTable[pageNum] << 7) | offSet;

        fwrite(&PA, sizeof(unsigned long), 1 , outfile);// write but with different values
        //pageNum++;
    }
    printf("\nPage count %d\n", pageNum);

    fclose(infile);
    fclose(outfile);

    return 0;
}