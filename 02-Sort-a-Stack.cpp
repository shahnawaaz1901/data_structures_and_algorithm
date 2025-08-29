#include <bits/stdc++.h>
using namespace std;

// Problem : https://www.geeksforgeeks.org/problems/sort-a-stack/1
/* The structure of the class is */
class SortedStack
{
public:
    stack<int> s;
    void sort();
};

// Bruteforce Approach with O(n^2) Time Complexity and O(n) Space Complexity
void SortedStack ::sort()
{
    // Your code here
    if (s.empty())
    {
        return;
    }
    int data = s.top();
    s.pop();
    sort();
    vector<int> val;
    while (!s.empty() && s.top() > data)
    {
        val.push_back(s.top());
        s.pop();
    }
    s.push(data);
    for (int i = val.size() - 1; i >= 0; i--)
    {
        s.push(val[i]);
    }
}

// Better Approach with O(n^2) Time Complexity and O(n) Space Complexity
void insertAtRightPlace(stack<int> &s, int x)
{
    if (s.empty() || s.top() < x)
    {
        s.push(x);
        return;
    }

    int data = s.top();
    s.pop();
    insertAtRightPlace(s, x);
    s.push(data);
}

void SortedStack ::sort()
{
    // Your code here
    if (s.empty())
    {
        return;
    }
    int data = s.top();
    s.pop();
    sort();
    insertAtRightPlace(s, data);
}