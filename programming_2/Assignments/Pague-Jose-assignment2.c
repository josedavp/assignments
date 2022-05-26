#include <stdio.h>
#include <string.h>

int main (int argc, char * agrv[]) 
{
    int arrayVal[] = {35, 25, 10, 38, 88, 17, 10, 99,32,47};
    char input[5];
    int i, min, max;

    printf("Enter if you want to find the max or min of the array: ");
    
    scanf("%s", input);
    
    if (strcmp( input, "max" ) == 0)
    {
        printf("you entered max\n");
        max = arrayVal[0];
        for( i = 1; i < 10; i++) 
        {
            if (arrayVal[i] > max)
            {
                max = arrayVal[i];
            }
        }
        printf( "the max value is: %d\n", max);
    }
    else if ( strcmp ( input, "min" ) == 0)
    {
        printf("you entered min\n");
        min = arrayVal[0];
        for (i = 1; i < 10; i++) 
        {
            if (arrayVal[i] < min) 
            {
                min = arrayVal[i];
            }
        }
        printf("the min value is: %d\n", min);
    }
    else 
    {
        printf("invalid input");
    }

    return 0;
}
