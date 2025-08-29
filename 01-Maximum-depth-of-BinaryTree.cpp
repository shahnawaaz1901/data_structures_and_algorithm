#include <bits/stdc++.h>
using namespace std;

// Problem : https://www.geeksforgeeks.org/problems/height-of-binary-tree/1

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// Approach 1 : In O(n) Time Complexity and O(h) Space Complexity
class Solution
{
public:
    int height(Node *node)
    {
        // code here
        if (node == NULL || (node->left == NULL && node->right == NULL))
        {
            return 0;
        }

        return 1 + max(height(node->left), height(node->right));
    }
};

// Approach 2 : In O(n) Time Complexity and O(n) Space Complexity
class Solution
{
public:
    int height(Node *node)
    {
        // code here
        if (node == NULL)
        {
            return 0;
        }

        queue<Node *> treeNodes;
        treeNodes.push(node);
        int count = 0;
        while (!treeNodes.empty())
        {
            int level = treeNodes.size();
            for (int i = 0; i < level; i++)
            {
                Node *front = treeNodes.front();
                if (front->left != NULL)
                {
                    treeNodes.push(front->left);
                }

                if (front->right != NULL)
                {
                    treeNodes.push(front->right);
                }
                treeNodes.pop();
            }
            count++;
        }
        return count - 1;
    }
};