#include <bits/stdc++.h>
using namespace std;

// Problem : https://www.geeksforgeeks.org/dsa/quicksort-on-singly-linked-list/

/* A node of the singly linked list */
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

// Solution in O(n^2) Time Complexity and O(n) Space Complexity
class Solution
{
public:
    struct Node *getTail(struct Node *head)
    {
        while (head->next != NULL)
        {
            head = head->next;
        }
        return head;
    }

    struct Node *getPartition(struct Node *head, struct Node *tail)
    {
        if (head == NULL || head == tail)
        {
            return head;
        }

        struct Node *pivot = head;
        struct Node *curr = head;
        struct Node *prev = head;
        while (curr != tail->next)
        {
            if (curr->data < pivot->data)
            {
                swap(curr->data, prev->next->data);
                prev = prev->next;
            }
            curr = curr->next;
        }
        swap(pivot->data, prev->data);
        return prev;
    }
    void quickSort(struct Node *head, struct Node *tail)
    {
        if (head == NULL || head == tail)
        {
            return;
        }

        Node *pivot = getPartition(head, tail);
        quickSort(head, pivot);
        quickSort(pivot->next, tail);
    }
    struct Node *quickSort(struct Node *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        Node *tail = getTail(head);
        quickSort(head, tail);
        return head;
    }
};