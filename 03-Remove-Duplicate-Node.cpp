#include <bits/stdc++.h>
using namespace std;

// Problem : https://www.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1
/*
    The structure of linked list is the following
*/

// Bruteforce Approach with O(n^2) Time Complexity and O(n) Space Complexity
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

class Solution
{
public:
    Node *removeDuplicates(Node *head)
    {
        // your code goes here
        if (head == NULL)
        {
            return head;
        }

        Node *uniqueElementsHead = removeDuplicates(head->next);
        Node *temp = uniqueElementsHead;
        Node *prev = NULL;
        while (temp != NULL)
        {
            if (temp->data == head->data)
            {
                Node *deleteNode = temp;
                if (prev == NULL)
                {
                    uniqueElementsHead = temp->next;
                }
                else
                {
                    prev->next = temp->next;
                }
                deleteNode->next = NULL;
                delete deleteNode;
                break;
            }
            prev = temp;
            temp = temp->next;
        }
        head->next = uniqueElementsHead;
        return head;
    }
};

// Better Approach with O(n^2) Time Complexity and O(1) Space Complexity
class Solution
{
public:
    Node *removeDuplicates(Node *head)
    {
        // your code goes here
        if (head == NULL)
        {
            return head;
        }

        Node *temp = head;
        while (temp != NULL)
        {
            Node *nextElement = temp->next;
            Node *prev = NULL;
            while (nextElement != NULL)
            {
                if (nextElement->data == temp->data)
                {
                    Node *nodeToBeDeleted = nextElement;
                    if (prev == NULL)
                    {
                        temp->next = nextElement->next;
                    }
                    else
                    {
                        prev->next = nextElement->next;
                    }
                    nextElement = nextElement->next;
                    nodeToBeDeleted->next = NULL;
                    delete nodeToBeDeleted;
                }
                else
                {
                    prev = nextElement;
                    nextElement = nextElement->next;
                }
            }
            temp = temp->next;
        }
        return head;
    }
};

// Optimal Approach with O(n) Time Complexity and O(n) Space Complexity
class Solution
{
public:
    Node *removeDuplicates(Node *head)
    {
        // your code goes here
        Node *temp = head;
        unordered_map<int, int> freq;
        while (temp != NULL)
        {
            freq[temp->data]++;
            temp = temp->next;
        }

        temp = head;
        Node *prev = NULL;
        while (temp != NULL)
        {
            if (freq[temp->data] < 0)
            {
                prev->next = temp->next;
                Node *nodeToBeDeleted = temp;
                nodeToBeDeleted->next = NULL;
                delete nodeToBeDeleted;
                temp = prev;
            }
            prev = temp;
            freq[temp->data] = -1;
            temp = temp->next;
        }
        return head;
    }
};