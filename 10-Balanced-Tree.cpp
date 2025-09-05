#include <bits/stdc++.h>
using namespace std;

// Problem : https://www.geeksforgeeks.org/problems/check-for-balanced-tree/1

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

// Bruteforce (Top To Bottom Approach) Approach in O(n^2) Time Complexity and O(h) Space Complexity
class Solution
{
public:
    int getHeight(Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        if (root->left == NULL && root->right == NULL)
        {
            return 1;
        }

        return 1 + max(getHeight(root->left), getHeight(root->right));
    }
    bool isBalanced(Node *root)
    {
        // Code here
        if (root == NULL)
        {
            return true;
        }

        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        if (abs(leftHeight - rightHeight) > 1)
        {
            return false;
        }

        return isBalanced(root->left) && isBalanced(root->right);
    }
};

// Optimal Approach ( Bottom to Top Approach ) in O(n) Time Complexity and O(h) Space Complexity
class Solution
{
public:
    pair<int, bool> checkBalancing(Node *root)
    {
        pair<int, bool> output;
        if (root == NULL)
        {
            output.first = 0;
            output.second = true;
            return output;
        }

        if (root->left == NULL && root->right == NULL)
        {
            output.first = 1;
            output.second = true;
            return output;
        }

        pair<int, bool> leftSideBalancing = checkBalancing(root->left);
        pair<int, bool> rightSideBalancing = checkBalancing(root->right);

        if (!leftSideBalancing.second || !rightSideBalancing.second)
        {
            output.second = false;
            return output;
        }

        if (abs(leftSideBalancing.first - rightSideBalancing.first) > 1)
        {
            output.second = false;
            return output;
        }

        output.second = true;
        output.first = 1 + max(leftSideBalancing.first, rightSideBalancing.first);
        return output;
    }
    bool isBalanced(Node *root)
    {
        // Code here
        if (root == NULL)
        {
            return true;
        }

        return checkBalancing(root).second;
    }
};

// Optimal Approach ( Bottom to Top Approach ) in O(n) Time Complexity and O(h) Space Complexity withOut Creating Class
class Solution
{
public:
    int checkBalanced(Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int leftSide = checkBalanced(root->left);
        int rightSide = checkBalanced(root->right);

        if (leftSide == -1 || rightSide == -1 || abs(leftSide - rightSide) > 1)
        {
            return -1;
        }

        return 1 + max(leftSide, rightSide);
    }
    bool isBalanced(Node *root)
    {
        // Code here
        if (root == NULL)
        {
            return true;
        }

        return checkBalanced(root) > 0;
    }
};