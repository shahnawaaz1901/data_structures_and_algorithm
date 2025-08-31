#include <bits/stdc++.h>
using namespace std;

// Problem : https://www.geeksforgeeks.org/problems/search-a-node-in-bst/1

struct Node
{
    int data;
    Node *right;
    Node *left;

    Node(int x)
    {
        data = x;
        right = NULL;
        left = NULL;
    }
};

// Bruteforce Approach with O(n) Time Complexity and O(h) Space Comlexity
bool search(Node *root, int x)
{
    // Your code here
    if (root == NULL)
    {
        return false;
    }

    if (root->data == x)
    {
        return true;
    }

    return search(root->left, x) || search(root->right, x);
}

// Optimal Approach with O(logn) Time Complexity and O(h) Space Complexity
bool search(Node *root, int x)
{
    // Your code here
    if (root == NULL)
    {
        return false;
    }

    if (root->data == x)
    {
        return true;
    }
    else if (root->data < x)
    {
        return search(root->right, x);
    }
    else
    {
        return search(root->left, x);
    }
}