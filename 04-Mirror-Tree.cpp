#include <bits/stdc++.h>
using namespace std;

// Problem : https://www.geeksforgeeks.org/problems/mirror-tree/1

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

// Approach 1 : In O(n) Time Complexity and O(h) Space Complexity
class Solution
{
public:
    void mirror(Node *node)
    {
        // code here
        if (node == NULL)
        {
            return;
        }

        Node *temp = node->left;
        node->left = node->right;
        node->right = temp;

        mirror(node->left);
        mirror(node->right);
    }
};

// Approach 2 : In O(n) Time Complexity and O(n) Space Complexity
class Solution
{
public:
    void mirror(Node *node)
    {
        // code here
        if (node == NULL)
        {
            return;
        }

        queue<Node *> pq;
        pq.push(node);
        while (!pq.empty())
        {
            Node *front = pq.front();
            if (front->left != NULL)
            {
                pq.push(front->left);
            }
            if (front->right != NULL)
            {
                pq.push(front->right);
            }

            Node *temp = front->left;
            front->left = front->right;
            front->right = temp;
            pq.pop();
        }
    }
};