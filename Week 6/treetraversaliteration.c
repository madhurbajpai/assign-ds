//Name- Madhur Bajpai
//Reg. No.- 2022ca047
//Date - 13/2/2023

//Objective-- Tree Traversal using iteration


#include <stdio.h>
#include <stdlib.h>

//structure for tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

//structure for stack
struct Stack {
    int size;
    int top;
    struct Node** array;
};

//creating the stack structure
struct Stack* createStack(int size) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->size = size;
    stack->top = -1;
    stack->array = (struct Node*)malloc(stack->size * sizeof(struct Node));
    return stack;
}

//to check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == stack->size - 1;
}

//to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

//function to push in stack
void push(struct Stack* stack, struct Node* node) {
    if (isFull(stack)) {
        return;
    }
    stack->array[++stack->top] = node;
}

//function to pop 
struct Node* pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        return NULL;
    }
    return stack->array[stack->top--];
}

//function for inorder traversal
void inorder(struct Node* root) {
    //creating structure stack of size 100
    struct Stack* stack = createStack(100);
    struct Node* current = root;
    while (current != NULL || !isEmpty(stack)) {
        while (current != NULL) {
            push(stack, current);
            current = current->left;
        }
        current = pop(stack);
        printf("%d ", current->data);
        current = current->right;
    }
    //releasing the memory
    free(stack);
}

//function for preorder traversal
void preorder(struct Node* root) {
    struct Stack* stack = createStack(100);
    push(stack, root);
    while (!isEmpty(stack)) {
        struct Node* current = pop(stack);
        printf("%d ", current->data);
        //pushing right child so that popping left can be done
        if (current->right != NULL) {
            push(stack, current->right);
        }
        if (current->left != NULL) {
            push(stack, current->left);
        }
    }
    //releasing the memory
    free(stack);
}

//function for postorder traversal
void postorder(struct Node* root) {
    //creating stack structure of size 100
    struct Stack* stack1 = createStack(100);
    struct Stack* stack2 = createStack(100);
    push(stack1, root);
    while (!isEmpty(stack1)) {
        struct Node* current = pop(stack1);
        push(stack2, current);
        if (current->left != NULL) {
            push(stack1, current->left);
        }
        if (current->right != NULL) {
            push(stack1, current->right);
        }
    }
    while (!isEmpty(stack2)) {
        struct Node* current = pop(stack2);
        printf("%d ", current->data);
    }
    //releasing the memory
    free(stack1);
    free(stack2);
}

//function to create the node for tree
struct Node* createNode(int data) {\
//allocating memory for the node
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main() {

    //creating tree 
    /*
                1
            /       \
            2         3
         /    \     /   \
        4      5   6     7
      /     \     
     8       9  
    */
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    root->left->left->left = createNode(8);
    root->left->left->right = createNode(9);

    printf("\n---Inorder traversal---\n");
    //calling the inorder function
    inorder(root);
    printf("\n");

    printf("\n---Preorder traversal---\n");
    //calling the preorder function
    preorder(root);
    printf("\n");

    printf("\n---Postorder traversal---\n");
    //calling the postorder function
    postorder(root);
    printf("\n");

    return 0;
}