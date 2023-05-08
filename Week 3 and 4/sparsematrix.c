//Name - Madhur Bajpai
//Reg. No.- 2022CA047
//Date- 31/01/2023

#include <stdio.h>
#include "sparsematrix.h"

int main()
{
    int a[20][20], k[3][100], i, j, m, n, count = 0;

    //input the first matrix as 4 x 4
    //1 1 1 1
    //1 0 0 1
    //0 0 0 1
    //1 0 0 0
    printf("Enter no of rows");
    scanf("%d", &m);
    printf("Enter no of coloumns");
    scanf("%d", &n);
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
            if (a[i][j])
            {
                k[0][count] = i;
                k[1][count] = j;
                k[2][count] = a[i][j];
                count++;
            }
        }
    }
    //input the second matrix and multiply
    multiply(k, count, m, n);
}
