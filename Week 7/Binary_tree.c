/*
	Name : Madhur Bajpai
	Reg No : 2022CA047
	
	Topic : Construction of Binary tree given the ndoe sequence for inorder and preorder or postorder traversals for the missing binary tree.
	
	Date : 21/02/2023 
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;				// Structure of node
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to search for the index of the given value in the given array
int search(int arr[], int start, int end, int value) {
    int i;
    for (i = start; i <= end; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

// Function to construct the binary tree given inorder and preorder traversals
struct Node* buildTree(int inorder[], int preorder[], int inStart, int inEnd) {
    static int preIndex = 0;

    if (inStart > inEnd) {
        return NULL;
    }

    // Create a new node with the current value in the preorder array
    struct Node* node = newNode(preorder[preIndex++]);

    // If there is only one element in the subtree, return the node
    if (inStart == inEnd) {
        return node;
    }

    // Find the index of the current node in the inorder array
    int inIndex = search(inorder, inStart, inEnd, node->data);

    // Recursively build the left and right subtrees
    node->left = buildTree(inorder, preorder, inStart, inIndex - 1);
    node->right = buildTree(inorder, preorder, inIndex + 1, inEnd);

    return node;
}

// Function to construct the binary tree given inorder and postorder traversals
struct Node* buildTreeFromPostorder(int inorder[], int postorder[], int inStart, int inEnd, int* postIndex) {
    if (inStart > inEnd) {
        return NULL;
    }

    // Create a new node with the current value in the postorder array
    struct Node* node = newNode(postorder[(*postIndex)--]);

    // If there is only one element in the subtree, return the node
    if (inStart == inEnd) {
        return node;
    }

    // Find the index of the current node in the inorder array
    int inIndex = search(inorder, inStart, inEnd, node->data);

    // Recursively build the right and left subtrees (in opposite order)
    node->right = buildTreeFromPostorder(inorder, postorder, inIndex + 1, inEnd, postIndex);
    node->left = buildTreeFromPostorder(inorder, postorder, inStart, inIndex - 1, postIndex);

    return node;
}

// Function to print the inorder traversal of the binary tree
void inorderTraversal(struct Node* node) {
    if (node == NULL) {
        return;
    }

    inorderTraversal(node->left);
    printf("%d ", node->data);
    inorderTraversal(node->right);
}

// Driver program to test the above functions
int main() {
    int inorder[] = { 4, 2, 5, 1, 3 };
    int preorder[] = { 1, 2, 4, 5, 3 };
    int postorder[] = { 4, 5, 2, 3, 1};
int n = sizeof(inorder) / sizeof(inorder[0]);

// Construct the binary tree from inorder and preorder traversals
struct Node* root = buildTree(inorder, preorder, 0, n - 1);

printf("Inorder traversal of the constructed tree (from inorder and preorder):\n");
inorderTraversal(root);
printf("\n");

// Construct the binary tree from inorder and postorder traversals
int postIndex = n - 1;
root = buildTreeFromPostorder(inorder, postorder, 0, n - 1, &postIndex);

printf("Inorder traversal of the constructed tree (from inorder and postorder):\n");
inorderTraversal(root);
printf("\n");

return 0;
}
