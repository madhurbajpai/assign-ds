/*
Name: Madhur Bajpai
Reg. No.: 2022ca047
Date: 10-2-23
Objective: To define a Circular linked list which can be used later on
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "CircularLink.h"

int main(int argc, char **argv){	
	
	int choice =-1;
	NodeC *head[2];
	head[0]=NULL;
	head[1]=NULL;
	int num;
	int position;
	while(choice !=0){
		printf("press \n 1 to enter operate on circular linked list 1 \n 2 to operate on circular linked list 2 \n3 to merge them into circular linked list 1\n 0 exit");
		scanf("%d",&choice);
		int choice2=-1;
		if(choice == 3){
			head[0]=merge(head[0],head[1]);
			display(head[0]);
			continue;
		}
		while(choice2!=0){
			printf("press \n1 to insert a value \n2 to delete \n3 to display \n0 exit to main menu ");
			scanf("%d",&choice2);
			switch(choice2){
				
				case 1 : 
						printf("\nenter the data you want to enter into the linked list\n");
						scanf("%d",&num);
						printf("the position you want ot enter this data at\n");
						scanf("%d",&position);
						head[choice-1]= insertion(num,position,head[choice-1]);
						break;
				case 2: 
						printf("the position where you want to delete \n");
						scanf("%d",&position);
						head[choice-1]= delete(position,head[choice-1]);
						break;
				case 3: printf("\nCircular Linked List %d\n",choice);
						display(head[choice-1]);
						printf("\n");
						break;
			}
		}


	}

}
