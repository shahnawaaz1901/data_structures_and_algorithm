#include <bits/stdc++.h>
using namespace std;

// Problem : https://www.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/0

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// Bruteforce Approach with O(n) Time Complexity and O(n-k) Space Complexity
class Solution
{
public:
    int getKthElementFromStart(Node *head, int k)
    {
        if (k == 0)
        {
            return head->data;
        }

        return getKthElementFromStart(head->next, k - 1);
    }
    int getKthFromLast(Node *head, int k)
    {
        // code here
        Node *temp = head;
        int count = 0;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }

        if (count - k < 0)
        {
            return -1;
        }

        return getKthElementFromStart(head, count - k);
    }
};

// Optimal Approach with O(n) Time Complexity and O(1) Space Complexity
class Solution
{
public:
    int getKthFromLast(Node *head, int k)
    {
        // code here
        Node *temp = head;
        int count = 0;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        int dif = count - k;
        if (dif < 0)
        {
            return -1;
        }
        count = 0;
        temp = head;
        while (temp != NULL)
        {
            if (count == dif)
            {
                return temp->data;
            }
            temp = temp->next;
            count++;
        }
    }
};