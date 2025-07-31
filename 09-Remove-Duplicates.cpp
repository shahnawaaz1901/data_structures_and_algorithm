#include <bits/stdc++.h>
using namespace std;

// Problem : https://www.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/0
/*
    The structure of linked list is the following
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
};

// Bruteforce Approach within O(n^2) Time Complexity and O(1) Space Complexity
class Solution
{
public:
    Node *removeDuplicates(Node *head)
    {
        // your code goes here
        Node *temp = head;
        while (temp != NULL)
        {
            Node *next = temp->next;
            Node *prev = NULL;
            while (next != NULL)
            {
                if (next->data == temp->data)
                {
                    Node *nodeToBeDeleted = next;
                    if (prev == NULL)
                    {
                        temp->next = next->next;
                    }
                    else
                    {
                        prev->next = next->next;
                    }
                    nodeToBeDeleted->next = NULL;
                    delete nodeToBeDeleted;
                    if (prev == NULL)
                    {
                        break;
                    }
                    else
                    {
                        next = prev;
                    }
                }
                prev = next;
                next = next->next;
            }
            temp = temp->next;
        }
        return head;
    }
};

// Optimal Solution with O(n) Time Complexity and O(n) Space Complexity
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