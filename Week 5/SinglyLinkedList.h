/*
Name: Madhur Bajpai
Reg. No.: 2022ca047
Date: 07/02/2023
Objective: To define a singly linked list which can be used later on
*/


#ifndef SINGLY_LINKED_LIST
#define SINGLY_LINKED_LIST

//Singly pointer node
typedef struct SNode {
	int data;
	struct SNode* next;
}SNode;



//Singly Linked List structure with single pointer to head
typedef struct SinglyLinkedList{
	SNode *head;
	int size;
}SinglyLinkedList;



//to check if the singly linked list is empty or not
int isEmpty_sll(SinglyLinkedList *ptr){
	if(ptr->head==NULL)
		return 1;
	else
		return false;
}


//adding value to start of the linked List
void add_front_sll(SinglyLinkedList *ptr, int data){
	
	//intializing the new node
	SNode *node = (SNode*)malloc(sizeof(SNode));
	node->data=data;
	
	//if the linked list has no element
	if(ptr->head==NULL){
		ptr->head=node;
		ptr->head->next=NULL;
	}
	//if the linked list already has some element
	else{
		node->next=ptr->head;
		ptr->head=node;
	}
	(ptr->size)++;
}

//adding to the end of the linked list
void add_back_sll(SinglyLinkedList *ptr, int data){

	//intializing the new node
	SNode *node = (SNode*)malloc(sizeof(SNode));
	node->data=data;
	
	//if the linked list has some element or not
	if(ptr->head==NULL){
		ptr->head=node;
		ptr->head->next=NULL;
	}
	else{
		//using loop to reach the end of the linked list since a single pointer to the head is used
		SNode *temp = ptr->head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		
		//adding the node
		temp->next=node;
		node->next=NULL;
	}
	(ptr->size)++;
}


//inserting at some random position
int insert_sll(SinglyLinkedList *ptr, int data, int pos){

	//if the index is out of bounds
	if(pos<=0||pos>(ptr->size+1))
		return 0;
		
	//if it is to be inserted at position 1 then call add front
	else if(pos==1){
		add_front_sll(ptr, data);
		return 1;
	}
	
	//if it is to be added at the end position call add back
	else if(pos==(ptr->size+1)){
		add_back_sll(ptr,data);
		return 1;
	}
	
	//adding to the mdiddle
	else{
		SNode *temp=ptr->head;
		for(int i=2;i<pos&&temp!=NULL;i++){
			temp=temp->next;
		}
		
		//index found now inserting the new element
		SNode *node = (SNode*)malloc(sizeof(SNode));
		node->data=data;
		node->next=temp->next;
		temp->next=node;
		(ptr->size)++;
		
		//returning 1 for successful addition of linked list
		return 1;
	}
}


//deleting the element from the front
int delete_front_sll(SinglyLinkedList *ptr){

	// if the linked list is empty notheing can be deleted
	if(isEmpty_sll(ptr)){
		return 0;
	}
	
	else{
		//deleting the element by shifting the heading and then freeing the memory allocated to that particular node
		SNode *temp= ptr->head;
		ptr->head=ptr->head->next;
		temp->next=NULL;
		free(temp);
		(ptr->size)--;
		//returning 1 for success in deleting the node
		return 1;
	}
}


//deleting from the end
int delete_back_sll(SinglyLinkedList *ptr){

	//if is empty then one cant delete anything
	if(isEmpty_sll(ptr)){
		return 0;
	}
	
	//if size is 1 call delete front since its the first and last element at the same time
	else if((ptr->size)==1){
		delete_front_sll(ptr);
	}
	
	else{
		//using temp to parse till the end of the array
		SNode *temp = ptr->head;
		while(temp->next->next!=NULL){
			temp=temp->next;
		}
		
		//deleting the node by unlinking then freeing the element
		SNode *temp2=temp->next;
		temp->next=NULL;
		free(temp2);
		(ptr->size)--;
		return 1;
	}
}

//deleting at index provided by user
int delete_sll(SinglyLinkedList *ptr, int pos){

	//position is in bound
	if(pos<=0||pos>(ptr->size))
		return 0;
		
	//to delete the front element
	else if(pos==1){
		return delete_front_sll(ptr);
	}
	
	//to delete the end element
	else if(pos==(ptr->size)){
		return delete_back_sll(ptr);
	}
	
	//to delete the element in the middle
	else{
		SNode *temp = ptr->head;
		
		//parsing to desired index
		for(int i=2;i<pos;i++)
			temp=temp->next;
			
		//unlinking then deleting the node
		SNode *temp2 = temp->next;
		temp->next=temp->next->next;
		free(temp2);
		(ptr->size)--;
		return 1;
	}
}


//displaying the singly linked list
void display_sll(SinglyLinkedList *ptr){
	printf("Size:%d\n",ptr->size);
	if((ptr->size)==0){
		printf("NULL\n");
	}
	else{
		printf("SINGLY LINKED LIST: ");
		SNode*temp=ptr->head;
		
		//looping through and printing the singly linked list
		while(temp->next!=NULL){
			printf("%d -> ",temp->data);
			temp=temp->next;
		}
		printf("%d\n",temp->data);
	}
}


//concatenating the singly linked list
void concatenate_sll(SinglyLinkedList *ptr, SinglyLinkedList *sll){
	if(ptr->head==NULL){
		ptr->head=sll->head;
	}
	else{
		//using loop to reach the end of the linked list since a single pointer to the head is used
		SNode *temp = ptr->head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		//adding the new linked list
		temp->next=sll->head;
	}
	sll->head=NULL;
	ptr->size+=sll->size;
	sll->size=0;
}

#endif
