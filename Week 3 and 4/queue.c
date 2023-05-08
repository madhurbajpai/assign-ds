//Name - Madhur Bajpai
//Reg. No. - 2022ca047
//Date-31/01/2023

#include<stdio.h>
#include<stdlib.h>
#include "queue.h"
#define size 20

//main function

int main(){
	//declaration of the queue
	int queue[size];

	//infinte loop to enter values
	while(1){
		int choice;
		printf("\n1. Push\n2. Pop\n3. Traverse\n4. Exit\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				push(queue);
				break;
			case 2: 
				pop(queue);
				break;
			case 3:
				traverse(queue);
				break;
			case 4:
				exit(0);
		}
	}
	return 0;
}