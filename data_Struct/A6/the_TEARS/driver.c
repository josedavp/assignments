#include <stdlib.h>
#include <stdio.h>

#include "answer3.c"

char** read2DArray( char* name, int* prows, int* pcols );
void print2DArray( char** room, int rows, int cols );
void free2DArray( char** room, int rows, int cols );

int main( int argc, char *argv[] )
{
    int i, rows, cols;
    int numFiles = 4;
    char *defaultFilenames[] = {"room-Small.txt", "room-Medium.txt", "room-Long.txt", "room-Large.txt"};
    char **room;

        printf("Running default test files: \n\n");

    for( i=0; i<numFiles; i++ ){
        printf("\n--------------- START OF OUTPUT FOR %s -----------------\n\n", defaultFilenames[i]);

        room = read2DArray( defaultFilenames[i], &rows, &cols );
        printf("Base room: \n\n");
        print2DArray( room, rows, cols );

        paintRoom( room, rows, cols );

        printf("\nRoom after algorithm: \n\n");
        print2DArray( room, rows, cols );

        free2DArray( room, rows, cols );

        printf("\n--------------- END OF OUTPUT FOR %s -----------------\n\n", defaultFilenames[i]);
    }

    return 0;
}

//Read in and return room from given file
char** read2DArray( char* name, int* prows, int* pcols )
{
    int i, j;
    FILE *f = fopen( name, "r" );
    char **room;
    char buffer[100];
    char* line;

    if( f==NULL || fgets(buffer, 100, f)==NULL || sscanf( buffer, "%d%d", prows, pcols )!=2 )
    {
        printf("ERROR - Invalid file format %s\n", name);
        exit(-1);
    }

    line = (char*)malloc( sizeof(char)*(*pcols+10) );

    room = (char**)malloc( sizeof(char*)*(*prows) );
    for( i=0; i<*prows; i++ ){
        room[i] = (char*)malloc( sizeof(char)*(*pcols) );

        if( fgets( line, *pcols+10, f ) == NULL ){
            printf("ERROR - Failed to read %dth row\n", i+1);
            exit(-1);
        }
        for( j=0; j<*pcols; j++ )
            room[i][j] = line[j];
    }

    free(line);

    /* close file and return created trafficData */
    fclose( f );
    return room;
}

//Print given 2D array
 void print2DArray( char** room, int rows, int cols ){
    int i, j;

    for( i=0; i<rows; i++ ){
        for( j=0; j<cols; j++ )
            printf("%c", room[i][j]);
        printf("\n");
    }
}

//Free given 2D array
 void free2DArray( char** room, int rows, int cols ){
    int i;

    for( i=0; i<rows; i++ )
        free(room[i]);
    free(room);
}
