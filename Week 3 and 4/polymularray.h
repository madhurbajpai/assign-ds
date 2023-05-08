// Name - Madhur Bajpai
// Reg. No.- 2022CA047
// Date- 31/01/2023

#ifndef POLY_MUL_ARRAY_H
#define POLY_MUL_ARRAY_H

void mulPoly(int A[], int B[], int C[], int nA, int nB, int nC)
{
    // Multiply the two polynomial
    int i, j;
    for (i = 0; i < nA; i++)
    {
        for (j = 0; j < nB; j++)
        {
            C[i + j] += A[i] * B[j]; // Add the product to the corresponding position in C
        }
    }
}

#endif