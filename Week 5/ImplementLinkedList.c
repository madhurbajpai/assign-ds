/*
Name: Madhur Bajpai
Reg. No.: 2022ca047
Date: 10-2-23
Objective: To show the implementation of linked list of both type singly and doubly
*/

//including the header files
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"


//driver function
int main(int argc, char **argv){	
	int listType , choice;
	
	//taking the type of linked list one want to create
	printf("Type of Linked list you want to create: \n1.Singly Linked List \n2.Doubly Linked List \n");
	scanf("%d",&listType);
	
	//If the list type is inputted as singly linked list
	if(listType==1){
	
		//intializing the Singly Linked list
		SinglyLinkedList ll;
		ll.head=NULL;
		ll.size=0;
		
		//taking user input until user presses zero
		int flag=1;
		while(flag){
		
			//displaying the singly linked list
			display_sll(&ll);
			
			//type of operation to be done
			printf("Enter the type of operation you want to do: \n1.Insert \n2.Delete \n3.Concat\n(0 to exit)\n");
			scanf("%d", &choice);
			
			switch(choice){
				
				//insert operation
				case 1:{
					int n,val;
					
					//taking value and position
					printf("Enter the value you want to insert:");
					scanf("%d",&val);
					printf("Enter the index you want to add the value:");
					scanf("%d",&n);
					
					//calling insert function of singly linked list
					int status=insert_sll(&ll,val,n);
					
					//checking if it successfully added or not
					if(status)
						printf("SUCCESS!!\n");
					else
						printf("FAILED!! PLEASE RECHECK!!\n");
					break;
				}
					
				//deletion operation
				case 2:{
					int n;

					//inputting index from user to delete the node
					printf("Enter the index you want to delete the node from:");
					scanf("%d",&n);
					
					//calling function and checking the status whether it is successfully deleted or not
					int status=delete_sll(&ll,n);
					if(status)
						printf("SUCCESS!!\n");
					else
						printf("FAILED!! PLEASE RECHECK!!\n");
					break;
				}
				
				//concatenating operation
				case 3:{
					
					//declaring the new variables along with new singly linked list
					int n,val;
					SinglyLinkedList ll2;
					ll2.head=NULL;
					ll2.size=0;
					
					//inputting new linked list's size
					printf("Enter the size of the new singly linked list:");
					scanf("%d",&n);
					
					//intializing the linked list which is to be appended
					for(int i=0;i<n;i++){
						printf("Enter element %d:",i+1);
						scanf("%d",&val);
						add_back_sll(&ll2,val);
					}
					
					//calling concatenate function to concatenate the two linked list
					concatenate_sll(&ll,&ll2);
					printf("CONCATENATION COMPLETE!!\n");
					break;
				}
				
				//to break the loop
				case 0:{
					flag=0;
					break;
				}
				
				//default choice
				default: printf("WRONG CHOICE INPUTTED!!!");
			}
			printf("\n\n");
		}
	}
	else if(listType==2){
	
		//intializing the Doubly Linked list
		DoublyLinkedList ll;
		ll.head=NULL;
		ll.tail=NULL;
		ll.size=0;
		
		//taking user input until user presses zero
		int flag=1;
		while(flag){
		
			//displaying the doubly linked list
			display_dll(&ll);
			
			//type of operation to be done
			printf("Enter the type of operation you want to do: \n1.Insert \n2.Delete \n3.Concat\n(0 to exit)\n");
			scanf("%d", &choice);
			
			switch(choice){
				
				//insert operation
				case 1:{
					int n,val;
					
					//taking value and position
					printf("Enter the value you want to insert:");
					scanf("%d",&val);
					printf("Enter the index you want to add the value:");
					scanf("%d",&n);
					
					//calling insert function of singly linked list
					int status=insert_dll(&ll,val,n);
					
					//checking if it successfully added or not
					if(status)
						printf("SUCCESS!!\n");
					else
						printf("FAILED!! PLEASE RECHECK!!\n");
					break;
				}
					
				//deletion operation
				case 2:{
					int n;

					//inputting index from user to delete the node
					printf("Enter the index you want to delete the node from:");
					scanf("%d",&n);
					
					//calling function and checking the status whether it is successfully deleted or not
					int status=delete_dll(&ll,n);
					if(status)
						printf("SUCCESS!!\n");
					else
						printf("FAILED!! PLEASE RECHECK!!\n");
					break;
				}
				
				//concatenating operation
				case 3:{
					
					//declaring the new variables along with new Doubly linked list
					int n,val;
					DoublyLinkedList ll2;
					ll2.head=NULL;
					ll2.tail=NULL;
					ll2.size=0;
					
					//inputting new linked list's size
					printf("Enter the size of the new Doubly linked list:");
					scanf("%d",&n);
					
					//intializing the linked list which is to be appended
					for(int i=0;i<n;i++){
						printf("Enter element %d:",i+1);
						scanf("%d",&val);
						add_back_dll(&ll2,val);
					}
					
					//calling concatenate function to concatenate the two doubly linked list
					concatenate_dll(&ll,&ll2);
					printf("CONCATENATION COMPLETE!!\n");
					break;
				}
				
				//to break the loop
				case 0:{
					flag=0;
					break;
				}
				
				//default choice
				default: printf("WRONG CHOICE INPUTTED!!!");
			}
			printf("\n\n");
		}
	}
	else{
		printf("Wrong choice");
	}
	return 0;
}
