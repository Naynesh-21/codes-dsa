#include <bits/stdc++.h>
using namespace std;
 
/* Node Structure in a threaded binary tree */
struct Node{
    int value;
    Node *left, *right;
    bool rightThread;
};
 
// Converts tree to threaded binary tree 
// using given root.
// Function finds rightmost child of root.
Node *convert(Node *root)
{
    // Base cases : Tree is empty or contains a single node
    if (root == NULL)
        return NULL;
    if (root->left == NULL && root->right == NULL)
        return root;
 
    // Find predecessor if it exists
    if (root->left != NULL)
    {
        // Find predecessor of root (Rightmost
        // child of left subtree)
        Node* a = convert(root->left);
 
        // Linking thread from predecessor to root.
        a->right = root;
        a->rightThread = true;
    }
 
    // If current node is rightmost child
    if (root->right == NULL)
        return root;
 
    // Return for right subtree.
    return convert(root->right);
}
 
// Function to return the leftmost node of root.
Node *leftmost(Node *root)
{
    while (root != NULL && root->left != NULL)
        root = root->left;
    return root;
}
 
// Function for inorder traversal of threaded binary tree
void inorder(Node *root)
{
    if (root == NULL) 
    return;
 
    // For finding the leftmost node in normal Binary Tree
    Node *current = leftmost(root);
 
    while (current != NULL)
    {
        cout << current->value << " ";
 
       // If this Node is threaded Node, 
        // then go to inorder successor
        if (current->rightThread)
            current = current->right;
 
       // Or go to the leftmost child in right subtree
        else 
            current = leftmost(current->right);
    }
}
 
// Function to create a new node
Node *newNode(int value)
{
    Node *temp = new Node;
    temp->left = temp->right = NULL;
    temp->value = value;
    return temp;
}
 
int main()
{
    Node* root = newNode(10);
    root->left = newNode(20);
    root->right = newNode(30);
    root->left->left = newNode(40);
    root->left->right = newNode(50);
    root->right->left = newNode(60);
    root->right->right = newNode(70);
 
    convert(root);
 
    cout << "Inorder traversal of created threaded binary tree is \n";
    inorder(root);
    return 0;
}
