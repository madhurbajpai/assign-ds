//Name - Madhur Bajpai
//Reg. No. - 2022ca047
//Date - 11/04/2023


//Objective - Implementation of Breadth First search

/* Queue_h */
#include <stdio.h>
#include "queue.h"

//function for breadth first search
void BFS(int G[][7],int start,int n)
{
 int i=start,j;
 int visited[7]={0};
 printf("%d ",i);
 visited[i]=1;
 enqueue(i);
 while(!isEmpty())
 {
    i=dequeue();
    for(j=1;j<n;j++)
    {
        if(G[i][j]==1 && visited[j]==0)
        {
            printf("%d ",j);
            visited[j]=1;
            enqueue(j);
        }
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
 printf("----Calling the breadth first search----\n");
 BFS(G,4,7);
 printf("\n");
 return 0;
}