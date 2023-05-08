/*
Header file for implementing radix sort
Name: Madhur Bajpai
Registration no.: 2022ca047
Date: 17-01-23
Input: Expecting an array of an integer
This program intends to sort the given array using merge sort.
The sorting is done in a manner that the actual parameter itself is changed.(inline)
Output:none
*/

//to ensure that the header file isn't included mutiple times
#ifndef MERGE_SORT_H
#define MERGE_SORT_H

//--------------------------------------------------------------Integer--------------------------------------------------------------//

//getting maximum element
int getMax(int arr[],int n){
	int max=arr[0];
	//parsing the loop to find the largest from first element from 1 to n
	for(int i=1;i<n;i++){
		if(arr[i]>max){
			max=arr[i];
		}
	}
	//returns the max element
	return max;
}

//count sort function to sort the array based on single elements
void countSort(int arr[],int n,int exp){
	
	int output[n];
	int i,count[10]={0};
	
	for(i=0;i<n;i++){
		count[(arr[i]/exp)%10]++;
	}
	//changing count value to make it contain the position of this digit in final array
	for(i=1;i<10;i++){
		count[i]+=count[i-1];
	}
	for( i=n-1;i>=0;i--){
		output[count[(arr[i]/exp)%10]-1]=arr[i];
		count[(arr[i]/exp)%10]--;
	}
	//storing the sorted output in the main array  
	for(i=0;i<n;i++){
		arr[i]=output[i];
	}

}

//radix sort function to sort the array
void radixSort(int arr[],int n){
	//getting max in the array to count the number of digits
	int max=getMax(arr,n);
	for(int placeValue=1; max/placeValue > 0 ; placeValue*=10 ){
		countSort(arr,n,placeValue);
	}
}
#endif

