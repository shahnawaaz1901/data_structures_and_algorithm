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

// Bruteforce Approach in O(n) Time Complexity and O(n) Space Complexity
class Solution
{
public:
    int height(Node *node)
    {
        // code here
        int totalHeight = 0;
        queue<Node *> pq;
        pq.push(node);
        pq.push(NULL);
        while (!pq.empty())
        {
            Node *front = pq.front();
            pq.pop();
            if (front == NULL)
            {
                if (pq.size())
                {
                    pq.push(NULL);
                    totalHeight++;
                }
            }
            else
            {
                if (front->left != NULL)
                {
                    pq.push(front->left);
                }

                if (front->right != NULL)
                {
                    pq.push(front->right);
                }
            }
        }
        return totalHeight;
    }
};

// Better Approach in O(n) Time Complexity and O(h) Space Complexity
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