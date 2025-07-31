#include <bits/stdc++.h>
using namespace std;

// Problem :

/* Class */
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

// Bruteforce Approach with O(n) Time Complexity and O(n) Space Complexity
class Solution
{
public:
    // Function to remove duplicates from sorted linked list.
    Node *removeDuplicates(Node *head)
    {
        // code here
        if (head == NULL)
        {
            return head;
        }
        Node *output = removeDuplicates(head->next);
        if (output == NULL)
        {
            return head;
        }
        if (output->data == head->data)
        {
            head->next = NULL;
            delete head;
            return output;
        }

        head->next = output;
        return head;
    }
};

// Optimal Approach O(n) Time Complexity and O(1) Space Complexity
class Solution
{
public:
    // Function to remove duplicates from sorted linked list.
    Node *removeDuplicates(Node *head)
    {
        // code here
        if (head == NULL)
        {
            return head;
        }
        Node *curr = head;
        Node *prev = NULL;
        while (curr != NULL)
        {
            if (prev == NULL)
            {
                prev = curr;
                curr = curr->next;
            }
            else if (prev->data == curr->data)
            {
                Node *temp = curr;
                prev->next = curr->next;
                curr = curr->next;
                temp->next = NULL;
                delete temp;
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};