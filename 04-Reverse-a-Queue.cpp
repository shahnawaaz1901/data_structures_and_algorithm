#include <bits/stdc++.h>
using namespace std;

// Problem : https://www.geeksforgeeks.org/problems/queue-reversal/1

// Approach 1 : In O(n) Time Complexity and O(n) Space Complexity using Recursion Stack
class Solution
{
public:
    queue<int> reverseQueue(queue<int> &q)
    {
        // code here.
        if (q.empty())
        {
            return q;
        }

        int x = q.front();
        q.pop();
        queue<int> output = reverseQueue(q);
        output.push(x);
        return output;
    }
};

// Approach 2 : In O(n) Time Complexity and O(n) Space Complexity using Stack
class Solution
{
public:
    queue<int> reverseQueue(queue<int> &q)
    {
        // code here.
        if (q.empty())
        {
            return q;
        }
        stack<int> values;
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            values.push(x);
        }

        queue<int> output;
        while (!values.empty())
        {
            output.push(values.top());
            values.pop();
        }
        return output;
    }
};

// Approach 3 : In O(n) Time Complexity and O(n) Space Complexity using Array
class Solution
{
public:
    queue<int> reverseQueue(queue<int> &q)
    {
        // code here.
        if (q.empty())
        {
            return q;
        }
        vector<int> values;
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            values.push_back(x);
        }

        queue<int> output;
        for (int i = values.size() - 1; i >= 0; i--)
        {
            output.push(values[i]);
        }

        return output;
    }
};