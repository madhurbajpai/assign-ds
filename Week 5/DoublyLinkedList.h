/*
Name: Madhur Bajpai
Reg. No.: 2022ca047
Date: 7-2-23
Objective: To define a doubly linked list which can be used later on
*/


#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

//Node of doubly linked list having next and previous pointer
typedef struct DNode {
	int data;
	struct DNode* next, *prev;
}DNode;

//doubly linked list structure to maintain two pointer head and tail for better time complexity and size
typedef struct DoublyLinkedList{
	DNode *head;
	DNode *tail;
	int size;
}DoublyLinkedList;


// to check if the function is empty or not
int isEmpty_dll(DoublyLinkedList *ptr){
	if(ptr->size==0)
		return 1;
	else
		return 0;
}


//adding at the back of the doubly linked list
void add_back_dll(DoublyLinkedList *ptr, int data){
	DNode *node = (DNode*)malloc(sizeof(DNode));
	node->data=data;
	node->next=NULL;
	
	//if null linked list
	if(isEmpty_dll(ptr)){
		ptr->head=node;
		ptr->head->prev=NULL;
		ptr->tail=ptr->head;
	}
	
	//else just add to tail
	else{
		ptr->tail->next=node;
		node->prev=ptr->tail;
		ptr->tail=node;
	}
	ptr->size++;
}

//adding to the front of the doubly linked list
void add_front_dll(DoublyLinkedList *ptr, int data){
	DNode *node = (DNode*)malloc(sizeof(DNode));
	node->data=data;
	node->prev=NULL;
	
	//if null linked list
	if(isEmpty_dll(ptr)){
		ptr->head=node;
		ptr->head->next=NULL;
		ptr->tail=ptr->head;
	}
	
	//if non null linked list just add the node to head
	else{
		node->next=ptr->head;
		ptr->head->prev=node;
		ptr->head=node;
	}
	ptr->size++;
}

//insert the node at some position pos
int insert_dll(DoublyLinkedList *ptr, int data, int pos){
	//checking if the position is correct
	if(pos<=0||pos>(ptr->size+1))
		return 0;
	//adding to front if pos is at start
	else if(pos==1){
		add_front_dll(ptr, data);
	}
	//adding to end if pos is at end
	else if(pos==ptr->size+1){
		add_back_dll(ptr, data);
	}
	
	//adding in middle
	else{
		//finding the node
		DNode *temp=ptr->head;
		for(int i=2;i<pos;i++){
			temp=temp->next;
		}
		//inserting the elements by adjusting the element links
		DNode *temp2=temp->next;
		DNode *node = (DNode*)malloc(sizeof(DNode));
		node->data=data;
		temp->next=node;
		node->next=temp2;
		temp2->prev=node;
		node->prev=temp;
		ptr->size++;
	}
	return 1;
}


// deleting from front by unlinking the element at the head and freeing it afterwards
int delete_front_dll(DoublyLinkedList *ptr){
	//if isempty then return false
	if(isEmpty_dll(ptr)){
		return 0;
	}
	//if size is 1 along with head change the tail pointer too after deletion
	else if(ptr->size==1){
		DNode *temp= ptr->head;
		ptr->head=ptr->tail=NULL;
		free(temp);
		ptr->size--;
		return 1;
	}
	//changing only head pointer after deletion
	else{
		DNode *temp= ptr->head;
		ptr->head=ptr->head->next;
		temp->next=NULL;
		ptr->head->prev=NULL;
		free(temp);
		ptr->size--;
		return 1;
	}
}

//deleting from the end of the linked list and freeing it afterwards
int delete_back_dll(DoublyLinkedList *ptr){

	//if its empty
	if(isEmpty_dll(ptr)){
		return 0;
	}
	//if its size is 1 then change both head and tail
	else if(ptr->size==1){
		DNode *temp= ptr->head;
		ptr->head=ptr->tail=NULL;
		free(temp);
		ptr->size--;
		return 1;
	}
	//if its size is more than 1
	else{
		DNode *temp = ptr->tail;
		ptr->tail = ptr->tail->prev;
		ptr->tail->next=NULL;
		temp->prev=NULL;
		free(temp);
		ptr->size--;
		return 1;
	}
}

//deleting from the linked list at some position pos
int delete_dll(DoublyLinkedList *ptr, int pos){
	//checking position
	if(pos<=0||pos>ptr->size)
		return 0;
	//calling front and end function according to index provided
	else if(pos==1){
		return delete_front_dll(ptr);
	}
	else if(pos==ptr->size){
		return delete_back_dll(ptr);
	}
	//position is in middle
	else{
		//parse till the index
		DNode *temp = ptr->head;
		for(int i=1;i<pos;i++)
			temp=temp->next;
		//unlinking the node and deleting the element
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		temp->prev=NULL;
		temp->next = NULL;
		free(temp);
		ptr->size--;
		return 1;
	}
}


//displaying the doubly linked list
void display_dll(DoublyLinkedList *ptr){
	if(ptr->size==0){
		printf("NULL\n");
	}
	else{
		//parsing the whole doubly linked list
		printf("DOUBLY LINKED LIST: ");
		DNode*temp=ptr->head;
		while(temp->next!=NULL){
			printf("%d <-> ",temp->data);
			temp=temp->next;
		}
		printf("%d\n",temp->data);
	}
}

//concatenating second list provided to the first one
void concatenate_dll(DoublyLinkedList *ptr, DoublyLinkedList *dll){
	//changing the links and joining end of first linked list to start of second and prev pointer from second one to tail of first one
	ptr->tail->next=dll->head;
	dll->head->prev=ptr->tail;
	ptr->tail=dll->tail;
	//intializing the doubly linked list to null so it cant be changed
	dll->head=NULL;
	dll->tail=NULL;
	ptr->size+=dll->size;
	dll->size=0;
}

#endif
