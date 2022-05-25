/* 
    schedule.c
    Project 2
    Jose D. Pague

    This file contains all the schedule functions.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "schedule.h"

/* 
    printMenu
    ---------------------------
    This function prints the main menu.
    Returns: Nothing
*/
void printMenu()
{
    printf( "\n#########################################\n" );
    printf( "\tSchedule Program Menu\n" );
    printf( "#########################################\n" );
	printf( "1) Find a Course by CRN\n" );
	printf( "2) Find Courses by Course Number\n" );
	printf( "3) Find Courses by Days\n" );
	printf( "4) Find Courses by Instructor\n" );
	printf( "5) Print All Courses\n" );
	printf( "6) Compute stats\n");
	printf( "0) Quit\n" );
	printf( "Enter your choice: " );
}

/*******************************************************/
/*******************************************************/

/* 
    printCourseRecord
    ---------------------------
   	This function prints only the subject, course number, section number (all three characters must be shown), title, instructor name in the CourseRecord's data members in one row with formatted in columns
   		CourseRecord a - The record you are printing
    Returns: Nothing
*/
void printCourseRecord( CourseRecord c )
{
	printf( "%-4s%-4d.%3s (%d): %-30s\t%-15s\t%s\t%d\n", c.subject, c.course, c.section, c.crn, c.title, c.instructor, c.days, c.enrolled );
}

/*******************************************************/
/*******************************************************/

/* 
    printCourseInformation
    ---------------------------
   	This function prints all the CourseRecord's data members on separate rows. 
   		CourseRecord a - The record you are printing
   	Returns: Nothing
*/
void printCourseInformation( CourseRecord a ) 
{
	printf( "Subj:\t%s\n", a.subject );
	printf( "Course:\t%d\n", a.course ); // could this affect program search?
	printf( "Sec:\t%3s\n", a.section );
	printf( "CRN:\t%d\n", a.crn );
	printf( "Title:\t%s\n", a.title );
	printf( "Instr:\t%s\n", a.instructor );
	printf( "Days:\t%s\n", a.days );
	printf( "Times:\t%s\n", a.times );
	printf( "Enr:\t%d\n\n", a.enrolled );
}

/******************************************************/
/*******************************************************/
/* 
    printCourses
    ---------------------------
        This function creates a for loop that uses printCourseRecord to print 
        each "course" line.
                    CourseRecord a- The total record you are printing.
        Returns: Nothing
*/
void printCourses( CourseRecord *a, int length)
{
    int i;
    for ( i = 0; i < length; i++)
    {
        printCourseRecord( a[i] );
        printf("\n");
    }
    
}

/*******************************************************/
/*******************************************************/
/* 
    getCourseCount
    ---------------------------
            This function gets the length of the array and scans it from the file.
                CourseRecord a- contains the array that will be used for printing.
            Returns: length of array.
*/
int getCourseCount( FILE *f )
{
    int count = 0;
    char buffer[ 50 ];
    char status[ 10 ]; /* OPEN OR CLOSED */ 
    char subject[ 5 ]; /* CS */
    int number;        /* 1713 */  
    char section[ 4 ]; /* 001 */
    int crn;
    char title[ 100 ];
    int credit;
    char days[ 20 ];
    char times[ 20 ];
    char campus[ 20 ];
    char location[ 20 ];
    char lastname[ 25 ];
    char firstname[ 25 ];
    char date[ 10 ];
    int weeks;
    int seats;
    int enrolled;
    char rest[ 100 ];
    int actualRecordCount = 0;
    
     while( fgets( buffer, 50, f ) != NULL )
    {
        count++;
        if( count > 13 )
        {
              sscanf( buffer, "%[^,],%[^,],%d,%[^,],%d,%[^,],%d,%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%d,%d,%d,%s", status, subject, &number, section, &crn, title, &credit, days, times, campus, location, lastname, firstname, date, &weeks, &seats, &enrolled, rest );
            /* only count the OPEN classes with more than 10 students */
            if( strcmp( status, "OPEN" ) == 0 && enrolled > 10 )
            {
                actualRecordCount++;
                /* print to make sure we are reading each row, 
                   remove for final*/
               // printf( "%s\n", buffer );
            } 
        }
    }
    rewind( f );
    return count;
}


/*******************************************************/
/*******************************************************/
/* 
    fillCourses
    ---------------------------
        This function populates the *data array using using length while 
        searching within the file.
                FILE *f- contains the file itself.
        Returns: Nothing
*/
void fillCourses( FILE *f, CourseRecord *data, int length)
{
    int count = 0;
    char buffer[ 100 ];
    char status[ 10 ]; /* OPEN OR CLOSED */ 
    char subject[ 5 ]; /* CS */
    int number;        /* 1713 */
    char section[ 4 ]; /* 001 */
    int crn;                                         // does crn need to be an array or double? 
    char title[ 100 ];
    int credit;
    char days[ 20 ];
    char times[ 20 ];
    char campus[ 20 ];
    char location[ 20 ];
    char lastname[ 25 ];
    char firstname[ 25 ];
    char date[ 10 ];
    int weeks;
    int seats;
    int enrolled;
    char rest[ 100 ];
    int i = 0;
    
    while (fgets(buffer, 100, f ) != NULL)
    {
        
        count++;
        if ( count > 13 )
        {
            sscanf( buffer, "%[^,],%[^,],%d,%[^,],%d,%[^,],%d,%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%d,%d,%d,%s", status, subject, &number, section, &crn, title, &credit, days, times, campus, location, lastname, firstname, date, &weeks, &seats, &enrolled, rest );
            
            if ( strcmp( status, "OPEN" ) == 0 && enrolled > 10 )
            {
                strcpy(data[i].subject,subject);
                data[i].course = number; // is course
                strcpy(data[i].section,section);
                data[i].crn = crn;
                strcpy(data[i].title,title);
                strcpy(data[i].days, days);
                strcpy(data[i].times, times);
                strcpy(data[i].instructor, lastname);
                data[i].enrolled = enrolled;
                i++;
            }
        }
    }
}

/*******************************************************/
/*******************************************************/


/*
    findCourses
    ---------------------------
        This function find the courses using the array given and populates 
        another array with the new length and copies information from the original array.
            CourseRecord origin- contains the original array.
            CourseRecord dest- contains the new array.
        Returns: An Array Length for the second array.
*/
int findCourses( CourseRecord *origin, CourseRecord *dest, int length, char *key1, int key2, SearchType st)
{
    int count = 0;
    int i;
    
    for ( i = 0; i < length; i++)
    {
        if ( st == COURSE ) //Course ==0 
        {
            if (origin[i].course == key2) // or else?
            {
                strcpy(dest[count].subject, origin[i].subject);
                dest[count].course = origin[i].course;
                strcpy(dest[count].section, origin[i].section);
                dest[count].crn = origin[i].crn;
                strcpy(dest[count].title, origin[i].title);
                strcpy(dest[count].days, origin[i].days);
                strcpy(dest[count].times, origin[i].times);
                strcpy(dest[count].instructor, origin[i].instructor);
                dest[count].enrolled = origin[i].enrolled;
     
                count++;
            }   
        }
        if ( st == CRN ) 
        {
            if (origin[i].crn == key2) 
            {
                strcpy(dest[count].subject, origin[i].subject);
                dest[count].course = origin[i].course;
                strcpy(dest[count].section, origin[i].section);
                dest[count].crn = origin[i].crn;
                strcpy(dest[count].title, origin[i].title);
                strcpy(dest[count].days, origin[i].days);
                strcpy(dest[count].times, origin[i].times);
                strcpy(dest[count].instructor, origin[i].instructor);
                dest[count].enrolled = origin[i].enrolled;
     
                count++;
            }   
        }
        if ( st == DAYS ) 
        {
               
            //printf("%", *(origin + i));
            if (strcmp(origin[i].days, key1) == 0 ) //THIS LINE SEGFAULTS
            {
                   
                    
                strcpy(dest[count].subject, origin[i].subject);
                dest[count].course = origin[i].course;
                strcpy(dest[count].section, origin[i].section);
                dest[count].crn = origin[i].crn;
                strcpy(dest[count].title, origin[i].title);
                strcpy(dest[count].days, origin[i].days);
                strcpy(dest[count].times, origin[i].times);
                strcpy(dest[count].instructor, origin[i].instructor);
                dest[count].enrolled = origin[i].enrolled;
     
                count++;
            }
            
        }
         if ( st == INSTRUCTOR ) 
        {
          //  printf("%", *(origin + i));
            if (strcmp(origin[i].instructor, key1) == 0 ) 
               
            {
                
                    
                strcpy(dest[count].subject, origin[i].subject);
                dest[count].course = origin[i].course;
                strcpy(dest[count].section, origin[i].section);
                dest[count].crn = origin[i].crn;
                strcpy(dest[count].title, origin[i].title);
                strcpy(dest[count].days, origin[i].days);
                strcpy(dest[count].times, origin[i].times);
                strcpy(dest[count].instructor, origin[i].instructor);
                dest[count].enrolled = origin[i].enrolled;
     
               count++;
            }
            
        }
    }
           
    return count; //is this correct? since its asking for array length
}

/*******************************************************/
/*******************************************************/


/*
    computeStats
    ---------------------------
        This function finds the total amount of courses, 
        upper, lower, and grad courses, the total enrollment, and average enrollment.
                CourseRecord a - contains the populated array.
        Returns: Nothing 
*/
void computeStats( CourseRecord *a, int length)
{
    int totalCourses = 0;
    int totalLower = 0;
    int totalUpper = 0;
    int totalGrad = 0;
    int totalEnroll = 0;
    double avgEnroll = 0;
    int i, count;
    
    
    for ( i = 0; i < length; i++)
    {
        
        if ( a[i].course >= 1000 && a[i].course <= 1999)
        {
            //count++;
            totalLower = totalLower + 1;
        }
        else if ( a[i].course >= 2000 && a[i].course <= 3999)
        {
            //count++;
            totalUpper = totalUpper + 1;
        }
        else if ( a[i].course >= 4000 && a[i].course <= 7999)
        {
            //count++;
            totalGrad = totalGrad + 1;
        }
        
        totalEnroll += a[i].enrolled;       
    }
    
    avgEnroll = (double) totalEnroll / length;
    
    totalCourses = totalCourses + totalLower + totalUpper + totalGrad;
    
    printf("Total Courses: %-5d\n", totalCourses);
    printf("Number of Lower Division Courses: %-5d\n Number of Upper Division Courses: %-5d\n", totalLower, totalUpper);
    printf("Number of Graduate Courses: %-5d\n", totalGrad);
    printf("Total Enrollment: %-5d\n Average Enrollment: %-5lf\n ", totalEnroll, avgEnroll);
        
}
 

/*******************************************************/
/*******************************************************/

/* 
    mergeSortRecords
    ---------------------------
        This function uses creates a mid "length", and uses mergeRecords to sort the data array.
                CourseRecord data- The array itself containing the information later to be sorted.
        Returns: Nothing 
*/
void mergeSortRecords( CourseRecord *data, int min, int max )
{
    int mid;
    
    if (min < max)
    {
        mid = (min + max) / 2;
        
        mergeSortRecords(data, min, mid);
        mergeSortRecords(data, mid + 1, max);
        
       mergeRecords(data, min, mid, max); // problem
    }
}
    

/*******************************************************/
/*******************************************************/

/* 
    mergeRecords
    ---------------------------
        This function contains the merge sort algorithm used to sort the array.
                CourseRecord data - The array itself used to in the algorithm.
        Returns: Nothing 
*/
void mergeRecords( CourseRecord *data, int min, int mid, int max)
{
    
    //use string compare for each array element
    int mergedSize = max - min + 1;
    CourseRecord *mergedNum;
    mergedNum = (CourseRecord *)malloc(sizeof(CourseRecord) * mergedSize);
    int mergedPos;
    int leftPos;
    int rightPos;
    
    mergedPos = 0;
    leftPos = min;
    rightPos = mid + 1;
    
    while ( leftPos <= mid && rightPos <= max) 
    {
        if( data[leftPos].crn < data[rightPos].crn) 
        {        
            strcpy(mergedNum[mergedPos].subject, data[leftPos].subject);  
            mergedNum[mergedPos].course = data[leftPos].course;
            strcpy(mergedNum[mergedPos].section, data[leftPos].section);
            mergedNum[mergedPos].crn = data[leftPos].crn;
            strcpy(mergedNum[mergedPos].title, data[leftPos].title);
            strcpy(mergedNum[mergedPos].days, data[leftPos].days);
            strcpy(mergedNum[mergedPos].times, data[leftPos].times);
            strcpy(mergedNum[mergedPos].instructor, data[leftPos].instructor);
            mergedNum[mergedPos].enrolled = data[leftPos].enrolled;
            ++leftPos;
        }
        else // data[rightPos]
        {
            strcpy(mergedNum[mergedPos].subject, data[rightPos].subject);  
            mergedNum[mergedPos].course = data[rightPos].course;
            strcpy(mergedNum[mergedPos].section, data[rightPos].section);
            mergedNum[mergedPos].crn = data[rightPos].crn;
            strcpy(mergedNum[mergedPos].title, data[rightPos].title);
            strcpy(mergedNum[mergedPos].days, data[rightPos].days);
            strcpy(mergedNum[mergedPos].times, data[rightPos].times);
            strcpy(mergedNum[mergedPos].instructor, data[rightPos].instructor);
            mergedNum[mergedPos].enrolled = data[rightPos].enrolled;
            ++rightPos;
        }
        ++mergedPos;
    }
    
    while ( leftPos <= mid )
    {
        strcpy(mergedNum[mergedPos].subject, data[leftPos].subject);  
        mergedNum[mergedPos].course = data[leftPos].course;
        strcpy(mergedNum[mergedPos].section, data[leftPos].section);
        mergedNum[mergedPos].crn = data[leftPos].crn;
        strcpy(mergedNum[mergedPos].title, data[leftPos].title);
        strcpy(mergedNum[mergedPos].days, data[leftPos].days);
        strcpy(mergedNum[mergedPos].times, data[leftPos].times);
        strcpy(mergedNum[mergedPos].instructor, data[leftPos].instructor);
        mergedNum[mergedPos].enrolled = data[leftPos].enrolled;
        ++leftPos;
        ++mergedPos;
    }
    
    while( rightPos <= max)
    {
        strcpy(mergedNum[mergedPos].subject, data[rightPos].subject);  
        mergedNum[mergedPos].course = data[rightPos].course;
        strcpy(mergedNum[mergedPos].section, data[rightPos].section);
        mergedNum[mergedPos].crn = data[rightPos].crn;
        strcpy(mergedNum[mergedPos].title, data[rightPos].title);
        strcpy(mergedNum[mergedPos].days, data[rightPos].days);
        strcpy(mergedNum[mergedPos].times, data[rightPos].times);
        strcpy(mergedNum[mergedPos].instructor, data[rightPos].instructor);
        mergedNum[mergedPos].enrolled = data[rightPos].enrolled;
        ++rightPos;
        ++mergedPos;
    }
    for ( mergedPos = 0; mergedPos < mergedSize; ++mergedPos)
    {  
        strcpy( data[rightPos].subject,mergedNum[mergedPos].subject);  
        data[rightPos].course = mergedNum[mergedPos].course;     
        strcpy(data[rightPos].section, mergedNum[mergedPos].section);
        data[rightPos].crn = mergedNum[mergedPos].crn;
        strcpy(data[rightPos].title, mergedNum[mergedPos].title);
        strcpy( data[rightPos].days, mergedNum[mergedPos].days);
        strcpy( data[rightPos].times, mergedNum[mergedPos].times);
        strcpy(data[rightPos].instructor, mergedNum[mergedPos].instructor);
        data[rightPos].enrolled = mergedNum[mergedPos].enrolled;
    }
}