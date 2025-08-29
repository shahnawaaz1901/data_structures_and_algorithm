#include <bits/stdc++.h>
using namespace std;

// Problem : https://www.geeksforgeeks.org/problems/reverse-level-order-traversal/1

struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Approach 1 : In O(n) Time Complexity and O(n) Space Complexity with Stack
class Solution
{
public:
    vector<int> reverseLevelOrder(Node *root)
    {
        // code here
        queue<Node *> nodesData;
        nodesData.push(root);
        stack<Node *> reverseValues;
        while (!nodesData.empty())
        {
            Node *front = nodesData.front();
            nodesData.pop();
            if (front->right != NULL)
            {
                nodesData.push(front->right);
            }
            if (front->left != NULL)
            {
                nodesData.push(front->left);
            }
            reverseValues.push(front);
        }

        vector<int> output;
        while (!reverseValues.empty())
        {
            output.push_back(reverseValues.top()->data);
            reverseValues.pop();
        }
        return output;
    }
};

// Approach 2 : In O(n) Time Complexity and O(n) Space Complexity with Array
class Solution
{
public:
    vector<int> reverseLevelOrder(Node *root)
    {
        // code here
        queue<Node *> nodesData;
        nodesData.push(root);
        vector<int> reverseValues;
        while (!nodesData.empty())
        {
            Node *front = nodesData.front();
            nodesData.pop();
            if (front->right != NULL)
            {
                nodesData.push(front->right);
            }
            if (front->left != NULL)
            {
                nodesData.push(front->left);
            }
            reverseValues.push_back(front->data);
        }

        int i = 0;
        int j = reverseValues.size() - 1;
        while (i < j)
        {
            int temp = reverseValues[j];
            reverseValues[j] = reverseValues[i];
            reverseValues[i] = temp;
            i++;
            j--;
        }
        return reverseValues;
    }
};