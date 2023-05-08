/*
Header file for implementing bucket sort
Name: Madhur Bajpai
Registration no.: 2022ca047
Date: 17-01-23
Input: Expecting an array of integer
This program intends to sort the given array using bucket sort.
The sorting is done in a manner that the actual parameter itself is changed.(inline)
Output:none
*/

//to ensure that the header file isn't included mutiple times
#ifndef MERGE_SORT_H
#define MERGE_SORT_H


int max_element(int array[], int size) 

{  

    // Initializing max variable to minimum value so that it can be updated
    // when we encounter any element which is greater than it.
    int max = INT_MIN;  

    for (int i = 0; i < size; i++)
    {
        //Updating max when array[i] is greater than max
        if (array[i] > max)  
	        max = array[i];  
    }

    //return the max element
    return max;  
}

//Implementing bucket sort 
void bucketSort(int array[], int size) 
{  
    //Finding max element of array which we will use to create buckets
    int max = max_element(array, size); 

    // Creating buckets 
    int bucket[max+1];  

     //Initializing buckets to zero
    for (int i = 0; i <= max; i++)  
	    bucket[i] = 0;  

    // Pushing elements in their corresponding buckets
    for (int i = 0; i < size; i++)  
    bucket[array[i]]++;
 
    // Merging buckets effectively
    int j=0;   // j is a variable which points at the index we are updating
    for (int i = 0; i <= max; i++)  
    { 
        // Running while loop until there is an element in the bucket
        while (bucket[i] > 0)  
        {  
            // Updating array and increment j          
            array[j++] = i;  

            // Decreasing count of bucket element
            bucket[i]--;   
        }  

    }  
}  

#endif
