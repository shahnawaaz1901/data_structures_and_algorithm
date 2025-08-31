#include <bits/stdc++.h>
using namespace std;

// Problem : https://www.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    // Constructor to initialize a new node
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Bruteforce Approach with O(n) Time Complexity and O(h) Space Complexity
class Solution
{
public:
    Node *LCA(Node *root, Node *n1, Node *n2)
    {
        // code here
        if (root == NULL)
        {
            return NULL;
        }

        if (root->data == n1->data || root->data == n2->data)
        {
            return root;
        }

        Node *leftSide = LCA(root->left, n1, n2);
        Node *rightSide = LCA(root->right, n1, n2);
        if (leftSide != NULL && rightSide != NULL)
        {
            return root;
        }
        else if (leftSide != NULL)
        {
            return leftSide;
        }
        else
        {
            return rightSide;
        }
    }
};

// Optimal Approach with O(logn) Time Complexity and O(h) Space Complexity
class Solution
{
public:
    Node *LCA(Node *root, Node *n1, Node *n2)
    {
        // code here
        if (root == NULL)
        {
            return NULL;
        }

        if (root->data == n1->data || root->data == n2->data)
        {
            return root;
        }

        Node *leftSide = LCA(root->left, n1, n2);
        Node *rightSide = LCA(root->right, n1, n2);
        if (leftSide != NULL && rightSide != NULL)
        {
            return root;
        }
        else if (leftSide != NULL)
        {
            return leftSide;
        }
        else
        {
            return rightSide;
        }
    }
};