#include <iostream>
using namespace std;

// Problem : https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// Better Approach O(n)
class Solution
{
public:
    Node *segregate(Node *head)
    {
        // code here
        if (head == NULL)
        {
            return head;
        }
        Node *zeroHead = NULL, *zeroTail = NULL;
        Node *oneHead = NULL, *oneTail = NULL;
        Node *twoHead = NULL, *twoTail = NULL;
        Node *temp = head;
        while (temp)
        {
            if (temp->data == 0)
            {
                if (zeroTail != NULL)
                {
                    zeroTail->next = temp;
                    zeroTail = zeroTail->next;
                }
                else
                {
                    zeroHead = temp;
                    zeroTail = temp;
                }
            }
            else if (temp->data == 1)
            {
                if (oneTail != NULL)
                {
                    oneTail->next = temp;
                    oneTail = oneTail->next;
                }
                else
                {
                    oneHead = temp;
                    oneTail = temp;
                }
            }
            else
            {
                if (twoTail != NULL)
                {
                    twoTail->next = temp;
                    twoTail = twoTail->next;
                }
                else
                {
                    twoHead = temp;
                    twoTail = temp;
                }
            }

            temp = temp->next;
        }

        if (zeroHead != NULL && oneHead != NULL && twoHead != NULL)
        {
            zeroTail->next = oneHead;
            oneTail->next = twoHead;
            twoTail->next = NULL;
            return zeroHead;
        }
        else if (zeroHead != NULL && oneHead != NULL)
        {
            zeroTail->next = oneHead;
            oneTail->next = NULL;
            return zeroHead;
        }
        else if (zeroHead != NULL && twoHead != NULL)
        {
            zeroTail->next = twoHead;
            twoTail->next = NULL;
            return zeroHead;
        }
        else if (oneHead != NULL && twoHead != NULL)
        {
            oneTail->next = twoHead;
            twoTail->next = NULL;
            return oneHead;
        }
        else if (zeroHead != NULL)
        {
            return zeroHead;
        }
        else if (oneHead != NULL)
        {
            return oneHead;
        }
        else
        {
            return twoHead;
        }
    }
};

// Optimal Approach O(n)
class Solution
{
public:
    Node *segregate(Node *head)
    {
        // code here
        if (head == NULL)
        {
            return head;
        }
        int countZero = 0;
        int countOne = 0;
        int countTwo = 0;
        Node *tail = head;
        while (tail != NULL)
        {
            if (tail->data == 0)
            {
                countZero++;
            }
            else if (tail->data == 1)
            {
                countOne++;
            }
            else
            {
                countTwo++;
            }
            tail = tail->next;
        }
        tail = head;

        while (countZero-- && tail != NULL)
        {
            tail->data = 0;
            tail = tail->next;
        }

        while (countOne-- && tail != NULL)
        {
            tail->data = 1;
            tail = tail->next;
        }

        while (countTwo-- && tail != NULL)
        {
            tail->data = 2;
            tail = tail->next;
        }
        if (tail != NULL)
        {
            tail->next = NULL;
        }
        return head;
    }
};