/*
Header file for implementing selection sort
Name: Madhur Bajpai
Registration no.: 2022ca047
Date: 17-01-23
Input: Expecting an array of any type(template is being used) and its size
This program intends to sort the given array using bubble sort.
The sorting is done in a manner that the actual parameter itself is changed.(inline)
Output:none
*/

//to ensure that the header file isn't included mutiple times
#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H


//bubble sort works on the principle that heavier elements are bubbled out at the end of the array
void bubble_sort_int(int *arr, int n){
    //for loop to keep on parsing the array until it is sorted
    for(int i=0;i<n-1;i++){
        //inner loop runs for n-i-1 iteration to ensure that the sorted array isn't compared again all the while shifting the heaviest(greatest) element to right
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                //swapping the variable if the variable is greater than its next element
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

//bubble sort for a character 
void bubble_sort_char(char *arr, int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                char temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

#endif
