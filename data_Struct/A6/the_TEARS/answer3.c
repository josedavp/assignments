#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void paintRoom( char** room, int numrows, int numcols );
void recPaintRoom( char** room,int sizeR,int sizeC, int row, int column, char letter);
void print2DArray( char** room, int rows, int cols );
//void isPath (char** room, int sizeR, int sizeC, int row, int column );


//One line function that makes initial call to recur sive function
void paintRoom( char** room, int numrows, int numcols ){
    /* Call your recursive function here */

    recPaintRoom( room,numrows, numcols, 1, 1, 'A');

}

void recPaintRoom( char** room,int sizeR,int sizeC, int row, int column, char letter){

    //Base case: 
    if (letter > 'Z' ) letter = 'Z';
    if (room[row][column] == '*') return;

    room[row][column] = letter;
  /****************************updates letter**************************************/
  /* if (room[row][column-1] == ' ') //|| room[row][column-1] > letter) room[row][column-1] = letter+1;//left
    if (room[row][column+1] == ' ')//|| room[row][column+1] > letter) room[row][column+1] = letter+1; //right      
    if (room[row-1][column] == ' ')//|| room[row-1][column] > letter) room[row-1][column] = letter+1; //up      
    if (room[row+1][column] == ' ')//|| room[row+1][column] > letter) room[row+1][column] = letter+1; //down  */  
    /******************************RECURSION******************************/
    //Recursive case: 
    if (room[row][column-1] == ' ' || room[row][column-1] > letter) recPaintRoom(room,sizeR, sizeC, row, column-1, letter+1); //left 
    if (room[row][column+1] == ' ' || room[row][column+1] > letter) recPaintRoom(room,sizeR, sizeC, row, column+1, letter+1); //right    
    if ( room[row-1][column] == ' '|| room[row-1][column] > letter) recPaintRoom(room,sizeR, sizeC, row-1, column, letter+1); //up     
    if (room[row+1][column] == ' ' || room[row+1][column] > letter) recPaintRoom(room,sizeR, sizeC, row+1, column, letter+1); //down       
}


/*********************************WHAT I DID FOR 3 ENTIRE DAYS STRAIGHT*****************************/
/*
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
    if (letter >= 'Z' ) 
    {     
        letter = 'Z';
    }
*/













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

