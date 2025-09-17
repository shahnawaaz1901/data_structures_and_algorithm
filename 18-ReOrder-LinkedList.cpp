#include <bits/stdc++.h>
using namespace std;

// Problem : https://www.geeksforgeeks.org/problems/reorder-list/1

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
    pair<Node *, Node *> findMid(Node *head)
    {
        Node *slow = head;
        Node *prev = NULL;
        Node *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pair<Node *, Node *> output = {prev, slow};
        return output;
    }

    Node *reverseLL(Node *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        Node *curr = head;
        Node *prev = NULL;
        while (curr != NULL)
        {
            Node *next = curr->next;
            curr->next = prev;
            prev = curr;

            curr = next;
        }
        return prev;
    }
    void reorderList(Node *head)
    {
        // Your code here
        if (head == NULL || head->next == NULL)
        {
            return;
        }

        Node *temp = head;
        while (temp != NULL && temp->next != NULL)
        {
            Node *prevNode = temp;
            Node *nextNode = temp->next;
            while (nextNode->next != NULL)
            {
                prevNode = nextNode;
                nextNode = nextNode->next;
            }
            Node *lastNode = nextNode;
            prevNode->next = NULL;
            lastNode->next = temp->next;
            temp->next = lastNode;
            temp = lastNode->next;
        }
    }
};

// Optimized Approach in O(n) Time Complexity and O(n) Space Complexity
class Solution
{
public:
    void reorderList(Node *head)
    {
        // Your code here
        vector<int> values;
        Node *temp = head;
        while (temp != NULL)
        {
            values.push_back(temp->data);
            temp = temp->next;
        }

        int midIndex = (values.size() / 2);
        int i = midIndex;
        int j = values.size() - 1;
        vector<int> outputElements;
        i = 0;
        j = values.size() - 1;
        for (int k = 0; i < midIndex && j >= midIndex; k++)
        {
            if (k % 2)
            {
                outputElements.push_back(values[j]);
                j--;
            }
            else
            {
                outputElements.push_back(values[i]);
                i++;
            }
        }

        while (j >= midIndex)
        {
            outputElements.push_back(values[j]);
            j--;
        }

        while (i < midIndex)
        {
            outputElements.push_back(values[i]);
            i++;
        }

        temp = head;
        for (int i = 0; i < outputElements.size(); i++, temp = temp->next)
        {
            temp->data = outputElements[i];
        }
    }
};

// Optimal Approach in O(n) Time Complexity and O(1) Space Complexity
class Solution
{
public:
    pair<Node *, Node *> findMid(Node *head)
    {
        Node *slow = head;
        Node *prev = NULL;
        Node *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pair<Node *, Node *> output = {prev, slow};
        return output;
    }

    Node *reverseLL(Node *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        Node *curr = head;
        Node *prev = NULL;
        while (curr != NULL)
        {
            Node *next = curr->next;
            curr->next = prev;
            prev = curr;

            curr = next;
        }
        return prev;
    }
    void reorderList(Node *head)
    {
        // Your code here
        if (head == NULL || head->next == NULL)
        {
            return;
        }

        pair<Node *, Node *> mid = findMid(head);
        if (mid.first != NULL)
        {
            mid.first->next = NULL;
        }

        Node *temp1 = head;
        Node *temp2 = reverseLL(mid.second);
        Node *outputHead = temp1;
        Node *outputTail = outputHead;
        temp1 = temp1->next;
        int i = 1;
        while (temp1 != NULL && temp2 != NULL)
        {
            if (i % 2)
            {
                outputTail->next = temp2;
                temp2 = temp2->next;
            }
            else
            {
                outputTail->next = temp1;
                if (temp1->next == NULL)
                {
                    outputTail = outputTail->next;
                    break;
                }
                temp1 = temp1->next;
            }
            i++;
            outputTail = outputTail->next;
        }
        outputTail->next = temp2;
    }
};