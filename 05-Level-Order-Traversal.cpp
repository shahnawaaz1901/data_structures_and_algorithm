#include <bits/stdc++.h>
using namespace std;

// Problem : https://www.geeksforgeeks.org/problems/level-order-traversal/1

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    // Constructor
    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution
{
public:
    vector<vector<int>> levelOrder(Node *root)
    {
        // code here
        if (!root)
        {
            vector<vector<int>> output;
            return output;
        }

        queue<Node *> pq;
        vector<vector<int>> output;
        pq.push(root);
        pq.push(NULL);
        vector<int> data;
        while (pq.size())
        {
            Node *front = pq.front();

            if (front == NULL)
            {
                output.push_back(data);
                while (data.size())
                {
                    data.pop_back();
                }
                pq.pop();
                if (pq.size())
                {
                    pq.push(NULL);
                }
                continue;
            }
            pq.pop();
            data.push_back(front->data);
            if (front->left)
            {
                pq.push(front->left);
            }

            if (front->right)
            {
                pq.push(front->right);
            }
        }
        return output;
    }
};