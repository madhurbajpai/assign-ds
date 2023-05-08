/*
	Name : Madhur Bajpai
	Reg No: 2022CA047
	
	Topic : Implementation of Binary Search tree and demonstration of insertion and deletion of element
	
	Date : 21/02/2023
*/
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int key;				// Node Structure 
    struct Node *left, *right;
};

// Function to create a new node
struct Node *newNode(int item)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));			//Creating a new node by allocating new memory
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to insert a new node
struct Node *insert(struct Node *node, int key)
{
    // If the tree is empty, return a new node
    if (node == NULL)
        return newNode(key);

    // Otherwise, recur down the tree
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    // Return the (changed) node pointer
    return node;
}

// Function to find the minimum value in a node
struct Node *minValueNode(struct Node *node)
{
    struct Node *current = node;

    // Loop down to find the leftmost leaf
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

// Function to delete a node
struct Node *deleteNode(struct Node *root, int key)
{
    // Base case
    if (root == NULL)
        return root;

    // If the key to be deleted is smaller than the root's key,
    // then it lies in the left subtree
    if (key < root->key)
        root->left = deleteNode(root->left, key);

    // If the key to be deleted is greater than the root's key,
    // then it lies in the right subtree
    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    // If key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // Node with only one child or no child
        if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest
        // in the right subtree)
        struct Node *temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->key = temp->key;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// Function to traverse the binary search tree in-order and print the keys
void inOrderTraversal(struct Node *node)
{
    if (node != NULL)
    {
        inOrderTraversal(node->left);
        printf("%d ", node->key);
        inOrderTraversal(node->right);
    }
}

// Driver program to test above functions
int main()
{
    struct Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("In-order traversal of the given tree: ");
    inOrderTraversal(root);

    printf("\n\nDeleting 17\n");
    root = deleteNode(root, 70);
    printf("\nIn-order traversal after deletion of 20: ");
    inOrderTraversal(root);
    printf("\n\nDeleting 30\n");
    root = deleteNode(root, 30);
    printf("In-order traversal after deletion of 30: ");
    inOrderTraversal(root);

    printf("\n\nDeleting 50\n");
    root = deleteNode(root, 50);
    printf("In-order traversal after deletion of 50: ");
    inOrderTraversal(root);

    return 0;
}
