#include <bits/stdc++.h>
using namespace std;

// Problem : https://www.geeksforgeeks.org/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/0
/*
delete n nodes after m nodes
  The input list will have at least one element
  Node is defined as
*/

struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
// Bruteforce Approach with in O(n) Time Complexity and O(n) Space Complexity
class Solution
{
public:
    Node *linkdelete(Node *head, int n, int m)
    {
        // code here
        if (head == NULL)
        {
            return head;
        }

        Node *tail = head;
        int x = m;
        int y = n;
        while (x - 1 && tail != NULL)
        {
            tail = tail->next;
            x--;
        }
        if (tail == NULL)
        {
            return head;
        }
        Node *deletedNodes = tail->next;
        while (y - 1 && deletedNodes != NULL)
        {
            deletedNodes = deletedNodes->next;
            y--;
        }
        Node *temp = tail->next;
        if (deletedNodes == NULL)
        {
            tail->next = deletedNodes;
        }
        else
        {
            tail->next = deletedNodes->next;
            deletedNodes->next = NULL;
        }
        delete temp;
        tail->next = linkdelete(tail->next, n, m);
        return head;
    }
};

// Optimal Approach with in O(n) Time Complexity and O(1) Space Complexity
class Solution
{
public:
    Node *linkdelete(Node *head, int n, int m)
    {
        // code here
        if (head == NULL)
        {
            return head;
        }

        int x = n;
        int y = m;
        Node *temp = head;
        while (temp != NULL)
        {
            if (y)
            {
                while (y - 1 && temp != NULL)
                {
                    temp = temp->next;
                    y--;
                }
                y = 0;
            }
            else if (x)
            {
                Node *startingDeletePoint = temp->next;
                Node *endingDeletePoint = temp->next;
                while (x - 1 && endingDeletePoint != NULL)
                {
                    x--;
                    endingDeletePoint = endingDeletePoint->next;
                }
                if (endingDeletePoint == NULL)
                {
                    temp->next = endingDeletePoint;
                }
                else
                {
                    temp->next = endingDeletePoint->next;
                    endingDeletePoint->next = NULL;
                }
                delete startingDeletePoint;
                temp = temp->next;
                x = 0;
            }
            else
            {
                x = n;
                y = m;
            }
        }
        return head;
    }
};