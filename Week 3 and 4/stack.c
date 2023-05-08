//Name - Madhur Bajpai
//Reg. No.- 2022ca047
//Date - 31/01/2023


#include<stdio.h>
#include<stdlib.h>
#include "stack.h"

//main function

int main(){
	int stack[20];
	while(1){
		int choice;

        //menu for operation on the stack
		printf("\n1. Push\n2. Pop\n3. Traverse\n4. Exit\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
            //for pushing elements
				push(stack);
				break;
			case 2: 
            //for poping element
				pop(stack);
				break;
			case 3:
				traverse(stack);
				break;
			case 4:
				exit(0);
		}
	}
	return 0;
}