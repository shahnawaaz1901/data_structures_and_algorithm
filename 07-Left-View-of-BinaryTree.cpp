#include <bits/stdc++.h>
using namespace std;

// Problem : https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1

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

// Bruteforce Approach in O(n) Time Complexity and O(n) Space Complexity
class Solution
{
public:
    vector<int> leftView(Node *root)
    {
        // code here
        vector<int> output;
        if (root == NULL)
        {
            return output;
        }

        queue<Node *> pq;
        pq.push(root);
        pq.push(NULL);
        int currentLevel = 0;
        while (pq.size())
        {
            Node *front = pq.front();
            pq.pop();
            if (front == NULL)
            {
                currentLevel++;
                if (pq.size())
                {
                    pq.push(NULL);
                }
            }
            else
            {
                if (currentLevel == output.size())
                {
                    output.push_back(front->data);
                }
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
        return output;
    }
};

// Better Approach in O(n) Time Complexity and O(h) Space Complexity
class Solution
{
public:
    vector<int> getLeftView(Node *root, vector<int> ele, int index)
    {
        if (root == NULL)
        {
            return ele;
        }
        if (ele.size() == index)
        {
            ele.push_back(root->data);
        }

        vector<int> leftSide = getLeftView(root->left, ele, index + 1);
        vector<int> rightSide = getLeftView(root->right, leftSide, index + 1);
        return rightSide;
    }
    vector<int> leftView(Node *root)
    {
        // code here
        vector<int> output;
        return getLeftView(root, output, 0);
    }
};

// Better Approach in O(n) Time Complexity and O(h) Space Complexity
class Solution
{
public:
    vector<int> leftView(Node *root, int &maxLevel, int currLevel)
    {
        vector<int> output;
        if (root == NULL)
        {
            return output;
        }

        if (currLevel > maxLevel)
        {
            output.push_back(root->data);
            maxLevel = currLevel;
        }

        vector<int> leftSide = leftView(root->left, maxLevel, currLevel + 1);
        for (int i = 0; i < leftSide.size(); i++)
        {
            output.push_back(leftSide[i]);
        }
        vector<int> rightSide = leftView(root->right, maxLevel, currLevel + 1);
        for (int i = 0; i < rightSide.size(); i++)
        {
            output.push_back(rightSide[i]);
        }
        return output;
    }

    vector<int> leftView(Node *root)
    {
        // code here
        int maxLevel = -1;
        return leftView(root, maxLevel, 0);
    }
};

// Better Approach in O(n) Time Complexity and O(h) Space Complexity
class Solution
{
public:
    void getLeftView(Node *root, vector<int> &output, int index)
    {
        if (root == NULL)
        {
            return;
        }

        if (output.size() == index)
        {
            output.push_back(root->data);
        }

        getLeftView(root->left, output, index + 1);
        getLeftView(root->right, output, index + 1);
    }
    vector<int> leftView(Node *root)
    {
        // code here
        vector<int> output;
        getLeftView(root, output, 0);
        return output;
    }
};

// Optimal Approach in O(n) Time Complexity and O(1) Space Complexity using Morris Traversal
class Solution
{
public:
    vector<int> leftView(Node *root)
    {
        // code here
        vector<int> output;
        if (root == NULL)
        {
            return output;
        }

        Node *curr = root;
        int level = 0;
        while (curr != NULL)
        {
            if (curr->left == NULL)
            {
                if (level == output.size())
                {
                    output.push_back(curr->data);
                }
                level++;
                curr = curr->right;
            }
            else
            {
                Node *iP = curr->left;
                int depth = 1;
                while (iP->right != NULL && iP->right != curr)
                {
                    iP = iP->right;
                    depth++;
                }

                if (iP->right == NULL)
                {
                    if (output.size() == level)
                    {
                        output.push_back(curr->data);
                    }
                    level++;
                    iP->right = curr;
                    curr = curr->left;
                }
                else
                {
                    iP->right = NULL;
                    curr = curr->right;
                    level -= depth;
                }
            }
        }
        return output;
    }
};