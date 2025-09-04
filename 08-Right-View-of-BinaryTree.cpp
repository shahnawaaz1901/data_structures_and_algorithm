#include <bits/stdc++.h>
using namespace std;

// Problem : https://www.geeksforgeeks.org/problems/right-view-of-binary-tree/1

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Bruteforce Approach in O(n) Time Complexity and O(h) Space Complexity
class Solution
{
public:
    vector<int> rightView(Node *root, int &max, int order)
    {
        vector<int> output;
        if (root == NULL)
        {
            return output;
        }

        if (max < order)
        {
            output.push_back(root->data);
            max = order;
        }

        vector<int> rightSubTreeView = rightView(root->right, max, order + 1);
        for (int i = 0; i < rightSubTreeView.size(); i++)
        {
            output.push_back(rightSubTreeView[i]);
        }
        vector<int> leftSubTreeView = rightView(root->left, max, order + 1);
        for (int i = 0; i < leftSubTreeView.size(); i++)
        {
            output.push_back(leftSubTreeView[i]);
        }
        return output;
    }
    vector<int> rightView(Node *root)
    {
        //  Code here
        int maxLevel = -1;
        return rightView(root, maxLevel, 0);
    }
};

// Optimized Bruteforce Approach in O(n) Time Complexity and O(h) Space Complexity
class Solution
{
public:
    vector<int> rightView(Node *root, vector<int> &elements, int order)
    {
        if (root == NULL)
        {
            return elements;
        }

        if (elements.size() == order)
        {
            elements.push_back(root->data);
        }

        vector<int> rightSide = rightView(root->right, elements, order + 1);
        vector<int> leftSide = rightView(root->left, rightSide, order + 1);
        return leftSide;
    }
    vector<int> rightView(Node *root)
    {
        //  Code here
        vector<int> output;
        return rightView(root, output, 0);
    }
};

// Optimized Bruteforce Approach in O(n) Time Complexity and O(h) Space Complexity
class Solution
{
public:
    void rightView(Node *root, vector<int> &output, int order)
    {
        if (root == NULL)
        {
            return;
        }

        if (output.size() == order)
        {
            output.push_back(root->data);
        }

        rightView(root->right, output, order + 1);
        rightView(root->left, output, order + 1);
    }
    vector<int> rightView(Node *root)
    {
        //  Code here
        vector<int> output;
        rightView(root, output, 0);
        return output;
    }
};

// Optimized Bruteforce Approach in O(n) Time Complexity and O(n) Space Complexity
class Solution
{
public:
    vector<int> rightView(Node *root)
    {
        //  Code here
        vector<int> output;
        queue<Node *> pq;
        pq.push(root);
        pq.push(NULL);
        int level = 0;
        while (pq.size())
        {
            Node *front = pq.front();
            pq.pop();
            if (front == NULL)
            {
                if (pq.size())
                {
                    pq.push(NULL);
                }
                level++;
            }
            else
            {
                if (level == output.size())
                {
                    output.push_back(front->data);
                }

                if (front->right != NULL)
                {
                    pq.push(front->right);
                }

                if (front->left != NULL)
                {
                    pq.push(front->left);
                }
            }
        }
        return output;
    }
};

// Optimal Approach in O(n) Time Complexiy and O(1) Space Complexity using Morris Traversal

class Solution
{
public:
    vector<int> rightView(Node *root)
    {
        //  Code here
        vector<int> output;
        Node *curr = root;
        int level = 0;
        while (curr != NULL)
        {
            if (curr->right == NULL)
            {
                if (output.size() == level)
                {
                    output.push_back(curr->data);
                }
                curr = curr->left;
                level++;
            }
            else
            {
                Node *iP = curr->right;
                int depth = 1;
                while (iP->left != NULL && iP->left != curr)
                {
                    iP = iP->left;
                    depth++;
                }

                if (iP->left == NULL)
                {
                    iP->left = curr;
                    if (level == output.size())
                    {
                        output.push_back(curr->data);
                    }
                    level++;
                    curr = curr->right;
                }
                else
                {
                    iP->left = NULL;
                    curr = curr->left;
                    level -= depth;
                }
            }
        }
        return output;
    }
};