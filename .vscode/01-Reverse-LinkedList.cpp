#include <bits/stdc++.h>
using namespace std;

// Problem : https://www.geeksforgeeks.org/problems/reverse-a-linked-list/1
struct Node
{
    int data;
    struct Node *next;
};

// Bruteforce Approach in O(n^2) Time in O(n) Space
class Solution
{
public:
    Node *reverseList(struct Node *head)
    {
        // code here
        if (head == nullptr)
        {
            return head;
        }

        Node *reversedLinkedListHead = reverseList(head->next);
        if (reversedLinkedListHead == nullptr)
        {
            return head;
        }
        Node *temp = reversedLinkedListHead;
        while (temp != nullptr && temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = head;
        head->next = nullptr;
        return reversedLinkedListHead;
    }
};

// Better Approach in O(n) Time and O(n) Space
class Solution
{
public:
    Node *reverseList(struct Node *head)
    {
        // code here
        if (head == nullptr)
        {
            return head;
        }

        Node *reversedLinkedListHead = reverseList(head->next);
        if (reversedLinkedListHead == nullptr)
        {
            return head;
        }
        Node *temp = head->next;
        temp->next = head;
        head->next = nullptr;
        return reversedLinkedListHead;
    }
};

// Optimal Approach in O(n) Time and O(1) Space
class Solution
{
public:
    Node *reverseList(struct Node *head)
    {
        // code here
        if (head == nullptr)
        {
            return head;
        }

        Node *prev = nullptr;
        Node *curr = head;
        while (curr != nullptr)
        {
            Node *next = curr->next;

            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};
