#include <bits/stdc++.h>
using namespace std;

// Problem : https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1

class Node
{
public:
    int data;
    Node *next;
    Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

// Bruteforce Approach in O(n*m) Time Complexity and O(n) Space Complexity
class Solution
{
public:
    Node *mergeSortedLL(Node *head1, Node *head2)
    {
        if (head1 == NULL)
        {
            return head2;
        }

        if (head2 == NULL)
        {
            return head1;
        }

        Node *outputHead = head1->data < head2->data ? head1 : head2;
        if (head1->data < head2->data)
        {
            outputHead->bottom = mergeSortedLL(head1->bottom, head2);
        }
        else
        {
            outputHead->bottom = mergeSortedLL(head1, head2->bottom);
        }
        return outputHead;
    }
    Node *flatten(Node *root)
    {
        // code here
        if (root == NULL)
        {
            return root;
        }
        Node *curr = root;
        Node *output = NULL;
        while (curr != NULL)
        {
            output = mergeSortedLL(output, curr);
            curr = curr->next;
        }
        return output;
    }
};

// Optimized Approach in O((m*n)Log(m*n)) Time Complexity and O(m*n) Space Complexity
class Solution
{
public:
    Node *flatten(Node *root)
    {
        // code here
        if (root == NULL)
        {
            return root;
        }
        vector<int> values;
        Node *curr = root;
        while (curr != NULL)
        {
            Node *nextNode = curr;
            while (nextNode != NULL)
            {
                values.push_back(nextNode->data);
                nextNode = nextNode->bottom;
            }
            curr = curr->next;
        }

        sort(values.begin(), values.end());
        Node *outputHead = new Node(values[0]);
        Node *outputTail = outputHead;
        for (int i = 1; i < values.size(); i++)
        {
            outputTail->bottom = new Node(values[i]);
            outputTail = outputTail->bottom;
        }
        return outputHead;
    }
};

// Better Approach in O(m*m*n) Time Complexity and O(m) Space Complexity where m is heads and n is bottom Nodes
class Solution
{
public:
    Node *flatten(Node *root)
    {
        // code here
        if (root == NULL || root->next == NULL)
        {
            return root;
        }

        vector<Node *> heads;
        Node *temp = root;
        while (temp != NULL)
        {
            heads.push_back(temp);
            temp = temp->next;
        }

        Node *outputHead = NULL;
        Node *outputTail = NULL;
        bool isAllValuesNull = true;
        while (outputHead == NULL || !isAllValuesNull)
        {
            Node *minNode = NULL;
            int minNodeIndex = -1;
            isAllValuesNull = true;
            for (int i = 0; i < heads.size(); i++)
            {
                Node *node = heads[i];
                if (node != NULL)
                {
                    minNode = minNode == NULL ? node : minNode->data < node->data ? minNode
                                                                                  : node;
                    minNodeIndex = minNode == NULL ? i : minNode->data < node->data ? minNodeIndex
                                                                                    : i;
                    isAllValuesNull = false;
                }
            }
            if (!isAllValuesNull)
            {
                if (outputHead == NULL)
                {
                    outputHead = minNode;
                    outputTail = outputHead;
                }
                else
                {
                    outputTail->bottom = minNode;
                    outputTail = outputTail->bottom;
                }

                heads[minNodeIndex] = heads[minNodeIndex]->bottom;
            }
        }

        return outputHead;
    }
};