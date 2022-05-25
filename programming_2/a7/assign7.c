#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "assign7.h"

#define COURSE_FILE "courses.dat"
#define MAX 100

//void searchCourse(FILE* ptrCourseFile);

int main(int argc, char* argv[])
{
    printf("Enter one of the following actions or press CTRL-D to exit\n");
    printf("C - create a new course record\n");
    printf("U - update an existing course record\n");
    printf("R - read an existing course record\n");
    printf("D - delete an existing course record\n");
//    printf("F - searching course records\n");
    printf("\n");

/*******************************/
    
    FILE* ptrCourseFile;

    ptrCourseFile = fopen(COURSE_FILE, "rb+"); 
    
    if (ptrCourseFile == NULL) {
        printf("Could not find file");
        return -1;
    }

    char letter;
    char inputBuffer[MAX];

    while (fgets(inputBuffer, 100, stdin))  {
        
        sscanf(inputBuffer,"%c", &letter); 
     //   fseek( 
        printf("\n%c\n", letter);

        if (letter == 'C' || letter == 'c')
        {
            createCourse(ptrCourseFile);
        }
        else if (letter == 'U' || letter == 'u')
        {
            updateCourse(ptrCourseFile);
        }
        else if (letter == 'R' || letter == 'r') 
        {
            readCourse(ptrCourseFile);
        }
        else if (letter == 'D' || letter == 'd')
        {
            deleteCourse(ptrCourseFile);
        }
  //      else if (letter == 'F' || letter == 'f')
  //      {
  //          searchCourse(ptrCourseFile);
 //       }
        else {
            printf("ERROR: invalid option\n");
            return -1;
        }
    } 
    fclose(ptrCourseFile);
    
    return 0;
    
}
/*******************************/
    void createCourse(FILE *ptrCourseFile)
    {
        char inputBuffer[MAX];
        int iCourseNum;
        int iScanCount; //ADDED POINTER

        COURSE courseNew;
        COURSE courseRead;

        // CREATES FILE
        printf("Enter Course Number: ");
        fgets(inputBuffer, MAX, stdin);
        iScanCount = sscanf(inputBuffer, "%d", &iCourseNum);
        printf("%d\n", iCourseNum);

        //USED TO CHECK IF FILE EXISTS OR NOT
        if( fseek(ptrCourseFile, iCourseNum * sizeof(COURSE), SEEK_SET) != -1) {
            if(fread(&courseNew, sizeof(COURSE), 1L, ptrCourseFile) == 1) {

                fseek(ptrCourseFile, iCourseNum * sizeof(COURSE), SEEK_SET); 

                printf("Enter Course Name: ");
                //fread(&courseNew.course_Name, sizeof(COURSE), 1L, stdin);
                
                /******************************************/
                fgets(inputBuffer, MAX, stdin);
                sscanf(inputBuffer, "%[^\t\n]", courseNew.course_Name);
                printf("%s\n", courseNew.course_Name);
                /******************************************/
                
                printf("Enter Course Schedule{MWF, TR}: ");
                //fread(&courseNew.course_Sched, sizeof(COURSE), 1L, stdin); 
                
                /******************************************/
                fgets(inputBuffer, MAX, stdin);
                sscanf(inputBuffer, "%s", courseNew.course_Sched);
                printf("%s\n", courseNew.course_Sched);
                /******************************************/
               
                printf("Enter Course Hours: ");
                //fread(&courseNew.course_Hours, sizeof(COURSE), 1L, stdin);
                
                /******************************************/
                fgets(inputBuffer, MAX, stdin);
                sscanf(inputBuffer, "%d", &courseNew.course_Hours);
                printf("%d\n", courseNew.course_Hours);
                /******************************************/
               
                printf("Enter Course Size: ");
                //fread(&courseNew.course_Size, sizeof(COURSE), 1L, stdin);

                /******************************************/
                fgets(inputBuffer, MAX, stdin);
                sscanf(inputBuffer, "%d", &courseNew.course_Size);
                printf("%d\n", courseNew.course_Size);
                /******************************************/
                
                if (courseRead.course_Hours > 0 ) {
                    printf("ERROR: course already exists\n");    
                }
                fwrite(&courseNew, sizeof(COURSE), 1L , ptrCourseFile);
               // printf("\n");
            }
        }
    }

/******************************/
    void updateCourse(FILE *ptrCourseFile)
    {
        char inputBuffer[MAX];
        
        int iCourseNum;
        int iScanCount; 

        char* tempName, tempSched;
        int tempHours, tempSize;

    
        COURSE courseCurrent;
        COURSE courseUpdate;

        printf("Enter Course Number: ");
        
        fgets(inputBuffer, MAX, stdin);
        iScanCount = sscanf(inputBuffer, "%d", &iCourseNum);
       
        printf("%d\n", iCourseNum);
        /***********MEANT TO STORE ORIGINAL COURSE DATA*******************/
        if (fseek(ptrCourseFile, iCourseNum * sizeof(COURSE), SEEK_SET) != -1) {
            fread(&courseCurrent, sizeof(COURSE), 1L, ptrCourseFile);
        }
        /******************************/

        if( fseek(ptrCourseFile, iCourseNum * sizeof(COURSE), SEEK_SET) != -1) {
            if(fread(&courseCurrent, sizeof(COURSE), 1L, ptrCourseFile) == 1) {
                    
                //prompt and update if needed
                    
                fseek(ptrCourseFile, iCourseNum * sizeof(COURSE), SEEK_SET); 
                    
                printf("Enter Course Name: \n");
        
                fgets(inputBuffer, MAX, stdin);
                sscanf(inputBuffer, "%[^\t\n]", tempName);
                
                if (iScanCount == 1) {
                    printf("%s", tempName);
                    strcpy(courseUpdate.course_Name,tempName);
                }
                printf("Enter Course Schedule{MWF, TR}: \n");

                fgets(inputBuffer, MAX, stdin);
                iScanCount = sscanf(inputBuffer, "%s", &tempSched);

                if (iScanCount == 1) {
                    printf("%s", &tempSched);
                    strcpy(courseUpdate.course_Sched, &tempSched);//CORRECT?
                }

                printf("Enter Course Hours: \n");
        
                fgets(inputBuffer, MAX, stdin);
                iScanCount = sscanf(inputBuffer, "%d", &tempHours);

                if (iScanCount == 1) {
                    printf("%d", tempHours);
                    courseUpdate.course_Hours = tempHours;
                }   

                printf("Enter Course Enrollment: \n");

                fgets(inputBuffer, MAX, stdin);
                iScanCount = sscanf(inputBuffer, "%d", &tempSize);

                if (iScanCount == 1) {
                    printf("%d", tempSize);
                    courseUpdate.course_Size = tempSize;
                }
                if (courseCurrent.course_Hours > 0 ) {
                    printf("ERROR: course already exists\n");     
                }
                fwrite(&courseUpdate, sizeof(COURSE), 1L, ptrCourseFile);
            }
        }
    }
/*****************************************/
    void readCourse(FILE *ptrCourseFile)
    {
        char inputBuffer[MAX];
        int iScanCount;
        int readCount;
        int iCourseNum;

        COURSE courseRead;

        printf("Enter a CS course number: ");
        fgets(inputBuffer, MAX, stdin);
        sscanf(inputBuffer, "%d", &iCourseNum);
      
        printf("%d\n", iCourseNum);
        
        //searches for the course location 
        fseek(ptrCourseFile, iCourseNum * sizeof(COURSE), SEEK_SET);
        fread(&courseRead,sizeof(COURSE), 1L, ptrCourseFile);
        
        printf("Course number: %d\n", iCourseNum);
        printf("Course name: %s\n", courseRead.course_Name);
        printf("Scheduled days: %s\n", courseRead.course_Sched);
        printf("Credit hours: %d\n", courseRead.course_Hours);
        printf("Enrolled Students: %d\n", courseRead.course_Size);
        
        if (courseRead.course_Hours == 0) {
            printf("ERROR: course not found\n");
        }
    }

    void deleteCourse(FILE *ptrCourseFile)
    {
        char inputBuffer[MAX]; 
        int iCourseNum;
        COURSE courseDelete;

        printf("Enter a CS course number: ");

        fgets(inputBuffer, MAX, stdin);
        sscanf(inputBuffer, "%d", &iCourseNum);
        
        printf("%d\n", iCourseNum);
        
        if (courseDelete.course_Hours > 0 ) {
            fseek(ptrCourseFile, iCourseNum * sizeof(COURSE), SEEK_SET);
                    
            courseDelete.course_Hours = 0;
            printf("%d was successfully deleted\n", iCourseNum);
            fwrite(&courseDelete.course_Hours, sizeof(COURSE), 1L, ptrCourseFile);
        }
        else {
            printf("ERROR: course not found\n");
        }
    }
    
   /* void searchCourse(FILE *ptrCourseFile) 
    {
        char inputBuffer[MAX];
        int iCourseNum;
        char* passPhrase;

        COURSE courseSearch;

        printf("Enter a search phrase: ");

        fgets(inputBuffer, MAX, stdin);
        sscanf(inputBuffer, "%[^\t\n]", passPhrase);
        
        printf("%s\n", passPhrase);
        
        fseek(ptrCourseFile, sizeof(COURSE), SEEK_SET);
      
        while(fseek(ptrCourseFile, sizeof(COURSE), SEEK_SET) != -1) {
            if(courseSearch.course_Hours > 0) {
                fseek(ptrCourseFile, sizeof(COURSE), SEEK_SET);
                fread(&courseSearch, sizeof(COURSE), 1L, ptrCourseFile);

                if (strcasecmp(courseSearch.course_Name, passPhrase)) {
                    printf("%d: \"%s\"", courseSearch.course_Hours, passPhrase);
                }
                if (strcasecmp(courseSearch.course_Sched, passPhrase)) {
                    printf("%d: \"%s\"", courseSearch.course_Hours, passPhrase);
                }
            }
        }
    }*/
