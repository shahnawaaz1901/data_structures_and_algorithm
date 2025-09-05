#include <bits/stdc++.h>
using namespace std;

// Problem : https://www.geeksforgeeks.org/dsa/zigzag-tree-traversal/

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// Bruteforce Approach in O(n^2) Time Complexity and O(h) Space Complexity
class Solution
{
public:
    void leftToRight(Node *root, int level, vector<int> &output)
    {
        if (root == NULL)
        {
            return;
        }

        if (level == 0)
        {
            output.push_back(root->data);
            return;
        }

        leftToRight(root->left, level - 1, output);
        leftToRight(root->right, level - 1, output);
    }

    void rightToLeft(Node *root, int level, vector<int> &output)
    {
        if (root == NULL)
        {
            return;
        }

        if (level == 0)
        {
            output.push_back(root->data);
            return;
        }

        rightToLeft(root->right, level - 1, output);
        rightToLeft(root->left, level - 1, output);
    }
    vector<int> zigZagTraversal(Node *root)
    {
        // Code here
        vector<int> output;
        for (int i = 0;; i++)
        {
            int n = output.size();
            if (i % 2 == 0)
            {
                leftToRight(root, i, output);
            }
            else
            {
                rightToLeft(root, i, output);
            }
            if (n == output.size())
            {
                break;
            }
        }

        return output;
    }
};

// Better Approach in O(n) Time Complexity and O(n*h) Space Complexity
class Solution
{
public:
    void levelOrder(Node *root, int level, vector<vector<int>> &levelOrderElements)
    {
        if (root == NULL)
        {
            return;
        }

        if (level == levelOrderElements.size())
        {
            levelOrderElements.push_back({});
        }

        levelOrderElements[level].push_back(root->data);

        levelOrder(root->left, level + 1, levelOrderElements);
        levelOrder(root->right, level + 1, levelOrderElements);
    }
    vector<int> zigZagTraversal(Node *root)
    {
        // Code here
        vector<int> output;
        vector<vector<int>> levelOrderElements;
        levelOrder(root, 0, levelOrderElements);
        int m = levelOrderElements.size();
        for (int i = 0; i < m; i++)
        {
            int n = levelOrderElements[i].size();
            for (int j = 0; j < n; j++)
            {
                if (i % 2 == 0)
                {
                    output.push_back(levelOrderElements[i][j]);
                }
                else
                {
                    output.push_back(levelOrderElements[i][n - 1 - j]);
                }
            }
        }
        return output;
    }
};

// Optimal Approach in O(n) Time Complexity and O(n) Space Complexity using two Stacks
class Solution
{
public:
    vector<int> zigZagTraversal(Node *root)
    {
        // Code here
        vector<int> output;
        stack<Node *> s1;
        stack<Node *> s2;
        s1.push(root);
        while (s1.size() || s2.size())
        {
            while (s1.size())
            {
                Node *top = s1.top();
                output.push_back(top->data);
                s1.pop();
                if (top->left != NULL)
                {
                    s2.push(top->left);
                }

                if (top->right != NULL)
                {
                    s2.push(top->right);
                }
            }

            while (s2.size())
            {
                Node *top = s2.top();
                s2.pop();
                output.push_back(top->data);
                if (top->right != NULL)
                {
                    s1.push(top->right);
                }

                if (top->left != NULL)
                {
                    s1.push(top->left);
                }
            }
        }

        return output;
    }
};

// Optimal Approach in O(n) Time Complexity and O(n) Space Complexity using Deque
class Solution
{
public:
    vector<int> zigZagTraversal(Node *root)
    {
        // Code here
        vector<int> output;
        deque<Node *> dPQ;
        dPQ.push_back(root);
        dPQ.push_back(NULL);
        int curLevel = 0;
        while (dPQ.size())
        {
            if (curLevel % 2 == 0)
            {
                Node *front = dPQ.front();
                if (front == NULL)
                {
                    if (dPQ.size() == 1)
                    {
                        dPQ.pop_front();
                    }
                    curLevel++;
                }
                else
                {
                    output.push_back(front->data);
                    if (front->left != NULL)
                    {
                        dPQ.push_back(front->left);
                    }

                    if (front->right != NULL)
                    {
                        dPQ.push_back(front->right);
                    }
                    dPQ.pop_front();
                }
            }
            else
            {
                Node *back = dPQ.back();
                if (back == NULL)
                {
                    if (dPQ.size() == 1)
                    {
                        dPQ.pop_back();
                    }
                    curLevel++;
                }
                else
                {
                    output.push_back(back->data);
                    if (back->right != NULL)
                    {
                        dPQ.push_front(back->right);
                    }

                    if (back->left != NULL)
                    {
                        dPQ.push_front(back->left);
                    }
                    dPQ.pop_back();
                }
            }
        }
        return output;
    }
};