#include <bits/stdc++.h>
using namespace std;

// Problem : https://www.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node()
    {
        data = 0;
        left = right = NULL;
    }

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

// Bruteforce Approach in O(n) Time Complexity and O(n) Space Complexity
class Solution
{
public:
    bool findNodePath(Node *root, int n1, vector<Node *> &path)
    {
        if (root == NULL)
        {
            return false;
        }

        if (root->data == n1)
        {
            path.push_back(root);
            return true;
        }

        path.push_back(root);
        bool isFoundFromLeft = findNodePath(root->left, n1, path);
        if (isFoundFromLeft)
        {
            return true;
        }
        bool isFoundFromRight = findNodePath(root->right, n1, path);
        if (isFoundFromRight)
        {
            return true;
        }
        path.pop_back();
        return false;
    }
    Node *lca(Node *root, int n1, int n2)
    {
        //  code here
        if (root == NULL)
        {
            return NULL;
        }

        vector<Node *> firstNodePath;
        vector<Node *> secondNodePath;

        bool leftSideOutput = findNodePath(root, n1, firstNodePath); // O(n) Time and O(h) Space
        bool rightSideOutput = findNodePath(root, n2, secondNodePath); // O(n) Time and O(h) Space
        if (leftSideOutput && rightSideOutput)
        {
            for (int i = firstNodePath.size() - 1; i >= 0; i--)
            {
                for (int j = secondNodePath.size() - 1; j >= 0; j--)
                {
                    if (firstNodePath[i] == secondNodePath[j])
                    {
                        return firstNodePath[i];
                    }
                }
            }
        }
        else if (leftSideOutput)
        {
            return firstNodePath[firstNodePath.size() - 1];
        }
        else
        {
            return secondNodePath[secondNodePath.size() - 1];
        }
        return NULL;
    }
};

// Bruteforce Approach in O(n) Time Complexity and O(h) Space Complexity
class Solution
{
public:
    Node *lca(Node *root, int n1, int n2)
    {
        //  code here
        if (root == NULL)
        {
            return NULL;
        }

        if (root->data == n1 || root->data == n2)
        {
            return root;
        }

        Node *leftSideCheck = lca(root->left, n1, n2);
        Node *rightSideCheck = lca(root->right, n1, n2);

        if (leftSideCheck != NULL && rightSideCheck != NULL)
        {
            return root;
        }
        else if (leftSideCheck != NULL)
        {
            return leftSideCheck;
        }
        else
        {
            return rightSideCheck;
        }
    }
};