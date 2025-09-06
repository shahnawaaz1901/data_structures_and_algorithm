#include <bits/stdc++.h>
using namespace std;

// Problem : https://www.geeksforgeeks.org/problems/diameter-of-binary-tree/1

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node *newNode(int val)
{
    return new Node(val);
}

// Bruteforce Approach in O(n^2) Time Complexity and O(h) Space Complexity
class Solution
{
public:
    int getHeight(Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        return 1 + max(getHeight(root->left), getHeight(root->right));
    }

    int getDiameter(Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        int diameterVal = leftHeight + rightHeight;
        return max(diameterVal, max(getDiameter(root->left), getDiameter(root->right)));
    }
    int diameter(Node *root)
    {
        // Your code here
        return getDiameter(root);
    }
};

// Better Approach in O(n) Time Complexity and O(h) Space Complexity
class Solution
{
public:
    pair<int, int> getDiameter(Node *root)
    {
        pair<int, int> output;
        if (root == NULL)
        {
            output.first = 0;
            output.second = 0;
            return output;
        }

        pair<int, int> leftDiameter = getDiameter(root->left);
        pair<int, int> rightDiameter = getDiameter(root->right);
        int diameter = leftDiameter.first + rightDiameter.first;
        output.second = max(diameter, max(leftDiameter.second, rightDiameter.second));
        output.first = 1 + max(leftDiameter.first, rightDiameter.first);
        return output;
    }

    int diameter(Node *root)
    {
        // Your code here
        return getDiameter(root).second;
    }
};

// Optimal Approach in O(n) Time Complexity and O(h) Space Complexity
class Solution
{
public:
    int diaMet(Node *root, int &res)
    {
        if (root == NULL)
        {
            return 0;
        }

        int leftDiameter = diaMet(root->left, res);
        int rightDiameter = diaMet(root->right, res);
        res = max(res, leftDiameter + rightDiameter);
        return 1 + max(leftDiameter, rightDiameter);
    }
    int diameter(Node *root)
    {
        // Your code here
        int res = 0;
        diaMet(root, res);
        return res;
    }
};