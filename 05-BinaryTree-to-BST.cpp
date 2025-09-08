#include <bits/stdc++.h>
using namespace std;

// Problem : https://www.geeksforgeeks.org/problems/binary-tree-to-bst/1

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// Approach 1 : In O(nLogn) Time Complexity and O(n) Space Complexity
class Solution
{
public:
    void getNodes(Node *root, vector<int> &nodes)
    {
        if (root == NULL)
        {
            return;
        }

        nodes.push_back(root->data);
        getNodes(root->left, nodes);
        getNodes(root->right, nodes);
    }

    void constructBST(Node *root, vector<int> nodes, int &index)
    {
        if (index > nodes.size() || root == NULL)
        {
            return;
        }

        constructBST(root->left, nodes, index);
        root->data = nodes[index];
        index++;
        constructBST(root->right, nodes, index);
    }
    Node *binaryTreeToBST(Node *root)
    {
        // Your code goes here
        vector<int> nodes;
        getNodes(root, nodes);
        sort(nodes.begin(), nodes.end());
        int index = 0;
        constructBST(root, nodes, index);
        return root;
    }
};

// Approach 2 : In O(nLogn) Time Complexity and O(n) Space Complexity
class Solution
{
public:
    void getNodes(Node *root, vector<int> &nodes)
    {
        if (root == NULL)
        {
            return;
        }

        nodes.push_back(root->data);
        getNodes(root->left, nodes);
        getNodes(root->right, nodes);
    }

    Node *constructBST(vector<int> nodes, int start, int end)
    {
        if (start > end)
        {
            return NULL;
        }

        int mid = (end + start) / 2;
        Node *root = new Node(nodes[mid]);
        root->left = constructBST(nodes, start, mid - 1);
        root->right = constructBST(nodes, mid + 1, end);
        return root;
    }
    Node *binaryTreeToBST(Node *root)
    {
        // Your code goes here
        vector<int> nodes;
        getNodes(root, nodes);
        sort(nodes.begin(), nodes.end());
        return constructBST(nodes, 0, nodes.size() - 1);
    }
};

// Approach 3 in O(nLogn) Time Complexity and O(n) Space Complexity using PriorityQueue
class Solution
{
public:
    void getNodes(Node *root, priority_queue<int, vector<int>, greater<int>> &pq)
    {
        if (root == NULL)
        {
            return;
        }

        pq.push(root->data);
        getNodes(root->left, pq);
        getNodes(root->right, pq);
    }

    Node *getBST(Node *root, priority_queue<int, vector<int>, greater<int>> &pq)
    {
        if (root == NULL)
        {
            return root;
        }

        root->left = getBST(root->left, pq);
        root->data = pq.top();
        pq.pop();
        root->right = getBST(root->right, pq);
        return root;
    }
    Node *binaryTreeToBST(Node *root)
    {
        // Your code goes here
        if (root == NULL)
        {
            return root;
        }
        // set<int> values;
        priority_queue<int, vector<int>, greater<int>> pq;
        getNodes(root, pq);
        return getBST(root, pq);
    }
};

// Approach 4 in O(nLogn) Time Complexity and O(n) Space Complexity using Sets
class Solution
{
public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    void getNodes(Node *root, set<int> &values)
    {
        if (root == NULL)
        {
            return;
        }

        values.insert(root->data);
        getNodes(root->left, values);
        getNodes(root->right, values);
    }

    Node *getBST(Node *root, set<int> &values)
    {
        if (root == NULL)
        {
            return root;
        }

        root->left = getBST(root->left, values);
        root->data = *(values.begin());
        values.erase(values.begin());
        root->right = getBST(root->right, values);
        return root;
    }
    Node *binaryTreeToBST(Node *root)
    {
        // Your code goes here
        if (root == NULL)
        {
            return root;
        }
        set<int> values;
        getNodes(root, values);
        return getBST(root, values);
    }
};