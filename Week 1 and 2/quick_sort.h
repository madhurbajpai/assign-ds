/*
Header file for implementing quick sort
Name: Madhur Bajpai
Registration no.: 2022ca047
Date: 17-01-23
Input: Expecting an array of any type(template is being used) and its size
This program intends to sort the given array using merge sort.
The sorting is done in a manner that the actual parameter itself is changed.(inline)
Output:none
*/

//----------------------------Integer----------------------------

//partition function selects a pivot element and shifts the greater element to the right and lesser elements to the left
int partition(int *A,int low,int high){
	
	//choice of pivot element here is the first element of array passed
	int pivot = A[low];
	int i=low+1;
	int j=high;
	int temp;
	
	//do while loop to shift the lesser elements to the left of pivot element and greater to the right of pivot 
	do{
		//to check if we are finding an element smaller than pivot from the left
		while(A[i]<=pivot){
			i++;
		}
		//to check if we are finding an element greater than pivot from right
		while(A[j]>pivot){
			j--;
		}
		//when i and j are found then checking if we can swap them or not
		if(i<j){
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}while(i<j);
	
	//switching the pivot elements with the position of low which is now a separator of lesser element and greater element
	temp = A[low];
	A[low] = A[j];
	A[j] = temp;
	
	//returning the index of pivot element
	return j;
	
}

//recursive call to quick sort to break and sort using the pivot element
void quickSort(int A[],int low , int high){
	//only if low is less than high
	if(low<high){
		//index of pivot after partition
		int partitionIndex = partition(A,low,high);
		//sort left subarray
		quickSort(A,low,partitionIndex-1);  
		//sort right subarray
		quickSort(A,partitionIndex +1 , high);
	}
}




//--------------------------------------------------------------------------character ------------------------------------------------------------------------------------//




//patition function for a character
char partition_c(char *A,int low,int  high){
	//choice of pivot element here is the first element of array passed
	char pivot = A[low];
	int i=low+1;
	int j=high;
	char temp;
	
	//do while loop to shift the lesser elements to the left of pivot element and greater to the right of pivot 
	do{
		//to check if we are finding an element smaller than pivot from the left
		while(A[i]<=pivot){
			i++;
		}
		//to check if we are finding an element greater than pivot from right
		while(A[j]>pivot){
			j--;
		}
		//when i and j are found then checking if we can swap them or not
		if(i<j){
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}while(i<j);
	
	//switching the pivot elements with the position of low which is now a separator of lesser element and greater element
	temp = A[low];
	A[low] = A[j];
	A[j] = temp;
	
	//returning the index of pivot element
	return j;
	
}

//recursive call to quick sort to break and sort using the pivot element
void quickSort_c(char A[],int  low , int  high){
	//sort left subarray
	if(low<high){
		//sort left subarray
		partitionIndex = partition_c(A,low,high);
		//sort left subarray
		quickSort_c(A,low,partitionIndex-1);
		//sort left subarray
		quickSort_c(A,partitionIndex +1 , high);
	}
}


