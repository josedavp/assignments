/*
    schedule.h
    Project 2
    Jose D. Pague

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

/*******************************************************/
/*******************************************************/
/*******************************************************/



/* 
    printCourseRecord
    ---------------------------
   	This function prints only the subject, course number, section number (all three characters must be shown), title, instructor name in the CourseRecord's data members in one row with formatted in columns
   		CourseRecord a - The record you are printing
    Returns: Nothing
*/
void printCourseRecord( CourseRecord c ); 

/*******************************************************/
/*******************************************************/
/*******************************************************/



/* 
    printCourseInformation
    ---------------------------
   	This function prints only the subject, course number, section number (all three characters must be shown), title, instructor name in the CourseRecord's data members in one row with formatted in columns
   		CourseRecord a - The record you are printing
        Returns: Nothing
*/
void printCourseInformation( CourseRecord a ); 

/*******************************************************/
/*******************************************************/
/*******************************************************/



/*
    printCourses
    ---------------------------
        This function creates a for loop that uses printCourseRecord to print 
        each "course" line.
                    CourseRecord a- The total record you are printing.
        Returns: Nothing
*/
void printCourses( CourseRecord *a, int length ); 

/*******************************************************/
/*******************************************************/
/*******************************************************/



/*
    getCourseCount
    ---------------------------
            This function gets the length of the array and scans it from the file.
                CourseRecord a- contains the array that will be used for printing.
            Returns: length of array.
*/
int getCourseCount( FILE *f ); 

/*******************************************************/
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
void fillCourses( FILE *f, CourseRecord *data, int length );

/*******************************************************/
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
int findCourses( CourseRecord *origin, CourseRecord *dest, int length, char *key1, int key2, SearchType st );

/*******************************************************/
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
void computeStats( CourseRecord *a, int length);

/*******************************************************/
/*******************************************************/
/*******************************************************/

/*
    mergeSortRecords
    ---------------------------
        This function uses creates a mid "length", and uses mergeRecords to sort the data array.
                CourseRecord data- The array itself containing the information later to be sorted.
        Returns: Nothing 
*/
void mergeSortRecords( CourseRecord *data, int min, int max );

/*******************************************************/
/*******************************************************/
/*******************************************************/



/*
    mergeRecords
    ---------------------------
        This function contains the merge sort algorithm used to sort the array.
                CourseRecord data - The array itself used to in the algorithm.
        Returns: Nothing 
*/
void mergeRecords( CourseRecord *data, int min, int mid, int max );

