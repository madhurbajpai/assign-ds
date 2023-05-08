/*
Name: Madhur Bajpai
Reg. No.: 2022ca047
Date: 10-2-23
Objective: To define a Circular linked list which can be used later on
*/




#include<stdio.h>
#include<stdlib.h>
//Structure of Node
typedef struct NodeC
{
    int data;
    struct NodeC *next;

}NodeC;
//allocating memory to new nodes
NodeC *createNodeC(int data){
    NodeC *newNode = (NodeC*) malloc(sizeof(NodeC));
    //insering data in the new node
    newNode->data=data;
    newNode->next = NULL;
    return newNode;
}



//takes input as Position and node head and returns head pointer after deleting the node 
NodeC *delete(int position , NodeC *head){
        int count=1;
        NodeC *temp=head;
        //if head is NULL
        if(head==NULL){
            printf("\nList is empty\n");
        }
        //if head is to be deleted
        else if(position==1){
            while(temp->next != head){
                temp=temp->next;
            }
            //perfroming the link change
            NodeC *temp1;
            temp1=temp->next;
            temp->next=temp1->next;
            head=temp->next;
        }   
        else{
            //when deleting node is not head
            NodeC *temp1; 
            //finding the node just before the deleting node
            while(count < position-1 ){
            temp=temp->next;
            count++;
            }
            //performing the link change
            temp1=temp->next;
            temp->next=temp1->next;
            if(temp1==head){
                head=temp->next;
            }
        }
        return head;
}

//method to perform insertion in doubly linked list
NodeC *insertion(int data , int position, NodeC *head){
    //creating new Node
    NodeC *newNode = createNodeC(data);
    int count=1;
    NodeC *temp=head;
    //if Head is NULL
    if(head == NULL){
        printf("\ncreated a new Linked List(Circular)");
        head = newNode;
        newNode->next = head ;
    }
    //if Adding at first position , as a head 
    else if(position==1){
        //finding the node just before the head
        while(temp->next != head){
            temp=temp->next;
        }
        //perfoming the link change
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }
    //if position is other than first 
    else{
        //finding the node just before the position the new node is being added
        while(count < position-1 ){
            temp=temp->next;
            count++;
        }
       //performing the link change
        newNode->next = temp->next;
        temp->next = newNode;
    } 
    printf("\nadded a new node with data = %d \n",newNode->data);
    return head;

}

//function to display the data of linked list
void display(NodeC *head){
    NodeC *temp=head;
    //looping through all the nodes in the linked list 
    do{
        printf("%d ",temp->data);
        temp=temp->next;
    }while(temp != head );
    
}
//performing the merge
NodeC *merge(NodeC *head1,NodeC *head2){
    //if either head is NULL no merging
    if(head1==NULL || head2==NULL){
        printf("Circular list 1 is NULL");
        return NULL;
    }
    //finding the element just before the head in both linked list
    NodeC *temp1=head1;
    while(temp1->next != head1){
            temp1=temp1->next;
        }
    NodeC *temp2=head2;
    while(temp2->next != head2){
            temp2=temp2->next;
        }
    //performing the merge
    temp1->next=head2;
    temp2->next=head1;
    return head1;
    
}
