#include <bits/stdc++.h>
using namespace std;

// Problem : https://www.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list5035/1
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

// Bruteforce Approach in O(n^2) Time Complexity and O(1) Space Complexity
class Solution
{
public:
    Node *divide(Node *head)
    {
        // code here
        Node *evenHead = NULL;
        Node *evenTail = NULL;
        Node *oddHead = NULL;
        Node *oddTail = NULL;
        while (true)
        {
            bool evenNodeFound = false;
            Node *curr = head;
            Node *prev = NULL;
            while (curr != NULL)
            {
                if (!(curr->data % 2))
                {
                    evenNodeFound = true;
                    break;
                }
                else
                {
                    prev = curr;
                    curr = curr->next;
                }
            }
            if (!evenNodeFound)
            {
                break;
            }
            if (evenHead == NULL)
            {
                evenHead = curr;
                if (prev == NULL)
                {
                    head = curr->next;
                    curr = curr->next;
                }
                else
                {
                    prev->next = curr->next;
                    curr = prev->next;
                }
                evenTail = evenHead;
            }
            else
            {
                evenTail->next = curr;
                evenTail = evenTail->next;
                if (prev == NULL)
                {
                    head = curr->next;
                    curr = curr->next;
                }
                else
                {
                    prev->next = curr->next;
                    curr = prev->next;
                }
            }
        }

        if (evenHead == NULL)
        {
            return head;
        }
        else
        {
            evenTail->next = head;
            return evenHead;
        }
    }
};

// Better Approach in O(n) Time Complexity and O(n) Space Complexity
class Solution
{
public:
    Node *divide(Node *head)
    {
        // code here
        if (head == NULL)
        {
            return head;
        }
        vector<int> values;
        Node *temp = head;
        while (temp != NULL)
        {
            if (!(temp->data % 2))
            {
                values.push_back(temp->data);
            }
            temp = temp->next;
        }
        temp = head;
        while (temp != NULL)
        {
            if (temp->data % 2)
            {
                values.push_back(temp->data);
            }
            temp = temp->next;
        }

        Node *outputHead = new Node(values[0]);
        Node *outputTail = outputHead;
        for (int i = 1; i < values.size(); i++, outputTail = outputTail->next)
        {
            outputTail->next = new Node(values[i]);
        }
        return outputHead;
    }
};

// More Better Approach in O(n) Time Complexity and O(n) Space Complexity
class Solution
{
public:
    Node *divide(Node *head)
    {
        // code here
        if (head == NULL)
        {
            return head;
        }
        vector<Node *> values;
        Node *temp = head;
        while (temp != NULL)
        {
            if (!(temp->data % 2))
            {
                values.push_back(temp);
            }
            temp = temp->next;
        }
        temp = head;
        while (temp != NULL)
        {
            if (temp->data % 2)
            {
                values.push_back(temp);
            }
            temp = temp->next;
        }

        Node *outputHead = values[0];
        Node *outputTail = outputHead;
        for (int i = 1; i < values.size(); i++, outputTail = outputTail->next)
        {
            outputTail->next = values[i];
        }
        outputTail->next = NULL;
        return outputHead;
    }
};

// Optimal Approach in O(n) Time Complexity and O(1) Space Complexity
class Solution
{
public:
    Node *divide(Node *head)
    {
        // code here
        if (head == NULL)
        {
            return head;
        }

        Node *evenHead = NULL;
        Node *evenTail = NULL;
        Node *oddHead = NULL;
        Node *oddTail = NULL;
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data % 2)
            {
                if (oddHead == NULL)
                {
                    oddHead = temp;
                    oddTail = temp;
                }
                else
                {
                    oddTail->next = temp;
                    oddTail = oddTail->next;
                }
            }
            else
            {
                if (evenHead == NULL)
                {
                    evenHead = temp;
                    evenTail = evenHead;
                }
                else
                {
                    evenTail->next = temp;
                    evenTail = evenTail->next;
                }
            }
            temp = temp->next;
        }

        if (evenTail != NULL)
        {
            evenTail->next = oddHead;
            if (oddTail != NULL)
            {
                oddTail->next = NULL;
            }
            return evenHead;
        }
        else
        {
            return oddHead;
        }
    }
};