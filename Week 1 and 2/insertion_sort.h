/*
Header file for implementing insertion sort
Name: Madhur Bajpai
Registration no.: 2022ca047
Date: 17-01-23
Input: Expecting an array of any type(template is being used) and its size
This program intends to sort the given array using insertion sort.
The sorting is done in a manner that the actual parameter itself is changed.(inline)
Output:none
*/

//to ensure that the header file isn't included mutiple times
#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H


//insertion sort for an integer array
void insertion_sort_int(int a[], int size){
    
    //parsing for loop to sort the array on the left of the variable i as it moves to the right
    for (int i = 0; i < size; i++)
    {

        //temporary variable to help in shift operation
        int temp = a[i];
        int j = i-1;

        //using while loop to right shift
        while ((temp<a[j])&&j>=0)
        {
            a[j+1]=a[j];
            j--;
        }

        //shifting the intial value to right
        a[j+1]=temp;
    }
}


//insertion sort function for a character array
void insertion_sort_char(char a[], int size){
    
    //parsing for loop to sort the array on the left of the variable i as it moves to the right
    for (int i = 0; i < size; i++)
    {

        //temporary variable to help in shift operation
        char temp = a[i];
        int j = i-1;

        //using while loop to right shift
        while ((temp<a[j])&&j>=0)
        {
            a[j+1]=a[j];
            j--;
        }

        //shifting the intial value to right
        a[j+1]=temp;
    }
}


