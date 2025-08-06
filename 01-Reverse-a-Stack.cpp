#include <bits/stdc++.h>
using namespace std;

// Problem : https://www.geeksforgeeks.org/problems/reverse-a-stack/0

// Bruteforce Approach with O(n^2) Time Complexity and O(n^2) Space Complexity
class Solution
{
public:
    void insertAtBottom(int x, stack<int> &St)
    {
        if (St.empty())
        {
            St.push(x);
            return;
        }
        int data = St.top();
        St.pop();
        insertAtBottom(x, St);
        St.push(data);
    }
    void reverse(stack<int> &St)
    {
        // code here
        if (!St.size())
        {
            return;
        }

        int topData = St.top();
        St.pop();
        reverse(St);
        insertAtBottom(topData, St);
    }
};

// Optimal Approach with O(n) Time Complexity and O(n) Space Complexity

class Solution
{
public:
    void reverse(stack<int> &St)
    {
        // code here
        if (!St.size())
        {
            return;
        }

        stack<int> firstStack;
        stack<int> secondStack;
        while (St.size())
        {
            firstStack.push(St.top());
            St.pop();
        }

        while (firstStack.size())
        {
            secondStack.push(firstStack.top());
            firstStack.pop();
        }

        while (secondStack.size())
        {
            St.push(secondStack.top());
            secondStack.pop();
        }
    }
};