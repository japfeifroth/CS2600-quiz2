#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "loshusquare.c"

void printSquare(int square[3][3])
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if((i == 0 && j == 0) || (i == 1 && j == 0) || (i == 2 && j == 0))
            {
                printf("[");
            }
            if((i != 0 && j != 0) || (i != 1 && j != 0) || (i != 2 && j != 0))
            {
                printf(" ");
            }  
            printf("%d", square[i][j]);
        }
        printf("]\n");
    }
}

void checkIfLoShuSquare(int sqaure[3][3])
{
    if(isLoShuSquare(sqaure) == 1)
    {
        printf("The square is a Lo Shu Sqaure\n\n");
    }
    else
    {
        printf("The square is a not Lo Shu Sqaure\n\n");
    }
}

void fillSquare(int square[3][3])
{

        int numUsed[10] = {0};
        for (int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                int n = rand()%9 + 1;
                while(numUsed[n])
                {
                    n = rand()%9 + 1;
                }
                square[i][j] = n;
                numUsed[n]= 1;
            }
        }
}

int main()
{
    int sqaure[3][3] = {
        {6, 1, 8},
        {7, 5, 3},
        {2, 9, 4}
    };
    int count = 0;
    printSquare(sqaure);
    isLoShuSquare(sqaure);
    checkIfLoShuSquare(sqaure);
    int RandomSquare[3][3];
    fillSquare(RandomSquare);
    isLoShuSquare(sqaure);
    printSquare(RandomSquare);
    checkIfLoShuSquare(RandomSquare);
    
    while(1)
    {
        count++;
        srand(time(0) + count);
        fillSquare(RandomSquare);
        if(isLoShuSquare(RandomSquare) == 1)
        {
            break;
        }
    }
    printf("Number of sqaures generated: %d\n", count);
    printSquare(RandomSquare);
    checkIfLoShuSquare(RandomSquare);
    return 0;
}