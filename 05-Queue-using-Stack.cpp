#include <bits/stdc++.h>
using namespace std;

// Problem : https://www.geeksforgeeks.org/problems/queue-using-stack/1

// Approach with O(1) Time Complexity and O(1) Space Complexity for Push and O(n) Time Complexity and O(1) Space Complexity for Pop
class Queue
{
    stack<int> input, output;

public:
    void enqueue(int x)
    {
        // code here
        input.push(x);
    }

    int dequeue()
    {
        // code here
        while (!input.empty())
        {
            output.push(input.top());
            input.pop();
        }

        int x = output.top();
        output.pop();
        while (!output.empty())
        {
            input.push(output.top());
            output.pop();
        }
        return x;
    }
};