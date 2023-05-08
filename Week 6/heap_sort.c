//Name - Madhur Bajpai
//Reg. No. - 2022CA047
//Date - 14/02/2023

//Objective - Implement heap Sort
#include <stdio.h>
#include <stdlib.h>

//function to heapify the tree
void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
 
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
 
        //calling the heapify function
        heapify(arr, n, largest);
    }
}

//function to implement the heapsort
void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    for (int i=n-1; i>=0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
 
        heapify(arr, i, 0);
    }
}

//function to print the array
void printArray(int arr[], int n) {
    for (int i=0; i<n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

//main function
int main() {
    int arr[] = {73, 15, 63, 45, 16, 47};
    int n = sizeof(arr)/sizeof(arr[0]);
    //calling the function
    heapSort(arr, n);

    printf("Sorted array is \n");
    printArray(arr, n);
 
    return 0;
}
