//Name - Madhur Bajpai
//Reg. No.- 2022CA047
//Date- 31/01/2023

#ifndef POLY_QUEUE_H
#define POLY_QUEUE_H
#include<stdio.h>

#define size 20
//globally declare the variables

int front = 0, rear = -1;

//push function to push at the end
void push(int queue[]){
	//check if the queue is full
	if(rear==size-1)
		printf("\nThe queue is overflowed...\n");
	else{
		rear++;
		int temp;
		printf("\nEnter the value to be entered...\n");
		scanf("%d",&temp);
		queue[rear] = temp;
	}
}

//pop function to pop at front
void pop(int queue[]){
	//check if the queue is empty
	if(front>rear)
		printf("\nThe queue is empty...\n");
	else{
		int temp = queue[front];
		front++;
		printf("\n%d popped...",temp);
	}
}

//function to traverse the queue
void traverse(int queue[]){
	if(front>rear)
		printf("\nThe queue is empty..\n");
	else{
		int i;
		printf("\nThe queue is: \n");
		for(i = front; i <= rear; i++)
			printf("%d -> ",queue[i]);
		printf("NULL");
	}
}
#endif