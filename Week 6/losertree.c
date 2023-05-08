//Name - Madhur Bajpai
//Reg. No. 2022CA047
//Date - 14/02/2023

// Objective - Implementation of Loser tree

#include<stdio.h>

// functions
void input(int i, int n);		//to take input players
void construct(int i, int j);	//to construct winner tree as well as loser tree
void print(int ar[], int n);	//to print both the trees

int arr[100];	//to store players and winner tree
int loser[100];	//to store loser tree

// MAIN FUNCTION
void main()
{
	// take input number of players and those must be in the power of 2
	int n;
	printf("Enter number of players (must be  in the power of 2): ");
	scanf("%d", &n);
	if (n<1) {
		printf("Number of players can't be smaller than 1");
		return;
	}
	input(n, 2*n);

	construct(2*n-1, n-1); //calling function to construct the tree

	// output
	printf("Winner Tree :-\n");
	print(arr, 2*n);
	printf("\nLoser Tree :-\n%d\n", loser[0]);
	print(loser, 2*n);
}


// Function to take input players (or leaf nodes of tree)
void input(int i, int n) {
	printf("Now enter players value :-\n");
	while (i < n) {
		scanf("%d", &arr[i]);
		loser[i] = arr[i];	//also store those nodes in loser array
		i++;
	}
}

// Function to construct both the trees winner and loser at the same time
void construct(int i, int j) {
	while (i > 2) {
		if (arr[i] < arr[i-1]) {
			arr[j] = arr[i];		//winner is the smaller number
			loser[j] = arr[i-1];	//loser is the larger number
		} else {
			arr[j] = arr[i-1];
			loser[j] = arr[i];
		}
		i -= 2;
		j--;
	}
	loser[0] = arr[1];		//on top of loser tree, it will store the winner and then the loser will start
}

// Function to print the trees
void print(int ar[], int n) {
	int i=1, j;
	while (i < n) {
		for (j=i; j<i*2; j++) {
			printf("%d ", ar[j]);
		}
		printf("\n");
		i = j;
	}
}