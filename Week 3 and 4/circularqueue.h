// Name - Madhur Bajpai
// Reg. No.- 2022CA047
// Date- 31/01/2023

#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H
#include <stdio.h>

//define the max size queue can have
#define MAX 10
int queue[MAX];
int front = -1, rear = -1;

//insert function to insert the element in circular queue
void insert()
{
    int num;
    printf("\n Enter the number to be inserted in the queue : ");
    scanf("%d", &num);

    //to check if the queue is full
    if (front == 0 && rear == MAX - 1)
        printf("\n OVERFLOW");
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = num;
    }
    else if (rear == MAX - 1 && front != 0)
    {
        rear = 0;
        queue[rear] = num;
    }
    else
    {
        rear++;
        queue[rear] = num;
    }
}

//to delete the element from the queue
int delete_element()
{
    int val;

    //to check if the queue is empty
    if (front == -1 && rear == -1)
    {
        printf("\n UNDERFLOW");
        return -1;
    }
    val = queue[front];
    if (front == rear)
        front = rear = -1;
    else
    {
        if (front == MAX - 1)
            front = 0;
        else
            front++;
    }
    return val;
}

//to display the front element
int peek()
{
    //to check if the queue is empty
    if (front == -1 && rear == -1)
    {
        printf("\n QUEUE IS EMPTY");
        return -1;
    }
    else
    {
        return queue[front];
    }
}

//display the queue
void display()
{
    int i;
    printf("\n");
    if (front == -1 && rear == -1)
        printf("\n QUEUE IS EMPTY");
    else
    {
        if (front < rear)
        {
            for (i = front; i <= rear; i++)
                printf(" %d", queue[i]);
        }
        else
        {
            for (i = front; i < MAX; i++)
                printf(" %d", queue[i]);
            for (i = 0; i <= rear; i++)
                printf(" %d", queue[i]);
        }
    }
}
#endif