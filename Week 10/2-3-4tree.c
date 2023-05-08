// Name - Madhur Bajpai
//Reg. No. - 2022ca047
//Date - 17/03/2023

// Objective - Implementation of 2-3-4 tree

#include <stdio.h>
#include <stdlib.h>

// The maximum number of keys a node can hold
#define MAX_KEYS 3

// A node in the 2-3-4 tree
struct Node
{
    int num_keys;                        // The number of keys currently in the node
    int keys[MAX_KEYS];                  // The array of keys in the node
    struct Node *children[MAX_KEYS + 1]; // Pointers to the node's children
};

// Create a new node with no keys and no children
struct Node *create_node()
{
    struct Node *node = malloc(sizeof(struct Node));
    node->num_keys = 0;
    for (int i = 0; i < MAX_KEYS + 1; i++)
    {
        node->children[i] = NULL;
    }
    return node;
}

// Split a full node into two nodes, and return the new right node
struct Node *split_node(struct Node *node)
{
    // Create the new right node and move the second and third keys and children to it
    struct Node *right = create_node();
    right->num_keys = 1;
    right->keys[0] = node->keys[2];
    right->children[0] = node->children[2];
    right->children[1] = node->children[3];

    // Update the original node to contain only the first key and its two children
    node->num_keys = 1;
    node->children[2] = NULL;
    node->children[3] = NULL;

    return right;
}

// Insert a key into the tree rooted at root_ptr
void insert(struct Node **root_ptr, int key)
{
    // If the root is null, create a new node with the key as its only element and set it as the root
    if (*root_ptr == NULL)
    {
        *root_ptr = create_node();
        (*root_ptr)->num_keys = 1;
        (*root_ptr)->keys[0] = key;
        return;
    }

    struct Node *node = *root_ptr;
    struct Node *parent = NULL;

    // Traverse the tree to find the appropriate leaf node to insert the key
    while (node != NULL)
    {
        // If the node is full, split it and update the parent node
        if (node->num_keys == MAX_KEYS)
        {
            struct Node *right = split_node(node);
            if (parent == NULL)
            {
                // If the node is the root, create a new root and set the node and its right sibling as its children
                parent = create_node();
                parent->keys[0] = node->keys[1];
                parent->num_keys = 1;
                parent->children[0] = node;
                parent->children[1] = right;
                *root_ptr = parent;
            }
            else
            {
                // Otherwise, insert the new key and the right sibling into the parent node
                int i = parent->num_keys - 1;
                while (i >= 0 && parent->keys[i] > node->keys[1])
                {
                    parent->keys[i + 1] = parent->keys[i];
                    parent->children[i + 2] = parent->children[i + 1];
                    i--;
                }
                parent->keys[i + 1] = node->keys[1];
                parent->children[i + 1] = node;
                parent->children[i + 2] = right;
                parent->num_keys++;
            }
            // Move up to the parent node
            node = parent;
        }

        // If the key is less than the first key in the node, move to the left child
        if (key < node->keys[0])
        {
            parent = node;
            node = node->children[0];
            continue;
        }

        // If the key is greater than or equal to the last key in the node, move to the right child
        if (key >= node->keys[node->num_keys - 1])
        {
            parent = node;
            node = node->children[node->num_keys];
            continue;
        }

        // Otherwise, the key must be between the first and last keys in the node, so search for the correct child
        for (int i = 0; i < node->num_keys - 1; i++)
        {
            if (key >= node->keys[i] && key < node->keys[i + 1])
            {
                parent = node;
                node = node->children[i + 1];
                break;
            }
        }
    }

    // Create a new leaf node with the key and insert it into the parent node
    struct Node *leaf = create_node();
    leaf->num_keys = 1;
    leaf->keys[0] = key;

    int i = parent->num_keys - 1;
    while (i >= 0 && parent->keys[i] > key)
    {
        parent->keys[i + 1] = parent->keys[i];
        parent->children[i + 2] = parent->children[i + 1];
        i--;
    }
    parent->keys[i + 1] = key;
    parent->children[i + 2] = leaf;
    parent->num_keys++;
}

// Print the keys in the tree rooted at node in inorder traversal
void print_inorder(struct Node *node)
{
    if (node == NULL)
    {
        return;
    }
    for (int i = 0; i < node->num_keys; i++)
    {
        print_inorder(node->children[i]);
        printf("%d ", node->keys[i]);
    }
    print_inorder(node->children[node->num_keys]);
}

int main()
{
    // Initialize an empty tree
    struct Node *root = NULL;
    // Insert some keys into the tree
    insert(&root, 3);
    insert(&root, 1);
    insert(&root, 4);
    insert(&root, 2);
    insert(&root, 5);

    // Print the keys in the tree
    print_inorder(root);
    printf("\n");

    return 0;
}