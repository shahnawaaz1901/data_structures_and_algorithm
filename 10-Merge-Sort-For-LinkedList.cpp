#include <bits/stdc++.h>
using namespace std;

// Problem : https://www.geeksforgeeks.org/problems/sort-a-linked-list/1

/*
    The structure of linked list is the following
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

class Solution
{
public:
    // Function to sort the given linked list using Merge Sort.
    Node *findMid(Node *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        Node *slow = head;
        Node *fast = head->next;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

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

        if (head1->data < head2->data)
        {
            head1->next = mergeSortedLL(head1->next, head2);
            return head1;
        }
        else
        {
            head2->next = mergeSortedLL(head1, head2->next);
            return head2;
        }
    }
    Node *mergeSort(Node *head)
    {
        // your code here
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        Node *midNode = findMid(head);
        Node *firstHead = head;
        Node *secondHead = midNode->next;
        midNode->next = NULL;
        Node *node1 = mergeSort(firstHead);
        Node *node2 = mergeSort(secondHead);

        return mergeSortedLL(node1, node2);
    }
};