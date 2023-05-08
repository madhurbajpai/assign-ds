/*
Header file for implementing merge sort
Name: Madhur Bajpai
Registration no.: 2022ca047
Date: 17-01-23
Input: Expecting an array of any either an integer or a character
This program intends to sort the given array using merge sort.
The sorting is done in a manner that the actual parameter itself is changed.(inline)
Output:none
*/

//to ensure that the header file isn't included mutiple times
#ifndef MERGE_SORT_H
#define MERGE_SORT_H


//merge function to merge the array a and put it back in a
void merge(int a[], int beg, int mid, int end, int size){
    int i = beg, j = mid+1, index=beg;
    int *temp = malloc(sizeof(int)*size);

    //this while loop merges the broken elements of the array and puts it into temp array
    while((i<=mid)&&(j<=end)){
        
        //if left partition has lesser value insert it into temp first
        if(a[i]<a[j]){
            temp[index]=a[i];
            i++;
        }
        //if right partition has non lesser value insert it in temp first
        else{
            temp[index]=a[j];
            j++;
        }
        index++;
    }

    //to check if we have parsed every element in the left and right array
    if (i>mid)
    {
        //greater element in right array are inserted as such since they are already sorted
        while(j<=end){
            temp[index]=a[j];
            j++;
            index++;
        }
    }
    else{
        //smaller element in right array are inserted as such since they are already sorted
        while(i<=mid){
            temp[index]=a[i];
            i++;
            index++;
        }
    }

    //now copying the merged and sorted temp array back to the array a passed in the function
    for (int k = beg; k < index; k++)
    {
        a[k]=temp[k];
    }
}


// merge sort function to sort it recursively
void split(int *a, int beg, int end, int size){
    int mid;

    //terminating the condition if beg and end cross each other
    if (beg<end)
    {
        mid=(beg+end)/2;

        //calling merge sort for left half of the array recursively until base condition is false
        split(a, beg, mid, size);

        //calling merge sort for right half of the array recursively until base condition is false
        split(a, mid+1,end, size);

        //merging the array sorted in the previous iteration and putting it back to the array itself
        merge(a,beg,mid,end,size);
    }
}

//function for merge sort of char
void merge_sort(int *a, int n){
    split(a,0,n-1,n);
}


/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////


//merge function to merge the array a and put it back in a
void merge_c(char a[], int beg, int mid, int end, int size){
    int i = beg, j = mid+1, index=beg;
    char *temp = malloc(sizeof(char)*size);

    //this while loop merges the broken elements of the array and puts it into temp array
    while((i<=mid)&&(j<=end)){
        
        //if left partition has lesser value insert it into temp first
        if(a[i]<a[j]){
            temp[index]=a[i];
            i++;
        }
        //if right partition has non lesser value insert it in temp first
        else{
            temp[index]=a[j];
            j++;
        }
        index++;
    }

    //to check if we have parsed every element in the left and right array
    if (i>mid)
    {
        //greater element in right array are inserted as such since they are already sorted
        while(j<=end){
            temp[index]=a[j];
            j++;
            index++;
        }
    }
    else{
        //smaller element in right array are inserted as such since they are already sorted
        while(i<=mid){
            temp[index]=a[i];
            i++;
            index++;
        }
    }

    //now copying the merged and sorted temp array back to the array a passed in the function
    for (int k = beg; k < index; k++)
    {
        a[k]=temp[k];
    }
}


// merge sort function to sort it recursively
void split_c(char *a, int beg, int end, int size){
    int mid;

    //terminating the condition if beg and end cross each other
    if (beg<end)
    {
        mid=(beg+end)/2;

        //calling merge sort for left half of the array recursively until base condition is false
        split_c(a, beg, mid, size);

        //calling merge sort for right half of the array recursively until base condition is false
        split_c(a, mid+1,end, size);

        //merging the array sorted in the previous iteration and putting it back to the array itself
        merge_c(a,beg,mid,end,size);
    }
}

//function for merge sort of char
void merge_sort_c(char *a, int n){
    split_c(a,0,n-1,n);
}

#endif
