#include <bits/stdc++.h>
using namespace std;

// Problem : https://www.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1

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
    Node *intersectPoint(Node *head1, Node *head2)
    {
        //  Code Here
        Node *temp1 = head1;
        while (temp1 != nullptr)
        {
            Node *temp2 = head2;
            while (temp2 != nullptr)
            {
                if (temp1 == temp2)
                {
                    return temp1;
                }
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
        }
        return nullptr;
    }
};

// Better Approach with O(n) Time Complexity and O(n) Space Complexity
class Solution
{
public:
    Node *intersectPoint(Node *head1, Node *head2)
    {
        //  Code Here
        Node *temp1 = head1;
        unordered_map<Node *, bool> nodes;
        while (temp1 != nullptr)
        {
            nodes[temp1] = true;
            temp1 = temp1->next;
        }
        Node *temp2 = head2;
        while (temp2 != nullptr)
        {
            if (nodes[temp2])
            {
                return temp2;
            }
            temp2 = temp2->next;
        }
        return nullptr;
    }
};

// Optimal Approach with O(n) Time Complexity and O(1) Space Complexity
//* Approach 1
class Solution
{
public:
    int countNodes(Node *head)
    {
        int count = 0;
        while (head != NULL)
        {
            head = head->next;
            count++;
        }
        return count;
    }
    Node *intersectPoint(Node *head1, Node *head2)
    {
        //  Code Here
        int firstLLTotalNodes = countNodes(head1);
        int secondLLTotalNodes = countNodes(head2);
        Node *minLengthNode = firstLLTotalNodes > secondLLTotalNodes ? head2 : head1;
        Node *maxLengthNode = firstLLTotalNodes > secondLLTotalNodes ? head1 : head2;
        int minLength = firstLLTotalNodes > secondLLTotalNodes ? secondLLTotalNodes : firstLLTotalNodes;
        int maxLength = firstLLTotalNodes > secondLLTotalNodes ? firstLLTotalNodes : secondLLTotalNodes;
        while (maxLength != minLength)
        {
            maxLengthNode = maxLengthNode->next;
            maxLength--;
        }

        if (minLengthNode == maxLengthNode)
        {
            return minLengthNode;
        }
        while (minLengthNode != NULL && maxLengthNode != NULL)
        {
            if (minLengthNode == maxLengthNode)
            {
                return minLengthNode;
            }
            minLengthNode = minLengthNode->next;
            maxLengthNode = maxLengthNode->next;
        }
    }
};

// Optimal Approach with O(n) Time Complexity and O(1) Space Complexity
//* Approach 2
class Solution
{
public:
    int countNodes(Node *head)
    {
        int count = 0;
        while (head != NULL)
        {
            head = head->next;
            count++;
        }
        return count;
    }

    Node *getNodeOfInterSection(int dif, Node *head1, Node *head2)
    {
        while (dif != 0)
        {
            dif--;
            head1 = head1->next;
        }

        while (head1 != NULL && head2 != NULL)
        {
            if (head1 == head2)
            {
                return head1;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
    }
    Node *intersectPoint(Node *head1, Node *head2)
    {
        //  Code Here
        int firstLLTotalNodes = countNodes(head1);
        int secondLLTotalNodes = countNodes(head2);
        if (firstLLTotalNodes < secondLLTotalNodes)
        {
            int dif = secondLLTotalNodes - firstLLTotalNodes;
            return getNodeOfInterSection(dif, head2, head1);
        }
        else
        {
            int dif = firstLLTotalNodes - secondLLTotalNodes;
            return getNodeOfInterSection(dif, head1, head2);
        }
    }
};

// Optimal Approach with O(n) Time Complexity and O(1) Space Complexity
//* Approach 3
class Solution
{
public:
    // Only works in Guaranteed intersected Node
    Node *intersectPoint(Node *head1, Node *head2)
    {
        //  Code Here
        Node *temp1 = head1;
        Node *temp2 = head2;
        while (true)
        {
            if (temp1 == NULL)
            {
                temp1 = head1;
            }

            if (temp2 == NULL)
            {
                temp2 = head2;
            }
            if (temp1 == temp2)
            {
                return temp1;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
};

// Optimal Approach with O(n) Time Complexity and O(1) Space Complexity
//* Approach 4
class Solution
{
public:
    Node *intersectPoint(Node *head1, Node *head2)
    {
        //  Code Here
        Node *temp1 = head1;
        Node *temp2 = head2;
        while (temp1 != temp2)
        {
            temp1 = temp1 != NULL ? temp1->next : head2;
            temp2 = temp2 != NULL ? temp2->next : head1;
        }
        return temp1;
    }
};