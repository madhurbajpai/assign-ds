// Name - Madhur Bajpai
// Reg. No.- 2022CA047
// Date- 31/01/2023

#include <stdio.h>
#include "polymularray.h"

#define MAX_TERMS 100

int main()
{
    int nA, nB, nC, i;
    int coefficient, exponent;

    // Read the first polynomial
    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &nA);
    int A[nA];

    // input the terms in descending order as
    // 3x^2 + 2x^2 + x
    // 3 2
    // 2 1
    // 1 0
    printf("Enter the terms of the first polynomial: \n");
    for (i = 0; i < nA; i++)
    {
        scanf("%d %d", &coefficient, &exponent);
        A[exponent] = coefficient; // Store the coefficient at the exponent position
    }

    // Read the second polynomial
    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &nB);
    int B[nB];
    int C[nA * nB];
    // Initialize all elements of C to 0
    for (i = 0; i < nA * nB; i++)
    {
        C[i] = 0;
    }

    printf("Enter the terms of the second polynomial: \n");
    for (i = 0; i < nB; i++)
    {
        scanf("%d %d", &coefficient, &exponent);
        B[exponent] = coefficient; // Store the coefficient at the exponent position
    }

    mulPoly(A, B, C, nA, nB, nC);

    nC = nA + nB - 1;

    // Print the resultant polynomial
    printf("Resultant polynomial: \n");
    for (i = nC - 1; i >= 0; i--)
    {
        if (C[i] == 0)
        {
            continue; // Skip the terms with coefficient 0
        }
        if (i == 0)
        {
            printf("%d\n", C[i]);
        }
        else if (i == 1)
        {
            printf("%dx + ", C[i]);
        }
        else
        {
            printf("%dx^%d + ", C[i], i);
        }
    }

    return 0;
}
