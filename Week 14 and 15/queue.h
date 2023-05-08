// Name - Madhur Bajpai
// Reg. No. - 2022ca047
// Date - 11/04/2023

// Objective - To Implement queue operatios

#ifndef queue_h
#define queue_h

#include <stdlib.h>

// Node structure
struct Node
{
    int data;
    struct Node *next;

}

    // initializing the front and rear pointer to NULL
    *front = NULL,
    *rear = NULL;

// function to enqueue
void enqueue(int x)
{
    struct Node *t;
    // allocating the memory
    t = (struct Node *)malloc(sizeof(struct Node));

    // check whether queue is full
    if (t == NULL)
        printf("Queue is FUll\n");
    else
    {
        t->data = x;
        t->next = NULL;
        if (front == NULL)
            front = rear = t;
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}
int dequeue()
{
    int x = -1;
    struct Node *t;

    if (front == NULL)
        printf("Queue is Empty\n");
    else
    {
        x = front->data;
        t = front;
        front = front->next;
        free(t);
    }
    return x;
}
int isEmpty()
{
    return front == NULL;
}
#endif