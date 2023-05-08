//Name- Madhur Bajpai
//Reg. No.- 2022ca047
//Date - 13/2/2023

//Objective-- Tree Traversal using recursion


#include<stdio.h>
#include<stdlib.h>

//tree structure

struct tree{
    //data in node
    int data;

    //left child
    struct tree* left;

    //right child
    struct tree* right;
};


//initialising the root node
//struct tree* root = NULL;

//function to create a node
struct tree* newnode(int val){
    //create a new node
    struct tree* newnode;
    //allocate the memory
    newnode = (struct tree*)malloc(sizeof(struct tree));
   
    //initialising the value 
    newnode->data = val;

    //initialising the left child
    newnode->left = NULL;

    //initialising right node
    newnode->right = NULL;

    return newnode;

}




//preorder traversal
void preorder(struct tree* root){
    
    //base case if root is null
    if(root==NULL)
    return ;

    //first traverse the root node
    printf("%d ",root->data);
    //second traverse the left subtree recursively
    preorder(root->left);
    //third traverse the right subtree recursively
    preorder(root->right);
}

//inorder traversal
void inorder(struct tree* root){
    //base case if root is null
    if(root==NULL)
    return ;
    //first traverse the left subtree recursilvely.
    inorder(root->left);
    //second traverse the root node
    printf("%d ",root->data);
    //third traverse the right subtree recursively
    inorder(root->right);
}

//postorder traversal
void postorder(struct tree *root){
    //base case if root is null
    if(root==NULL)
    return ;
    //first traverse the left subtree recursively
    postorder(root->left);
    //second traverse the right subtree recursively
    postorder(root->right);
    //third traverse the root node
    printf("%d ",root->data);
}
//main function
int main(){
    int choice;

     //creating a tree
    /*
                1
            /       \
            2         3
         /    \     /   \
        4      5   6     7
     /     \     
    8       9  
    */


    struct tree* root = NULL;
    root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    root->left->right->left = newnode(6);
    root->left->right->right = newnode(7);
    root->left->left->left = newnode(8);
    root->left->left->right = newnode(9);
    printf("\ntree created...");
                printf("\n----INORDER TRAVERSAL----\n");
                //calling inorder function
                inorder(root);
                printf("\n----PREORDER TRAVERSAL----\n");
                //calling preorder function
                preorder(root);
                printf("\n----POSTORDER TRAVERSAL----\n");
                //calling postorder function
                postorder(root);
    return 0;
}