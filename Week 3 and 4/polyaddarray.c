//Name - Madhur Bajpai
//Reg. No.- 2022CA047
//Date- 31/01/2023

#include <stdio.h>
#include "polyaddarray.h"


int main()
{
    int degreeA, degreeB, degreeC, i;

    printf("Enter degree of first polynomial: ");
    scanf("%d", &degreeA);
    //creating array for the first polynomial
    int A[degreeA + 1];
    printf("Enter coefficients of first polynomial: ");
    for (i = degreeA; i >= 0; i--)
    {
        scanf("%d", &A[i]);
    }

    printf("Enter degree of second polynomial: ");
    scanf("%d", &degreeB);
    //creating the array for the second polynomial
    int B[degreeB + 1];
    degreeC = (degreeA > degreeB) ? degreeA : degreeB;
    int C[degreeC + 1];
    printf("Enter coefficients of second polynomial: ");
    for (i = degreeB; i >= 0; i--)
    {
        scanf("%d", &B[i]);
    }

    addPolynomials(A, B, C, degreeA, degreeB);

    printf("Resultant polynomial: \n");
    for (i = degreeC; i >= 0; i--)
    {
        if (i != 0)
            printf("%d x^%d + ", C[i], i);
        else
            printf("%d ", C[i], i);
    }
    return 0;
}
