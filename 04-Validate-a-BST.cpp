#include <bits/stdc++.h>
using namespace std;

// Problem : https://www.geeksforgeeks.org/problems/check-for-bst/1

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

// Bruteforce Approach with O(n^2) Time Complexity and O(h) Space Complexity
class Solution
{
public:
    // Function to check whether a Binary Tree is BST or not.
    bool checkMinimumAvailable(Node *root, int data)
    {
        if (root == NULL)
        {
            return true;
        }
        if (root->data < data)
        {
            return false;
        }
        return checkMinimumAvailable(root->left, data) && checkMinimumAvailable(root->right, data);
    }
    bool checkMaximumAvailable(Node *root, int data)
    {
        if (root == NULL)
        {
            return true;
        }
        if (root->data > data)
        {
            return false;
        }
        return checkMaximumAvailable(root->left, data) && checkMaximumAvailable(root->right, data);
    }
    bool isBST(Node *root)
    {
        if (root == NULL)
        {
            return true;
        }
        // Your code here
        Node *left = root->left;
        Node *right = root->right;
        if (left != NULL && root->data < left->data)
        {
            return false;
        }

        if (right != NULL && root->data > right->data)
        {
            return false;
        }
        if (!checkMinimumAvailable(root->right, root->data) || !checkMaximumAvailable(root->left, root->data))
        {
            return false;
        }

        return isBST(root->left) && isBST(root->right);
    }
};

// Another Bruteforce Approach in O(n^2) Time Complexity and O(n) Space Complexity
class Solution
{
public:
    vector<int> getInOrderTraversal(Node *root)
    {
        vector<int> output;
        if (root == NULL)
        {
            return output;
        }

        vector<int> leftOutput = getInOrderTraversal(root->left);
        vector<int> rightOutput = getInOrderTraversal(root->right);
        for (int i = 0; i < leftOutput.size(); i++)
        {
            output.push_back(leftOutput[i]);
        }
        output.push_back(root->data);
        for (int i = 0; i < rightOutput.size(); i++)
        {
            output.push_back(rightOutput[i]);
        }
        return output;
    }
    bool isBST(Node *root)
    {
        if (root == NULL)
        {
            return true;
        }

        vector<int> inOrder = getInOrderTraversal(root);
        for (int i = 0; i < inOrder.size() - 1; i++)
        {
            if (inOrder[i] > inOrder[i + 1])
            {
                return false;
            }
        }
        return true;
    }
};

// Optimized Bruteforce Approach in O(n) Time Complexity and O(n) Space Complexity
class Solution
{
public:
    void getInOrderTraversal(Node *root, vector<int> &output)
    {
        if (root == NULL)
        {
            return;
        }

        getInOrderTraversal(root->left, output);
        output.push_back(root->data);
        getInOrderTraversal(root->right, output);
    }
    bool isBST(Node *root)
    {
        if (root == NULL)
        {
            return true;
        }

        vector<int> inOrder;
        getInOrderTraversal(root, inOrder);
        for (int i = 0; i < inOrder.size() - 1; i++)
        {
            if (inOrder[i] > inOrder[i + 1])
            {
                return false;
            }
        }
        return true;
    }
};

// Better Approach in O(n) Time Complexity and O(h) Space Complexity using PrevValue of Node
class Solution
{
public:
    bool inOrderTraversal(Node *root, int &prevValue)
    {
        if (root == NULL)
        {
            return true;
        }

        if (!inOrderTraversal(root->left, prevValue))
        {
            return false;
        }

        if (root->data <= prevValue)
        {
            return false;
        }

        prevValue = root->data;

        return inOrderTraversal(root->right, prevValue);
    }
    bool isBST(Node *root)
    {
        if (root == NULL)
        {
            return true;
        }

        int prevVal = INT_MIN;

        return inOrderTraversal(root, prevVal);
    }
};

// Better Approach in O(n) Time Complexity and O(h) Space Complexity using CustomClass
class CustomClass
{
public:
    bool isBST;
    int min;
    int max;
};
class Solution
{
public:
    CustomClass validateBST(Node *root)
    {
        if (root == NULL)
        {
            CustomClass a;
            a.min = INT_MAX;
            a.max = INT_MIN;
            a.isBST = true;
            return a;
        }

        CustomClass leftResult = validateBST(root->left);
        if (!leftResult.isBST)
        {
            return leftResult;
        }
        CustomClass rightResult = validateBST(root->right);
        if (!rightResult.isBST)
        {
            return rightResult;
        }

        CustomClass output;
        if (root->data > leftResult.max && root->data < rightResult.min)
        {
            output.isBST = true;
        }
        else
        {
            output.isBST = false;
        }
        output.min = min(root->data, min(leftResult.min, rightResult.min));
        output.max = max(root->data, max(rightResult.max, leftResult.max));
        return output;
    }
    bool isBST(Node *root)
    {
        if (root == NULL)
        {
            return true;
        }

        return validateBST(root).isBST;
    }
};

// Better Approach in O(n) Time Complexity and O(h) Space Complexity
class Solution
{
public:
    // Function to check whether a Binary Tree is BST or not.
    bool isBST(Node *root, int min, int max)
    {
        if (root == NULL)
        {
            return true;
        }

        if (root->data > max || root->data < min)
        {
            return false;
        }

        Node *left = root->left;
        Node *right = root->right;

        if (left != NULL && left->data > root->data)
        {
            return false;
        }

        if (right != NULL && right->data < root->data)
        {
            return false;
        }

        return isBST(root->left, min, root->data) && isBST(root->right, root->data, max);
    }
    bool isBST(Node *root)
    {
        // Your code here
        return isBST(root, INT_MIN, INT_MAX);
    }
};

// Most Optimal Approach in O(n) Time Complexity and O(1) Space Complexity
class Solution
{
public:
    bool isBST(Node *root)
    {
        Node *curr = root;
        Node *prev = NULL;

        while (curr != NULL)
        {
            if (curr->left == NULL)
            {
                if (prev != NULL && prev->data > curr->data)
                {
                    return false;
                }
                prev = curr;
                curr = curr->right;
            }
            else
            {
                Node *inorderPredecessor = curr->left;
                while (inorderPredecessor->right != NULL && inorderPredecessor->right != curr)
                {
                    inorderPredecessor = inorderPredecessor->right;
                }

                if (inorderPredecessor->right != NULL)
                {
                    inorderPredecessor->right = NULL;
                    if (prev != NULL && prev->data > curr->data)
                    {
                        return false;
                    }
                    prev = curr;
                    curr = curr->right;
                }
                else
                {
                    inorderPredecessor->right = curr;
                    curr = curr->left;
                }
            }
        }

        return true;
    }
};