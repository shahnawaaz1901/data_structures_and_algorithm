#include <bits/stdc++.h>
using namespace std;

// Problem : https://www.geeksforgeeks.org/problems/stack-using-two-queues/1

// Single Approach with O(n) Time Complexity for Push O(1) Time Complexity for Pop and O(1) Space Complexity for both Push & Pop
class QueueStack
{
private:
    queue<int> q1;
    queue<int> q2;

public:
    void push(int);
    int pop();
};

void QueueStack ::push(int x)
{
    // code here
    q2.push(x);
    while (!q1.empty())
    {
        q2.push(q1.front());
        q1.pop();
    }

    queue<int> temp = q1;
    q1 = q2;
    q2 = temp;
}

int QueueStack ::pop()
{
    if (q1.empty())
    {
        return -1;
    }
    int data = q1.front();
    q1.pop();
    return data;
}