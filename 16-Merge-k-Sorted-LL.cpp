#include <bits/stdc++.h>
using namespace std;

// Problem : https://www.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1
// Problem : https://leetcode.com/problems/merge-k-sorted-lists/description/
class Node
{
public:
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// Bruteforce Approach with O(n^2) Time Complexity and O(1) Space Complexity
class Solution
{
public:
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

        Node *temp1 = head1;
        Node *temp2 = head2;
        Node *outputHead = NULL;
        Node *outputTail = NULL;
        if (temp1->data < temp2->data)
        {
            outputHead = temp1;
            outputTail = outputHead;
            temp1 = temp1->next;
        }
        else
        {
            outputHead = temp2;
            outputTail = outputHead;
            temp2 = temp2->next;
        }
        while (temp1 != NULL && temp2 != NULL)
        {
            if (temp1->data < temp2->data)
            {
                outputTail->next = temp1;
                temp1 = temp1->next;
            }
            else
            {
                outputTail->next = temp2;
                temp2 = temp2->next;
            }
            outputTail = outputTail->next;
        }

        if (temp1 != NULL)
        {
            outputTail->next = temp1;
        }

        if (temp2 != NULL)
        {
            outputTail->next = temp2;
        }
        return outputHead;
    }
    Node *mergeKLists(vector<Node *> &arr)
    {
        // code here
        Node *outputHead = NULL;
        for (int i = 0; i < arr.size(); i++)
        {
            outputHead = mergeSortedLL(outputHead, arr[i]);
        }
        return outputHead;
    }
};

// Better Approach with O(n) Time Complexity and O(n) Space Complexity
class Solution
{
public:
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

        Node *temp1 = head1;
        Node *temp2 = head2;
        Node *outputHead = NULL;
        Node *outputTail = NULL;
        if (temp1->data < temp2->data)
        {
            outputHead = temp1;
            outputTail = outputHead;
            temp1 = temp1->next;
        }
        else
        {
            outputHead = temp2;
            outputTail = outputHead;
            temp2 = temp2->next;
        }
        while (temp1 != NULL && temp2 != NULL)
        {
            if (temp1->data < temp2->data)
            {
                outputTail->next = temp1;
                temp1 = temp1->next;
            }
            else
            {
                outputTail->next = temp2;
                temp2 = temp2->next;
            }
            outputTail = outputTail->next;
        }

        if (temp1 != NULL)
        {
            outputTail->next = temp1;
        }

        if (temp2 != NULL)
        {
            outputTail->next = temp2;
        }
        return outputHead;
    }

    Node *mergeKSortedLL(vector<Node *> &arr, int start, int end)
    {
        if (start > end)
        {
            return NULL;
        }

        if (start == end)
        {
            return arr[start];
        }

        int mid = (start + end) / 2;
        Node *leftPortion = mergeKSortedLL(arr, start, mid);
        Node *rightPortion = mergeKSortedLL(arr, mid + 1, end);

        return mergeSortedLL(leftPortion, rightPortion);
    }
    Node *mergeKLists(vector<Node *> &arr)
    {
        // code here
        if (!arr.size())
        {
            return NULL;
        }
        return mergeKSortedLL(arr, 0, arr.size() - 1);
    }
};

// Better Approach with O(n) Time Complexity and O(n) Space Complexity
class Solution
{
public:
    Node *mergeKLists(vector<Node *> &arr)
    {
        // code here
        Node *outputHead = NULL;
        Node *outputTail = NULL;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < arr.size(); i++)
        {
            Node *head = arr[i];
            while (head != NULL)
            {
                pq.push(head->data);
                head = head->next;
            }
        }

        while (!pq.empty())
        {
            Node *newNode = new Node(pq.top());
            pq.pop();
            if (outputHead == NULL)
            {
                outputHead = newNode;
                outputTail = outputHead;
            }
            else
            {
                outputTail->next = newNode;
                outputTail = outputTail->next;
            }
        }
        return outputHead;
    }
};

// Optimal Approach with O(n) Time Complexity and O(1) Space Complexity
class Solution
{
public:
    Node *mergeKLists(vector<Node *> &arr)
    {
        // code here
        Node *outputHead = NULL;
        Node *outputTail = NULL;
        while (true)
        {
            Node *minNode = NULL;
            bool isAllNodesNull = true;
            int minNodeIndex = -1;
            for (int i = 0; i < arr.size(); i++)
            {
                Node *head = arr[i];
                if (head != NULL)
                {
                    if (minNode == NULL)
                    {
                        minNode = head;
                        minNodeIndex = i;
                    }
                    else if (minNode->data > head->data)
                    {
                        minNode = head;
                        minNodeIndex = i;
                    }
                    isAllNodesNull = false;
                }
            }
            if (isAllNodesNull)
            {
                break;
            }
            if (outputHead == NULL)
            {
                outputHead = minNode;
                outputTail = outputHead;
            }
            else
            {
                outputTail->next = minNode;
                outputTail = outputTail->next;
            }
            arr[minNodeIndex] = arr[minNodeIndex]->next;
        }
        return outputHead;
    }
};