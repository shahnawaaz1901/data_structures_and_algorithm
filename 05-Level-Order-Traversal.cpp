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

// Approach 1 : In O(n^2) Time Complexity and O(h) Space Complexity using Recursion
class Solution
{
public:
    int getHeight(Node *root)
    {
        if (root == NULL || root->left == NULL && root->right == NULL)
        {
            return 0;
        }

        return 1 + max(getHeight(root->left), getHeight(root->right));
    }

    vector<int> getCurrentLevelNode(Node *root, int targetLevel)
    {
        vector<int> data;
        if (root == NULL)
        {
            return data;
        }

        if (targetLevel == 0)
        {
            vector<int> data;
            data.push_back(root->data);
            return data;
        }

        vector<int> leftSideLevel = getCurrentLevelNode(root->left, targetLevel - 1);
        vector<int> rightSideLevel = getCurrentLevelNode(root->right, targetLevel - 1);
        for (int i = 0; i < rightSideLevel.size(); i++)
        {
            leftSideLevel.push_back(rightSideLevel[i]);
        }
        return leftSideLevel;
    }
    vector<vector<int>> levelOrder(Node *root)
    {
        // code here
        vector<vector<int>> output;
        if (root == NULL)
        {
            return output;
        }

        int totalHeight = getHeight(root);
        for (int i = 0; i <= totalHeight; i++)
        {
            vector<int> data = getCurrentLevelNode(root, i);
            output.push_back(data);
        }

        return output;
    }
};
// Approach 2 : In O(n) Time Complexity and O(n) Space Complexity with Delimeter
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

// Approach 3 : Using 2 Queues In O(n) Time Complexity and O(n) Space Complexity without Delimeter

class Solution
{
public:
    vector<vector<int>> levelOrder(Node *root)
    {
        // code here
        vector<vector<int>> output;
        if (root == NULL)
        {
            return output;
        }

        queue<Node *> q1;
        queue<Node *> q2;
        q1.push(root);
        while (q1.size() || q2.size())
        {
            vector<int> data;
            while (q1.size())
            {
                Node *front = q1.front();
                data.push_back(front->data);
                q1.pop();
                if (front->left != NULL)
                {
                    q2.push(front->left);
                }
                if (front->right != NULL)
                {
                    q2.push(front->right);
                }
            }
            if (data.size())
            {
                output.push_back(data);
                while (data.size())
                {
                    data.pop_back();
                }
            }
            while (q2.size())
            {
                Node *front = q2.front();
                data.push_back(front->data);
                q2.pop();
                if (front->left != NULL)
                {
                    q1.push(front->left);
                }
                if (front->right != NULL)
                {
                    q1.push(front->right);
                }
            }
            if (data.size())
            {
                output.push_back(data);
            }
        }
        return output;
    }
};