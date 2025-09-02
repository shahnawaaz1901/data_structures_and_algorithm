#include <bits/stdc++.h>
using namespace std;

// Problem : https://www.geeksforgeeks.org/problems/inorder-traversal/1

// In O(n) Time Complexity and O(1) Space Compexity
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

class Solution
{
public:
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node *root)
    {
        // Your code here
        vector<int> output;
        Node *curr = root;
        while (curr != NULL)
        {
            if (curr->left != NULL)
            {
                Node *inOrderPredeccesor = curr->left;
                while (inOrderPredeccesor->right != NULL && inOrderPredeccesor->right != curr)
                {
                    inOrderPredeccesor = inOrderPredeccesor->right;
                }

                if (inOrderPredeccesor->right == NULL)
                {
                    inOrderPredeccesor->right = curr;
                    curr = curr->left;
                }
                else
                {
                    output.push_back(curr->data);
                    curr = curr->right;
                    inOrderPredeccesor->right = NULL;
                }
            }
            else
            {
                output.push_back(curr->data);
                curr = curr->right;
            }
        }
        return output;
    }
};