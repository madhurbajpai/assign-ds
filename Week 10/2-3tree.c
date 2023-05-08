//Name: Madhur Bajpai      
//Reg. No. - 2022ca047        
//Date - 17/03/2023

// Objective - Implementation of 2-3 tree


#include <stdio.h>
#include <stdlib.h>

// Define a structure for each node in the 2-3 Tree
struct Node
{
    int data1;
    int data2;
    struct Node *left;
    struct Node *middle;
    struct Node *right;
};

// Function to create a new node with given data
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data1 = data;
    newNode->data2 = -1;
    newNode->left = NULL;
    newNode->middle = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the 2-3 Tree
struct Node *insertValue(struct Node *root, int data)
{
    // If the root is empty, create a new node and return it as the root
    if (root == NULL)
        return createNode(data);

    // If the value to be inserted already exists in the tree, return the root
    if (root->data1 == data || root->data2 == data)
        return root;

    // If the root has only one data value
    if (root->data2 == -1)
    {
        // If the value to be inserted is less than the root's data value
        if (data < root->data1)
            root->left = insertValue(root->left, data);
        // If the value to be inserted is greater than the root's data value
        else
            root->right = insertValue(root->right, data);
    }
    // If the root has two data values
    else
    {
        // If the value to be inserted is less than the root's left data value
        if (data < root->data1)
        {
            root->left = insertValue(root->left, data);
        }
        // If the value to be inserted is greater than the root's right data value
        else if (data > root->data2)
        {
            root->right = insertValue(root->right, data);
        }
        // If the value to be inserted is between the root's two data values
        else
        {
            root->middle = insertValue(root->middle, data);
        }

        // Split the node if it has two data values after inserting the new value
        if (root->middle != NULL)
        {
            // Create a new node to hold the right data value
            struct Node *newNode = createNode(root->data2);

            // Set the left and middle children of the new node to the right and middle children of the root node
            newNode->left = root->middle;
            newNode->middle = root->right;

            // Set the root node's right data value to -1 and its right child to NULL
            root->data2 = -1;
            root->right = NULL;

            // Set the middle child of the root node to the new node
            root->middle = newNode;
        }
    }

    return root;
}

// Function to print the 2-3 Tree in in-order traversal
void printInOrderTraversal(struct Node *node)
{
    if (node == NULL)
        return;

    printInOrderTraversal(node->left);

    if (node->data2 == -1)
        printf("%d ", node->data1);
    else
        printf("%d %d ", node->data1, node->data2);

    printInOrderTraversal(node->middle);
    printInOrderTraversal(node->right);
}

// Driver function to test the 2-3 Tree implementation
int main()
{
    struct Node *root = NULL;
    // Insert some values into the 2-3 Tree
    root = insertValue(root, 10);
    root = insertValue(root, 20);
    root = insertValue(root, 30);
    root = insertValue(root, 40);
    root = insertValue(root, 50);
    root = insertValue(root, 60);
    root = insertValue(root, 70);
    root = insertValue(root, 80);
    root = insertValue(root, 90);
    root = insertValue(root, 100);

    // Print the 2-3 Tree in in-order traversal
    printInOrderTraversal(root);

    return 0;
}