#include <bits/stdc++.h>
using namespace std;

/*
  Node is defined as
*/
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }

} *head;

// Bruteforce Approach with O(n) Time Complexity and O(n) Space Complexity
class Solution
{
public:
    Node *reverse(Node *head)
    {
        if (head == NULL)
        {
            return head;
        }

        Node *prev = NULL;
        Node *curr = head;
        Node *next = NULL;
        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    Node *reverseKGroup(Node *head, int k)
    {
        // code here
        if (head == NULL || head->next == NULL || k <= 1)
        {
            return head;
        }
        Node *temp = head;
        Node *firstNode = head;
        int count = k;
        while (temp != NULL && count != 1)
        {
            temp = temp->next;
            count--;
        }
        Node *nextNode = NULL;
        if (temp != NULL)
        {
            nextNode = temp->next;
            temp->next = NULL;
        }

        head = reverse(head);
        firstNode->next = reverseKGroup(nextNode, k);
        return head;
    }
};

// Optimized Approach with O(n) Time Complexity and O(1) Space Complexity
class Solution
{
public:
    Node *reverse(Node *head)
    {
        if (head == NULL)
        {
            return head;
        }

        Node *prev = NULL;
        Node *curr = head;
        Node *next = NULL;
        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    Node *reverseKGroup(Node *head, int k)
    {
        // code here
        Node *temp = head;
        Node *outputHead = NULL;
        Node *startReverseHead = head;
        Node *reverseTail = head;
        int count = 1;
        while (temp != NULL)
        {
            if (count == k)
            {
                Node *nextNode = temp->next;
                temp->next = NULL;
                Node *reverseHead = reverse(startReverseHead);
                if (outputHead == NULL)
                {
                    outputHead = reverseHead;
                }
                else
                {
                    reverseTail->next = reverseHead;
                    reverseTail = startReverseHead;
                }
                startReverseHead = nextNode;
                temp = nextNode;
                count = 0;
            }
            else
            {
                temp = temp->next;
            }
            count++;
        }
        if (outputHead == NULL)
        {
            outputHead = reverse(startReverseHead);
        }
        else
        {
            reverseTail->next = reverse(startReverseHead);
        }
        return outputHead;
    }
};