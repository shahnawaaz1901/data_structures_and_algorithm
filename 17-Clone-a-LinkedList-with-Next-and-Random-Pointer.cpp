#include <bits/stdc++.h>
using namespace std;

// Problem : https://www.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer

class Node
{
public:
    int data;
    Node *next;
    Node *random;

    Node(int x)
    {
        data = x;
        next = NULL;
        random = NULL;
    }
};

// Bruteforce Approach in O(n) Time Complexity and O(n) Space Complexity using Recursion
class Solution
{
public:
    Node *cloneList(Node *head, unordered_map<Node *, Node *> &addresses)
    {
        if (head == NULL)
        {
            return head;
        }

        Node *newHead = new Node(head->data);
        addresses[head] = newHead;
        newHead->next = cloneList(head->next, addresses);
        newHead->random = addresses[head->random];
        return newHead;
    }
    Node *cloneLinkedList(Node *head)
    {
        // code here
        if (head == NULL)
        {
            return head;
        }

        unordered_map<Node *, Node *> addresses;
        return cloneList(head, addresses);
    }
};

// Better Approach in O(n) Time Complexity and O(n) Space Complexity
class Solution
{
public:
    Node *cloneLinkedList(Node *head)
    {
        // code here
        if (head == NULL)
        {
            return head;
        }
        Node *temp = head;
        Node *newHead = new Node(temp->data);
        Node *newTail = newHead;
        unordered_map<Node *, Node *> randomPointers;
        randomPointers[temp] = newHead;
        temp = temp->next;
        while (temp != NULL)
        {
            Node *newLLNode = new Node(temp->data);
            randomPointers[temp] = newLLNode;
            newTail->next = newLLNode;
            newTail = newTail->next;
            temp = temp->next;
        }
        temp = head;
        Node *newTemp = newHead;
        while (temp != NULL)
        {
            Node *randomNodeAddress = temp->random;
            if (randomNodeAddress != NULL)
            {
                newTemp->random = randomPointers[randomNodeAddress];
            }
            else
            {
                newTemp->random = NULL;
            }
            temp = temp->next;
            newTemp = newTemp->next;
        }

        return newHead;
    }
};

// Optimal Approach in O(n) Time Complexity and O(1) Space Complexity
class Solution
{
public:
    Node *cloneLinkedList(Node *head)
    {
        // code here
        if (head == NULL)
        {
            return head;
        }
        Node *temp = head;
        while (temp != NULL)
        {
            Node *newNode = new Node(temp->data);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = newNode->next;
        }

        temp = head;
        Node *outputHead = temp->next;
        Node *outputTail = outputHead;
        while (outputTail != NULL && outputTail->next != NULL)
        {
            Node *randomPointer = temp->random;
            outputTail->random = temp->random == NULL ? NULL : temp->random->next;
            temp = temp->next->next;
            outputTail = outputTail->next->next;
        }
        if (outputTail != NULL)
        {
            outputTail->random = temp->random == NULL ? NULL : temp->random->next;
        }
        temp = head;
        outputTail = outputHead;
        while (outputTail != NULL && outputTail->next != NULL)
        {
            temp->next = outputTail->next;
            temp = temp->next;
            outputTail->next = temp->next;
            outputTail = outputTail->next;
        }

        if (temp != NULL)
        {
            temp->next = NULL;
        }

        return outputHead;
    }
};