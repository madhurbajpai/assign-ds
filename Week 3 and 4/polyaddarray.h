//Name - Madhur Bajpai
//Reg. No.- 2022CA047
//Date- 31/01/2023

#ifndef POLY_ADD_ARRAY_H
#define POLY_ADD_ARRAY_H

void addPolynomials(int A[], int B[], int C[], int degreeA, int degreeB)
{
    int i, degreeC;

    //calculating the highest degree
    degreeC = (degreeA > degreeB) ? degreeA : degreeB;


    //initialising the resultant array with 0
    for (i = 0; i <= degreeC; i++)
    {
        C[i] = 0;
    }

    //copying the coefficient of first polynomials
    for (i = 0; i <= degreeA; i++)
    {
        C[i] += A[i];
    }

    //adding the coefficients of second polynomial
    for (i = 0; i <= degreeB; i++)
    {
        C[i] += B[i];
    }
}

#endif