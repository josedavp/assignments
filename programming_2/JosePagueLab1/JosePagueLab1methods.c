#include <stdio.h>
#include <math.h>

void displayBits(unsigned int n);
unsigned int setKthBit (unsigned int n, int k);
int isPowerOfTwo (unsigned int n);
int getNoBits(unsigned int a, unsigned int b);
unsigned int computeXor(unsigned int n);

void displayBits(unsigned int n) //This works!
{
    int count = 0;
    int num[32];
    int j;

    unsigned int value = n;

    unsigned int arrSize = sizeof(unsigned int);
    unsigned int arrTotal = arrSize * 8;
    unsigned int total;
    
    while ( arrTotal > 0 )  
    {
        total = n % 2;
        n = n / 2;
        num[count] = total;
        count++;
        arrTotal--;
    }
  //  printf("\n");
    for (j = 31; j >= 0; --j) 
    {
        if (j == 31)
        {
            printf("%7u = ", value);
        }
        if (j % 8 == 0)
        {
            printf("%d ", num[j]);
        }
        else 
        {
            printf("%d", num[j]);
        }
    }
    printf("\n");
    //printf("\n\n");
}

unsigned int setKthBit( unsigned int n, int k) //This works!
{
    int count = 0;
    int m = 0;
    int num[32];
    int sum[32];
    int j;
    
    unsigned int value = n;

    unsigned int arrSize = sizeof(unsigned int);
    unsigned int arrTotal = arrSize * 8;
    unsigned int total;
    unsigned int remainder;
    unsigned int decimal;
    
    unsigned int val = (( 1 << k-1 ) | n);

    return val;
}


int isPowerOfTwo (unsigned int n) //This works!
{
    unsigned int value = n;
    if (value == 0)
    {
        return 0;
    }


    while (value != 1)
    {
        if ((value % 2) != 0)
        {
            return 0;
           // printf("THIS IS isPowerOfTwo%d", value);
        }
        else 
        {
        value = value / 2;
        }
    }
    return 1;
}

int getNoBits(unsigned int a, unsigned int b) //This works!
{
    int i; 
    int num = 0;
    unsigned int total = a^b;

   // printf("A = %d\n", a);
   // printf("B = %d\n", b);
    //for (i = 0; i < b; i++)
    //{
     //   total = total * a;
   // }
   // printf("TOTAL= %d", total);
   // printf("\n\n");

    while (total > 0)
    {
        total = total & ( total - 1);
        num++;
    }

   // printf("\n\n");
  //  printf("TOTAL After= %d\n", total);
  //  printf("NUM = %d", num);
 //   printf("\n\n");
    return num;
}

unsigned int computeXor(unsigned int n) //This works!
{
   switch (n % 4)
   {
        case 0:
            return n;
        case 1:
            return 1;
        case 2:
            return n + 1;
        default:
            printf("Unfound");
   }
   return 0;

}

/*int main ()
{
    unsigned int x = 0;
    x = setKthBit(x, 8);
    displayBits(x);
    printf("%7u power of 2? %d\n", 1,isPowerOfTwo(1));
    printf("\n\n");
    printf("%7u bits convert %u to %u\n", getNoBits(533,524313), 533,524313);
    printf("TEST 6: XOR of all numbers");
    x = computeXor(5);
    displayBits(x);
}*/
