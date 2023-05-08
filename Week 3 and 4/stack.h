//Name - Madhur Bajpai
//Reg. No.- 2022CA047
//Date- 31/01/2023

#ifndef STACK_H
#define STACK_H
#include<stdio.h>

//globally declaration of top 
int top = -1;

//push function to add value at the top of the stack
void push(int stack[]){
	//check if stack is overflowed
	
	if(top == 20)
		printf("\nThe stack is overflowed.....");
	else{
		top++;
		int temp;
		printf("\nEnter the value to be pushed: ");
		scanf("%d",&temp);
		stack[top] = temp;
	}
}

//pop function to remove the element at the top of the stack
void pop(int stack[]){
	//check if the stack is empty
	
	if(top == -1)
		printf("\nThe stack is underflowed...");
	else{
		int temp;
		temp = stack[top];
		top--;
		printf("\n%d popped...\n",temp);
	}
}

//traverse function to show the stack

void traverse(int stack[]){
	int i;
	if(top == -1)
		printf("\nThe stack is empty..\n");
	else{
	printf("\nThe stack is:\n"); 
	for(i = top; i >= 0; i--){
		printf("\n|  %d  |\n--------\n",stack[i]);
	}
	}
}
#endif