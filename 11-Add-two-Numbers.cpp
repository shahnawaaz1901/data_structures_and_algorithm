#include <bits/stdc++.h>
using namespace std;

// Problem : https://www.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1
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

// Bruteforce Approach with O(n1 + n2) Time Complexity and O(n1 + n2) Space Complexity
class Solution
{
public:
    Node *reverse(Node *head)
    {
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

    vector<int> getArrayByLL(Node *head)
    {
        vector<int> output;
        while (head != NULL)
        {
            output.push_back(head->data);
            head = head->next;
        }
        return output;
    }

    void reverseArray(vector<int> &arr)
    {
        int i = 0;
        int n = arr.size() - 1;
        while (i < n)
        {
            int temp = arr[i];
            arr[i] = arr[n];
            arr[n] = temp;
            i++;
            n--;
        }
    }
    vector<int> getOutputArray(Node *head1, Node *head2)
    {
        vector<int> head1Values = getArrayByLL(head1);
        vector<int> head2Values = getArrayByLL(head2);
        reverseArray(head1Values);
        reverseArray(head2Values);
        vector<int> output;
        int i = 0;
        int carry = 0;
        while (i < head1Values.size() && i < head2Values.size())
        {
            int sum = head1Values[i] + head2Values[i] + carry;
            output.push_back(sum % 10);
            carry = sum / 10;
            i++;
        }

        while (i < head1Values.size())
        {
            output.push_back(head1Values[i] + carry);
            carry = 0;
            i++;
        }

        while (i < head2Values.size())
        {
            output.push_back(head2Values[i] + carry);
            carry = 0;
            i++;
        }

        if (carry)
        {
            output.push_back(carry);
        }
        return output;
    }
    Node *addTwoLists(Node *head1, Node *head2)
    {
        // code here
        vector<int> out = getOutputArray(head1, head2);
        Node *head = new Node(out[0]);
        Node *tail = head;
        for (int i = 1; i < out.size(); i++)
        {
            tail->next = new Node(out[i]);
            tail = tail->next;
        }
        Node *output = reverse(head);
        while (output != NULL && output->data == 0)
        {
            output = output->next;
        }
        return output;
    }
};

// Optimized Approach with O(n1 + n2) Time Complexity and O(n1 + n2) Space Complexity
class Solution
{
public:
    Node *reverse(Node *head)
    {
        if (head == NULL || head->next == NULL)
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

    Node *addTwoLLNumbers(Node *head1, Node *head2, int carry)
    {
        if (head1 == NULL && head2 == NULL)
        {
            if (carry)
            {
                return new Node(carry);
            }
            else
            {
                return NULL;
            }
        }
        if (head1 == NULL)
        {
            head2->data = head2->data + carry;
            return head2;
        }

        if (head2 == NULL)
        {
            head1->data = head1->data + carry;
            return head1;
        }

        int sum = head1->data + head2->data + carry;
        Node *head = new Node(sum % 10);
        head->next = addTwoLLNumbers(head1->next, head2->next, sum / 10);
        return head;
    }

    Node *addTwoLists(Node *head1, Node *head2)
    {
        Node *reverseOfHead1 = reverse(head1);
        Node *reverseOfHead2 = reverse(head2);
        int carry = 0;
        Node *sum = addTwoLLNumbers(reverseOfHead1, reverseOfHead2, carry);
        sum = reverse(sum);
        while (sum != NULL && sum->data == 0)
        {
            sum = sum->next;
        }
        return sum;
    }
};

// Optimal Approach with O(n1 + n2) Time Complexity and O(1) Space Complexity
class Solution
{
public:
    Node *reverse(Node *head)
    {
        if (head == NULL || head->next == NULL)
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

    Node *addTwoLists(Node *head1, Node *head2)
    {
        Node *reverseOfHead1 = reverse(head1);
        Node *reverseOfHead2 = reverse(head2);
        int carry = 0;
        Node *head = NULL;
        Node *tail = NULL;
        while (reverseOfHead1 != NULL && reverseOfHead2 != NULL)
        {
            int sum = reverseOfHead1->data + reverseOfHead2->data + carry;
            int digit = sum % 10;
            carry = sum / 10;
            Node *newNode = new Node(digit);
            if (head == NULL)
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
                tail->next = newNode;
                tail = tail->next;
            }
            reverseOfHead1 = reverseOfHead1->next;
            reverseOfHead2 = reverseOfHead2->next;
        }

        while (reverseOfHead1 != NULL)
        {
            int sum = reverseOfHead1->data + carry;
            carry = sum / 10;
            int digit = sum % 10;
            tail->next = new Node(digit);
            tail = tail->next;
            reverseOfHead1 = reverseOfHead1->next;
        }
        while (reverseOfHead2 != NULL)
        {
            int sum = reverseOfHead2->data + carry;
            carry = sum / 10;
            int digit = sum % 10;
            tail->next = new Node(digit);
            tail = tail->next;
            reverseOfHead2 = reverseOfHead2->next;
        }

        if (carry != 0)
        {
            tail->next = new Node(carry);
            tail = tail->next;
        }
        Node *outputArr = reverse(head);
        while (outputArr != NULL && outputArr->data == 0)
        {
            outputArr = outputArr->next;
        }
        return outputArr;
    }
};