#include <bits/stdc++.h>
using namespace std;

// Problem : https://www.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

// Bruteforce Approach with O(n^2) Time Complexity and O(n) Space Complexity
class Solution
{
public:
    Node *reverse(Node *head)
    {
        // code here
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        Node *reverseHead = reverse(head->next);
        Node *temp = reverseHead;
        temp->prev = NULL;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = head;
        head->prev = temp;
        head->next = NULL;
        return reverseHead;
    }
};

// Better Approach with O(n) Time Complexity and O(n) Space Complexity
class Solution
{
public:
    Node *reverse(Node *head)
    {
        // code here
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        Node *reverseHead = reverse(head->next);
        reverseHead->prev = NULL;
        Node *lastNode = head->next;
        head->next = NULL;
        lastNode->next = head;
        head->prev = lastNode;
        return reverseHead;
    }
};

// Optimal Approach with O(n) Time Complexity and O(1) Space Complexity
class Solution
{
public:
    // Function to reverse a doubly linked list
    Node *reverseDLL(Node *head)
    {
        // Your code here
        if (head == NULL)
        {
            return head;
        }
        Node *temp = head;
        Node *prev = NULL;
        while (temp != NULL)
        {
            Node *c = temp->next;
            temp->next = temp->prev;
            temp->prev = c;
            prev = temp;
            temp = temp->prev;
        }
        return prev;
    }
};