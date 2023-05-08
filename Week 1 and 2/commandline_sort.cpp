//week1 assignment 
// Name: Madhur Bajpai
// Registration no.: 2022ca047
// This program takes input from the suer in command line input and then the user gets the option he/she wants to use to sort them . header files are called of respective sort
#include<stdio.h>
#include<stdlib.h>
#include "selection_sort.h"
#include "bubble_sort.h"
#include "insertion_sort.h"
#include "quick_sort.h"
#include "radix_sort.h"
#include<time.h>
using namespace std;
  
int main(int argc, char** argv)
{       
	time_t start,end;
	// Type of choices	
	int inputChoice , sortChoice , dataType ;
	FILE *fptr;
	//input method in program
	printf("Enter the input method : \n1.CommandLine \n2.User Input \n3.file input/output");
	scanf("%d",&inputChoice);
	int n=argc-1;	
    	int arr[1000],i;
    	char arr1[1000];
    	//Data type of Array
    	printf("Array includes \n 1. Only Integers \n 2. alphanumeric \n");
    	scanf("%d",&dataType);
    	
    	//taking input from command line argument
    	if(inputChoice==1){
    		switch(dataType){
    			case 1: for(i=0;i<n;i++){
    					arr[i]=atoi(argv[i+1]);
    		       	}
    			       break;
    			case 2: for(i=0;i<n;i++){
    					arr1[i]=argv[i+1][0];
    				}
    				break;
    			default: printf("invalid input");
    			     	exit(0);
    		}
    	
    	}
    	//taking input from the user
    	else if(inputChoice==2){
    		printf("enter the number of elements you want to enter: ");
    		scanf("%d",&n);
    		switch(dataType){
    			case 1: for(i=0;i<n;i++){
    					printf("enter the element in %dth index : " ,i);
    					scanf("%d",&arr[i]);
    		       	}
    			       break;
    			case 2: for(i=0;i<n;i++){
    					printf("enter the element in %dth index : " ,i);
    					scanf(" %c",&arr1[i]);
    				}
    				break;
    			default: printf("invalid input");
    			     	exit(0);
    		}
    	
    	
    	}
    	//taking input from file
    	else if(inputChoice==3){
    		
    		fptr = fopen("./inputFile.txt","r");
    		if(fptr== NULL){
    			printf("the file doesnt exist");
    			exit(0);	
    		}
    		else{
    			fscanf(fptr,"%d",&n); // number of values
    			switch(dataType){
    			case 1: for(i=0;i<n;i++){
    					//printf("enter the element in %dth index : " ,i);
    					fscanf(fptr,"%d",&arr[i]);
    		       	}
    			       break;
    			case 2: for(i=0;i<n;i++){
    					//printf("enter the element in %dth index : " ,i);
    					arr1[i]=fgetc(fptr);
    				}
    				break;
    			default: printf("invalid input");
    			     	exit(0);
    		}
    		}
    	}
    	else{
    	printf("not a valid choice");
    	}
    		
    	 
    //selecting type of sort to be used 
    	printf("Enter the sort you want to use for the sorting : ");
	printf("\n1.Selection sort \n 2.bubble sort \n3.insertion sort ");
	scanf("%d",&sortChoice);
	start=time(NULL);
    if(dataType==1){
    //choose the type of sort you want to use on integer input
    switch(sortChoice){
    	case 1:
    		selection_sort(arr,n);
    		break;
    	case 2:
    		bubble_sort(arr,n);
    		break;
    	case 3:
    		insertion_sort(arr,n);
    		break;
    	case 4: 
    		radixSort(arr,n);
    		break;
    	case 5:
    		quickSort(arr,0,n-1);
    	default:
    		printf("not a valid input of choice ");
    		exit(0);
    	}
    	
    }
    else {
    	//choosing the kind of sort we want to use on character array
    	switch(sortChoice){
    		case 1:
    			selection_sort_c(arr1,n);
    			break;
    		case 2:
    			//bubble_sort_c(arr1,n);
    			break;
    		case 3:
    			//insertion_sort_c(arr1,n);
    			break;
    		case 4: break;
    		case 5: quickSort_c(arr1,0,n-1); 
    		default:
    			printf("not a valid input of choice ");
    			exit(0);
    		}
    
    }
    
    end= time(NULL);
    //output the sorted data
    if(inputChoice==1 || inputChoice==2){
    
    	if(dataType==1){
    		printf("output : ");
    		for(i=0;i<n;i++){
    			printf("%d ",arr[i]);
    		}
    	}
    	else if(dataType==2){
    		printf("output : ");
    		for(i=0;i<n;i++){
    			printf("%c ",arr1[i]);
    		}
    	
    	}
    
    }
    else if(inputChoice==3){
    
    	FILE *fp;
    	fp = fopen("output.txt","w");
    if(dataType==1){
    		
    		for(i=0;i<n;i++){
    			fprintf(fp,"%d\t",arr[i]);
    		}
    	}
    	else if(dataType==2){
    		for(i=0;i<n;i++){
    			fprintf(fp,"%c\t",arr1[i]);
    		}
    	
    	}
    //output the data in a file
    		
    		printf("\nOutput has been written in the file output.txt\n");
    		fclose(fp);
    
    }
    printf("\n");
    printf("time taken to sort - %.10f seconds",difftime(end,start));
    
    return 0;
}
