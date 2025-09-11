#include <bits/stdc++.h>
using namespace std;

// Problem : https://www.geeksforgeeks.org/problems/delete-middle-element-of-a-stack/1

// Approach 1 in O(n) Time Complexity and O(n) Space Complexity using Recursion
class Solution
{
public:
    void deleteMid(stack<int> &s, int pos)
    {
        if (s.empty())
        {
            return;
        }

        if (pos == 1)
        {
            s.pop();
            return;
        }
        int val = s.top();
        s.pop();
        deleteMid(s, pos - 1);
        s.push(val);
    }

    void deleteMid(stack<int> &s)
    {
        // code here..
        deleteMid(s, (s.size() / 2) + 1);
    }
};

// Approach 2 in O(n) Time Complexity and O(n) Space Complexity using Vector
class Solution
{
public:
    // Function to delete middle element of a stack.

    void deleteMid(stack<int> &s)
    {
        // code here..
        int mid = (s.size() / 2) + 1;
        vector<int> values;
        int i = 1;
        while (i < mid)
        {
            values.push_back(s.top());
            s.pop();
            i++;
        }
        s.pop();

        for (int i = values.size() - 1; i >= 0; i--)
        {
            s.push(values[i]);
        }
    }
};