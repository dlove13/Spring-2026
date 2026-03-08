#include <stdio.h>
#include "matrix.h"

void addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]) 
{
        for (int i = 0; i < SIZE; i++) 
        {
                for (int j = 0; j < SIZE; j++) 
                {
                        result[i][j] = m1[i][j] + m2[i][j];
                }
        }
}

void multMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE])
{
        for (int i = 0; i < SIZE; i++)
        {
                for (int j = 0; j < SIZE; j++)
                {
                        for (int k = 0; k < SIZE; k++)
                        {
                                result[i][j] += m1[i][k] * m2[k][j];
                        }
                }
        }
}

void transMatrix(int m1[SIZE][SIZE], int result[SIZE][SIZE])
{
        for (int i = 0; i < SIZE; i++) 
        {   
                for (int j = 0; j < SIZE; j++)
                {
                        result[j][i] = m1[i][j];
                }
        }
}

void printMatrix(int m1[SIZE][SIZE])
{
        for (int i = 0; i < SIZE; i++)
        {
                for (int j = 0; j < SIZE; j++)
                {
                        printf("%d\t", m1[i][j]);
                }
                printf("\n");
        }
        printf("\n");
}

int main() {

        int m1[SIZE][SIZE] = {
                {1,2,3,4,5},
                {6,7,8,9,10},
                {11,12,13,14,15},
                {16,17,18,19,20},
                {21,22,23,24,25}
        };

        int m2[SIZE][SIZE] = {
                {25,24,23,22,21},
                {20,19,18,17,16},
                {15,14,13,12,11},
                {10,9,8,7,6,},
                {5,4,3,2,1}
        };
        
        int result[SIZE][SIZE];

        printf("Matrix addition: \n");
        printMatrix(m1);
        printf("+\n");
        printMatrix(m2);
        printf("=\n");
        
        addMatrices(m1,m2,result);
        printMatrix(result);

        printf("\nMatrix Multiplication\n");
        printMatrix(m1);
        printf("*\n");
        printMatrix(m2);
        printf("=\n");

        multMatrices(m1,m2,result);
        printMatrix(result);

        printf("\nTranspose of matrix 1\n");
        transMatrix(m1, result);
        printMatrix(result);

        printf("\nTranspose of matrix 2\n");
        transMatrix(m2, result);
        printMatrix(result);

        return 0;
}
