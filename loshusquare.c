#include <stdio.h>
#include <stdlib.h>

int isLoShuSquare(int square[3][3])
{
    int n = 0;
    int tempn = 0;

    for(int i = 0; i < 3; i++) // checks first row
    {
        n = n + square[0][i];
    }

    for(int i = 1; i < 3; i++) // checks second and third row
    {
        int tempn = 0;
        for (int j = 0; j < 3; j++)
        {
            tempn = tempn + square[i][j];
        }
        if(tempn != n)
        {
            return 0;
        }
    }

    for(int i = 0; i < 3; i++) // checks all columns
    {
        tempn = 0;
        for(int j = 0; j < 3; j++)
        {
            tempn = tempn + square[j][i];
        }
        if (tempn != n)
        {
            return 0;
        }
    }

    tempn = 0;
    for(int i = 0; i < 3; i++) // checks diagonals
    {
        tempn = tempn + square[i][i];
    }
    if(tempn =! n)
    {
        return 0;
    }
    tempn = square[0][2] + square[1][1] + square[0][2];
    if(tempn = !n)
    {
        return 0;
    }
    return 1;
}