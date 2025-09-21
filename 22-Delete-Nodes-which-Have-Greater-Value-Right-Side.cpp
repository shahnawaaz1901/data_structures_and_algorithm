#include <bits/stdc++.h>
using namespace std;

// Problem : https://www.geeksforgeeks.org/problems/delete-nodes-having-greater-value-on-right/

//* Define Class
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

// Bruteforce Approach using O(n) Time Complexity and O(n) Space Complexity
class Solution
{
public:
    Node *compute(Node *head)
    {
        // your code goes here
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        head->next = compute(head->next);
        if (head->data < head->next->data)
        {
            Node *temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
        }

        return head;
    }
};

// Optimal Approach in O(n) Time Complexity and O(1) Space Complexity
class Solution
{
public:
    Node *reverse(Node *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        Node *curr = head;
        Node *prev = NULL;
        while (curr != NULL)
        {
            Node *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    Node *compute(Node *head)
    {
        // your code goes here
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        Node *reverseNodeHead = reverse(head);
        Node *temp = reverseNodeHead;
        while (temp != NULL && temp->next != NULL)
        {
            if (temp->data <= temp->next->data)
            {
                temp = temp->next;
            }
            else
            {
                Node *nodeToBeDeleted = temp->next;
                temp->next = temp->next->next;
                nodeToBeDeleted->next = NULL;
                delete nodeToBeDeleted;
            }
        }

        return reverse(reverseNodeHead);
    }
};