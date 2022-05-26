#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void paintRoom( char** room, int numrows, int numcols );
void recPaintRoom( char** room,int sizeR,int sizeC, int row, int column, char letter);
void print2DArray( char** room, int rows, int cols );
//void isPath (char** room, int sizeR, int sizeC, int row, int column );

typedef struct Point2D
{
   int x; 
   int y;

} Point2D;

//One line function that makes initial call to recur sive function
void paintRoom( char** room, int numrows, int numcols ){
    /* Call your recursive function here */
    
    int x = 1;
    int y = 1;

    char letter = 'A';
    
    recPaintRoom( room,numrows, numcols, y, x, letter);

}

void recPaintRoom( char** room,int sizeR,int sizeC, int row, int column, char letter){
    
     // print2DArray( room, sizeR, sizeC );
     // system("read -n 1 -r -p \"Press any key to continue...\" key");

    //Base case: 
    if (room[row][column] == '*')
    {   
        return;
    }

    
    
    char letter2 = 'A';

    if (room[row][column-1] != ' ' && room[row][column-1] != '*' && room[row][column-1] < letter) //left
    {
        letter2 = room[row][column-1];    
    }

    if ((room[row][column+1] != ' ' && room[row][column+1] != '*') && (room[row][column+1] < letter || room[row][column+1] > letter2 ))//right
    {
        letter2 = room[row][column+1];
    }

    if ((room[row-1][column] != ' ' && room[row-1][column] != '*') && (room[row-1][column] < letter || room[row-1][column] > letter2))//up
    {
        letter2 = room[row-1][column];
    }

    if ((room[row+1][column] != ' ' && room[row+1][column] != '*') && (room[row+1][column] < letter || room[row+1][column] > letter2))//down
    {
        letter2 = room[row+1][column];
    }
    if (letter2 != 'A')
    {
        letter = letter2 + 1;
    }
    if (letter >= 'Z') 
    {     
        letter = 'Z';
    }

    //Recursive case:
   
    room[row][column] = letter;
    if (room[row][column-1] == ' ') //left
    {
    //    room[row][column] = letter;
        recPaintRoom(room,sizeR, sizeC, row, column-1, letter+1);   
    }
    if (room[row][column+1] == ' ') //right
    {
      //  room[row][column] = letter;
        recPaintRoom(room,sizeR, sizeC, row, column+1, letter+1);   
    }
    if (room[row-1][column] == ' ') //up
    {
      //  room[row][column] = letter;
        recPaintRoom(room,sizeR, sizeC, row-1, column, letter+1);   
    }
    if (room[row+1][column] == ' ') //down
    {
       // room[row][column] = letter;
        recPaintRoom(room,sizeR, sizeC, row+1, column, letter+1);   
    }






}











    /*if (room[row][column] != ' ')
    {
        recPaintRoom(room,sizeR, sizeC, row, column, letter++);   
    }
   // if ()*/
    




    /***********************************************************/
   /* if (room[row][column] > room[row][column-1]  && room[row][column] == ' ') //left
    [
        recPaintRoom(room,sizeR, sizeC, row, column-1, letter);   
    ]
    if (room[row][column] > room[row][column+1]  && room[row][column] == ' ') //right
    [
        recPaintRoom(room,sizeR, sizeC, row, column-1, letter);   
    ]
    if (room[row][column] > room[row-1][column]  && room[row][column] == ' ')//up
    [
        recPaintRoom(room,sizeR, sizeC, row, column-1, letter);   
    ]
    if (room[row][column] > room[row+1][column-1]  && room[row][column] == ' ') //down
    [
        recPaintRoom(room,sizeR, sizeC, row, column-1, letter);   
    ]
*/

        
        /*if (room[row][column-1] != ' ' && room[row][column-1] < letter) //left
        {
            letter = room[row][column-1];    
        }
        
        if (room[row][column+1] != ' ' && room[row][column+1] < letter)//right
        {
            letter = room[row][column+1];
        }

        if (room[row-1][column] != ' ' && room[row-1][column] > letter)//up
        {
            letter = room[row-1][column];
        }

        if (room[row+1][column] != ' ' && room[row+1][column] < letter)//down
        {
            letter = room[row+1][column];
        }

        if (row != 1 && column != 1)
        {
            room[row][column] = letter + 1;
            if (letter >= 'Z') 
            {     
                letter = 'Z';
                room[row][column] = letter;
            }
            
            //room[row][column] = letter + 1;
        }
        else
        {
            room[1][1]= 'A';
        }

    room[row][column] = letter; 
    */
    /*****************************RECURSIVE CALL**********************************/
/*
    if (column > 0 && (room[row][column-1] == ' ' || room[row][column-1] > room[row][column])) //left
    { 
        
        recPaintRoom(room,sizeR, sizeC, row, column-1, letter);             
    }
    if (column < sizeC && (room[row][column+1] == ' ' || room[row][column+1] > room[row][column])) //right
    {      
        recPaintRoom(room,sizeR, sizeC, row, column+1, letter);                       
    }
    if (row > 0  && (room[row-1][column] == ' ' || room[row-1][column] > room[row][column])) //up
    {         
        recPaintRoom(room,sizeR, sizeC, row-1, column, letter);                     
    }
    if (row < sizeR && column > 0 && (room[row+1][column] == ' ' || room[row+1][column] > room[row][column])) //down
    {        
        recPaintRoom(room,sizeR, sizeC, row+1, column, letter);        
    }
*/

