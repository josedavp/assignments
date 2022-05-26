/* 
    schedule.c
    Project 2
    Firstname Lastname

    This file contains all the schedule functions.
*/
#include <stdio.h>
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

/* 
    printCourseRecord
    ---------------------------
   	This function prints all the CourseRecord's data members on separate rows. 
   		CourseRecord a - The record you are printing
   	Returns: Nothing
*/
void printCourseInformation( CourseRecord a ) 
{
	printf( "Subj:\t%s\n", a.subject );
	printf( "Course:\t%d\n", a.course );
	printf( "Sec:\t%3s\n", a.section );
	printf( "CRN:\t%d\n", a.crn );
	printf( "Title:\t%s\n", a.title );
	printf( "Instr:\t%s\n", a.instructor );
	printf( "Days:\t%s\n", a.days );
	printf( "Times:\t%s\n", a.times );
	printf( "Enr:\t%d\n\n", a.enrolled );
}