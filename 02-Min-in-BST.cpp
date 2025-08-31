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

// Better Approach with O(logn) Time Complexity and O(h) Space Complexity
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

// Optimal Approach with O(logn) Time Complexity and O(1) Space Complexity

class Solution
{
public:
    int minValue(Node *root)
    {
        // Code here
        int minValue = INT_MAX;
        while (root != NULL)
        {
            minValue = min(minValue, root->data);
            root = root->left;
        }
        return minValue;
    }
};