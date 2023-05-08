//Name - Madhur Bajpai
//Reg. No. - 2022ca047
//Date - 25/04/2023

//Objective - Implements Order Statistics tree

#include <stdio.h>
#include <stdlib.h>


//Defining the node for the order statistics tree
typedef struct Node {
    int key;
    int size;  // Size of the subtree rooted at this node
    struct Node *left, *right;
} Node;

// Helper function to create a new node
Node* newNode(int key) {
	//allocating memory for the node
    Node* node = (Node*) malloc(sizeof(Node));
	//initialising the value of the key to the provided key
    node->key = key;
	//initialising the size of the node = 1
    node->size = 1;
    //initialising the left and right child to NULL
    node->left = NULL;
    node->right = NULL;
	//returning the node
    return node;
}

// Helper function to update the size of a node
void updateSize(Node* node) {
    node->size = 1;
    //traversing through the lead node and calculating the size
    if (node->left != NULL) node->size += node->left->size;
    if (node->right != NULL) node->size += node->right->size;
}

// Helper function to insert a key into the tree
Node* insert(Node* root, int key) {
	//base case for the insertion in order statistics tree
    if (root == NULL) return newNode(key);

	//if key is less than the current node then traverse through
	//left subtree
    if (key < root->key) {
        root->left = insert(root->left, key);
    } 
	//else key is greater than the current node then traverse through the
	//right subtree
    else {
        root->right = insert(root->right, key);
    }

	//after inssertion update the size for each node
    updateSize(root);
    //return the root node
    return root;
}

// Helper function to find the kth order statistic in the tree
int kthSmallest(Node* root, int k) {
	//base case
    if (root == NULL) return -1;

    int leftSize = (root->left != NULL) ? root->left->size : 0;

    if (k == leftSize + 1) {
        return root->key;
    } else if (k <= leftSize) {
        return kthSmallest(root->left, k);
    } else {
        return kthSmallest(root->right, k - leftSize - 1);
    }
}

// Driver function
int main() {
    Node* root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 60);
    root = insert(root, 70);
    root = insert(root, 80);
    root = insert(root, 90);

    int k;
    printf("Enter the key for the smallest element: ");
    scanf("%d",&k);
    if(k > root->size) {
		printf("Invalid value!!\n");
		exit(0);
    }
    printf("%dth smallest element is %d\n", k, kthSmallest(root, k));

    return 0;
}