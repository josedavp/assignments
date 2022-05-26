/*
    schedule.h
    Project 2
    Firstname Lastname

    This file is the header file for the #define, enum, struct, and prototypes used in this project.
*/

/* boolean values */
#define TRUE 1
#define FALSE 0

/* enumeration used for the findCourses() function */
typedef enum SearchType{ COURSE, CRN, DAYS, INSTRUCTOR } SearchType;

/* struct that represents one record within the schedule CSV file. Note that not all the data from the CSV file will be used */
typedef struct CourseRecord
{
	char subject[ 5 ];
	int course;
	char section[ 5 ];
	int crn;
	char title[ 50 ];
	char days[ 10 ];
	char times[ 50 ];
	char instructor[ 50 ];
	int enrolled;
} CourseRecord;

/* 
    printMenu
    ---------------------------
    This function prints the main menu.
    Returns: Nothing
*/
void printMenu();

/* 
    printCourseRecord
    ---------------------------
   	This function prints all the CourseRecord's data members on separate rows. 
   	   		CourseRecord a - The record you are printing
   	Returns: Nothing
*/
void printCourseRecord( CourseRecord );

/* 
    printCourseRecord
    ---------------------------
   	This function prints only the subject, course number, section number (all three characters must be shown), title, instructor name in the CourseRecord's data members in one row with formatted in columns
   		CourseRecord a - The record you are printing
    Returns: Nothing
*/
void printCourseInformation( CourseRecord );


/* need function comments for all remaining prototypes */
void printCourses( CourseRecord *, int );
int getCourseCount( FILE * );
void fillCourses( FILE *, CourseRecord *, int );
int findCourses( CourseRecord *, CourseRecord *, int , char *, int, SearchType );
void computeStats( CourseRecord *, int );
void mergeSortRecords( CourseRecord *, int, int );
void mergeRecords( CourseRecord *, int, int, int );