#include <bits/stdc++.h>
using namespace std;

// Problem : https://www.geeksforgeeks.org/problems/minimum-element-in-bst/1

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Bruteforce Approach with O(n) Time Complexity an O(h) Space Complexity
class Solution
{
public:
    int minValue(Node *root)
    {
        // Code here
        if (root == NULL)
        {
            return INT_MAX;
        }

        int minValueFromLeft = minValue(root->left);
        int minValueFromRight = minValue(root->right);
        return min(root->data, min(minValueFromLeft, minValueFromRight));
    }
};

// Optimal Approach with O(logn) Time Complexity and O(h) Space Complexity
class Solution
{
public:
    int minValue(Node *root)
    {
        // Code here
        if (root == NULL)
        {
            return INT_MAX;
        }

        return min(minValue(root->left), root->data);
    }
};