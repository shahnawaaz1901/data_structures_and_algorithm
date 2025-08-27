#include <bits/stdc++.h>
using namespace std;

// Problem : https://www.geeksforgeeks.org/problems/merge-two-sorted-linked-lists/1
/* Link list Node */
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

// Bruteforce Approach with O(m + n) Time and O(m+n) Space
class Solution
{
public:
    Node *sortedMerge(Node *head1, Node *head2)
    {
        // code here
        if (head1 == NULL && head2 == NULL)
        {
            return head1;
        }

        if (head1 == NULL)
        {
            return head2;
        }

        if (head2 == NULL)
        {
            return head1;
        }
        Node *mainHead = NULL;
        if (head1->data < head2->data)
        {
            mainHead = head1;
            head1->next = sortedMerge(head1->next, head2);
        }
        else
        {
            mainHead = head2;
            head2->next = sortedMerge(head1, head2->next);
        }

        return mainHead;
    }
};

// Optimal Approach with O(m+n) Time Complexity and O(1) Space Complexity
class Solution
{
public:
    Node *sortedMerge(Node *head1, Node *head2)
    {
        // code here
        if (head1 == NULL && head2 == NULL)
        {
            return head1;
        }

        if (head1 == NULL)
        {
            return head2;
        }

        if (head2 == NULL)
        {
            return head1;
        }
        Node *mainHead = NULL;
        Node *mainTail = NULL;
        if (head1->data < head2->data)
        {
            mainHead = head1;
            mainTail = head1;
            head1 = head1->next;
        }
        else
        {
            mainHead = head2;
            mainTail = head2;
            head2 = head2->next;
        }
        while (head1 != NULL && head2 != NULL)
        {
            if (head1->data < head2->data)
            {
                mainTail->next = head1;
                head1 = head1->next;
            }
            else
            {
                mainTail->next = head2;
                head2 = head2->next;
            }
            mainTail = mainTail->next;
        }

        if (head1 != NULL)
        {
            mainTail->next = head1;
        }

        if (head2 != NULL)
        {
            mainTail->next = head2;
        }

        return mainHead;
    }
};