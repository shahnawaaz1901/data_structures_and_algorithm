#include <bits/stdc++.h>
using namespace std;

// Problem : https://www.geeksforgeeks.org/problems/delete-without-head-pointer/1

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
  // Function to delete a node without any reference to the head pointer.
  void deleteNode(Node *del_node)
  {
    if (del_node == NULL)
    {
      return;
    }
    Node *slow = del_node;
    Node *fast = del_node->next;
    while (fast->next != NULL)
    {
      slow->data = fast->data;
      fast = fast->next;
      slow = slow->next;
    }
    slow->data = fast->data;
    slow->next = NULL;
    delete fast;
  }
};