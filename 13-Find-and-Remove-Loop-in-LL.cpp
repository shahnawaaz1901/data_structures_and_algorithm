#include <bits/stdc++.h>
using namespace std;

// Problem : https://www.geeksforgeeks.org/problems/remove-loop-in-linked-list/1

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

// Bruteforce Approach with O(n^2) Time Complexity and O(n) Space Complexity
class Solution {
  public:
    bool nodeAlreadyPresent(vector<Node*>&nodesArray, Node *temp){
        for(int i = 0; i < nodesArray.size();i++){
            if(nodesArray[i] == temp){
                return true;
            }
        }
        return false;
    }
    void removeLoop(Node* head) {
        // code here
        if(head == nullptr || head->next == nullptr){
            return;
        }
        
        vector<Node *> nodesArray;
        Node *temp = head;
        Node *prev = NULL;
        while(temp != NULL){
            if(nodeAlreadyPresent(nodesArray, temp)){
                prev->next = nullptr;
                break;
            }
            nodesArray.push_back(temp);
            prev = temp;
            temp = temp->next;
        }
        
    }
};

// Better Approach with O(n) Time Complexity and O(n) Space Complexity
class Solution
{
public:
    void removeLoop(Node *head)
    {
        // code here
        if (head == NULL)
        {
            return;
        }

        if (head == head->next)
        {
            head->next = NULL;
            return;
        }
        Node *temp = head;
        unordered_map<Node *, bool> addressMap;
        Node *prev = NULL;
        while (temp != NULL)
        {
            if (addressMap[temp])
            {
                prev->next = NULL;
                break;
            }
            addressMap[temp] = true;
            prev = temp;
            temp = temp->next;
        }
    }
};

// Optimal Approach with O(n) Time Complexity and O(1) Space Complexity
class Solution
{
public:
    void removeLoop(Node *head)
    {
        // code here
        if (head == nullptr || head->next == nullptr)
        {
            return;
        }

        Node *slow = head->next;
        Node *fast = head->next->next;
        while (fast != nullptr && fast->next != nullptr)
        {
            if (slow == fast)
            {
                slow = head;
                break;
            }
            slow = slow->next;
            fast = fast->next->next;
        }

        if (fast == nullptr || fast->next == nullptr)
        {
            return;
        }

        if (slow == fast)
        {
            fast = fast->next;
            while (fast->next != slow)
            {
                fast = fast->next;
            }
        }
        else
        {
            while (fast->next != slow->next)
            {
                fast = fast->next;
                slow = slow->next;
            }
        }

        fast->next = nullptr;
    }
};