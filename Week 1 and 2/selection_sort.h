/*
Header file for implementing selection sort
Name: Madhur Bajpai
Registration no.: 2022ca047
date : 16/1/23
Input: Expecting an array of type int or char
This program intends to sort the given array using selection sort.
The sorting is done in a manner that the actual parameter itself is changed.
*/

//to ensure that the header file isn't included mutiple times
#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H


//function to find the index of the smallest element using a position and an array
int  smallest(int a[], int size, int pos){
    int small=a[pos];
    int smallpos=pos;

    //for loop to parse the array from pos+1 to size to find the smallest element and acquire its position
    for(int i = pos+1; i < size; i++){
        
        //to check for the smallest value and change values of small and smallpos
        if(a[i]<small){
            small = a[i];
            smallpos=i;
        }
    }
    
    	//returns the position of smallest value
	return smallpos;
}

//function to find smallest element in character array
char smallest_c(char a[], int size, int pos){
    char small=a[pos];
    int smallpos=pos;

    //for loop to parse the array from pos+1 to size to find the smallest element and acquire its position
    for(int i = pos+1; i < size; i++){
        
        //to check for the smallest value and change values of small and smallpos
        if(a[i]<small){
            small = a[i];
            smallpos=i;
        }
    }

    //returns the position of the smallest element
    return smallpos;
}



//selection sort implementation for int
void selection_sort(int a[], int size){
    int index;

    //for loop to parse the array from 0 to size so that left side of the array keeps on sorting
    for (int i = 0; i < size; i++)
    {
        //smallest index
        index = smallest(a,size,i);
        
        //swapping the variable using temporary variable
        int temp = a[i];
        a[i] = a[index];
        a[index] = temp;
    }
}


//selection sort implementation for char
void selection_sort_c(char a[], int size){
    int index;

    //for loop to parse the array from 0 to size so that left side of the array keeps on sorting
    for (int i = 0; i < size; i++)
    {
        //smallest index
        index = smallest_c(a,size,i);
        
        //swapping the variable using temporary variable
        char temp = a[i];
        a[i] = a[index];
        a[index] = temp;
    }
}

#endif
