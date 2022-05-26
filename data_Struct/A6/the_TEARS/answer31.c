#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


/********Creates Space******************/
char** mallocSpace(char** maze, int sizeM);
void createMaze(char** maze, int sizeR, int sizeC);
void printMaze(char** maze,int sizeR, int sizeC);

/***************************************/
typedef struct Point2D
{
    int x;
    int y;

} Point2D;

typedef struct Path
{
    bool visit;
    int count;
    char* pnext;
    int lowestCount;
    
} Path;

/**************************************/

int main(int argc, char* argv[])
{
    int row = 9; 
    int column = 14;
    int sizeM = row * column;
    char** maze;
    bool pass = false;
    bool visited = false;
    int count = 0;
    int lowestCount = 0
    
    //Point2D start;

    maze = mallocSpace(maze , sizeM);
    createMaze(maze, row, column, pass);

    start.x = 1;
    start.y = 1;

    printMaze(maze, row, column);
   
    






    return 0;
}//end of main

/**************Creates Background Maze****************/
void createMaze(char** maze, int sizeR, int sizeC, bool pass)
{
    int row, column;

    for(row = 0; row < sizeR; row++) //creates the inside of the maze
    {
        for (column = 0; column < sizeC; column++) 
        {
            maze[row][column] = ' ';

            if (row == 0 || row == sizeR-1) //top and bottom
            {
                maze[row][column] = '*';
            }
            if (column == 0 || column == sizeC-1)
            {
                maze[row][column] = '*';
            }
            if ((row == 2 && column == 5) || (row == 3 && column == 5))
            {
                maze[row][column] = '*';
            }
            if ((row == 4 && column == 3) || (row == 4 && column == 4) || (row == 4 && column == 5) )
            {
                maze[row][column] = '*';
            }        
            if ((row == 6 && column == 6) || (row == 6 && column == 7) || (row == 6 && column == 8) || (row == 6 && column == 9))
            {
                 maze[row][column] = '*';
            }
            if (row == 6 && column == 10)
            {
                 maze[row][column] = '*';
            }
            if ((row == 7 && column == 6) || (row == 7 && column == 7) || (row == 7 && column == 8))
            {
                maze[row][column] = '*';
            }

            furnitureRoom(maze, row, column, pass);
        }// end of first for loop
    } // end of second for loop
}// end of function 

/********************Creates impassable Regions******************************/
bool furnitureRoom(char** maze, int sizeR, int sizeC, bool pass )
{
    Path visit;
    int row, column;
            if (maze[row][column] == ' ') // set to true will let you go through maze
            {
                pass.visit = true;
            }
            if (maze[row][column] == '*')
            {
                pass = false;
            }

    return pass;
}

/*******************Prints Maze********************/
void printMaze(char** maze,int sizeR, int sizeC)
{
    int row, column;

    for (row = 0; row < sizeR; row++)
    {
        for (column = 0; column < sizeC; column++) 
        {
            printf("%c ", maze[row][column]);
        }
        printf("\n");
    }
}
/*************Mallocs Space For The MAZE**************/     
char** mallocSpace(char** maze, int sizeM)
{
    int i,j;

    maze = (char**) malloc(sizeof(char*)*sizeM);
    
    for( i=0; i<sizeM; i++ )
    {
        maze[i] = (char*) malloc(sizeof(char)*sizeM);
        
        for (j = 0; j < sizeM; j++)
        {
            maze[i][j] = ' ';
        }     
    }
    return maze;
}
/******************TO VISIT OR NOT VISIT*********************/
bool vistPath(char** maze, int sizeR, int sizeC, bool visit)
{
    if (maze[row][column] == ' ' && visit == true)
    {
        
    }
}




/**************Finds all steps around home*******************/
int allSteps(char** maze, row, column, bool pass) 
{
    if ()
}

void printSteps()
[

]
/************************************************************/
