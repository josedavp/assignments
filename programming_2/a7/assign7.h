#ifndef assign7_h
#define assign7_h
#include <stdio.h>
#include <string.h>

typedef struct {
    char course_Name[60];
    char course_Sched[4];
    unsigned course_Hours;
    unsigned course_Size;
} COURSE;

void createCourse(FILE *ptrCourseFile);
void updateCourse(FILE *ptrCourseFile);
void readCourse(FILE *ptrCourseFile);
void deleteCourse(FILE *ptrCourseFile);

#endif
