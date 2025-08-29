#include <bits/stdc++.h>
using namespace std;

// Problem : https://www.geeksforgeeks.org/dsa/check-if-a-binary-tree-is-subtree-of-another-binary-tree/

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

// Approach 1 : In O(n*m) Time Complexity and O(nHeight+mHeight) Space Complexity
class Solution
{
public:
    // Function to check if S is a subtree of tree T.
    bool isSubTree(Node *T, Node *S)
    {
        // Your code here

        if (S == NULL)
        {
            return true;
        }
        if (T == NULL)
        {
            return false;
        }
        bool output = false;
        if (T->data == S->data)
        {
            output = isSubTree(T->left, S->left) && isSubTree(T->right, S->right);
            if (output)
            {
                return true;
            }
        }
        return isSubTree(T->left, S) || isSubTree(T->right, S);
    }
};