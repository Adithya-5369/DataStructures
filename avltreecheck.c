/* Question:-
Construct a code-snippet that accepts a pointer to the root node of a binary tree and returns true if the binary tree is an AVL tree, and returns false otherwise.
*/

#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int value;
    struct Node *left, *right;
} Node;

// Create a new node
Node* newNode(int value) {
    Node* node = malloc(sizeof(Node));
    if (node) {
        node->value = value;
        node->left = node->right = NULL;
    }
    return node;
}

// Max of two values
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Check AVL and get height
int checkAVL(Node* root, int* isBalanced) {
    if (!root) return 0;

    int leftHeight = checkAVL(root->left, isBalanced);
    int rightHeight = checkAVL(root->right, isBalanced);

    if (abs(leftHeight - rightHeight) > 1) 
        *isBalanced = 0;

    return 1 + max(leftHeight, rightHeight);
}

// Wrapper function
int isAVLTree(Node* root) {
    int isBalanced = 1;
    checkAVL(root, &isBalanced);
    return isBalanced;
}

// Main
int main() {
    Node* root = newNode(20);
    root->left = newNode(10);
    root->right = newNode(30);
    root->left->left = newNode(5);
    root->left->right = newNode(15);

    printf(isAVLTree(root) ? "The tree is AVL.\n" : "The tree is NOT AVL.\n");

    return 0;
}