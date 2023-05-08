//Name - Madhur Bajpai
//Reg. No. - 2022ca047
//Date - 11/04/2023


//Objective - Implementation of Deapth First search

/* Queue_h */
#include <stdio.h>
#include "queue.h"


//function for deapth first search
void DFS(int G[][7],int start,int n)
{
//to mark visited node in the graph create a integer array
 static int visited[7]={0};
 int j;
 if(visited[start]==0)
 {
 	printf("%d ",start);
 	visited[start]=1;
 	for(j=1;j<n;j++)
 	{
 		if(G[start][j]==1 && visited[j]==0)

 		//recursive call if current node is visited and the adjacent node is not visited
 		DFS(G,j,n);
 	}
 }
}

//main function
int main()
{
//intitalizing the graph
 int G[7][7]={
 			  {0,0,0,0,0,0,0},
 			  {0,0,1,1,0,0,0},
 			  {0,1,0,0,1,0,0},
 			  {0,1,0,0,1,0,0},
 			  {0,0,1,1,0,1,1},
 			  {0,0,0,0,1,0,0},
 			  {0,0,0,0,1,0,0}
 			 };

 // calling the dfs function
 printf("----Calling the deapth first search----\n");
 DFS(G,4,7);
 printf("\n");
 return 0;
}