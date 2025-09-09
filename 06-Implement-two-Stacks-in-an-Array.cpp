#include <bits/stdc++.h>
using namespace std;

// Problem : https://www.geeksforgeeks.org/problems/implement-two-stacks-in-an-array/1

class twoStacks
{
public:
    vector<int> *data;
    int stack1Start;
    int stack2Start;
    int stack1End;
    int stack2End;
    int totalCapacity;
    int i;
    int j;

    twoStacks()
    {
        totalCapacity = 2;
        data = new vector<int>(totalCapacity);
        stack1Start = 0;
        stack2Start = totalCapacity / 2;
        stack1End = stack2Start - 1;
        stack2End = totalCapacity - 1;
        i = stack1Start;
        j = stack2Start;
    }

    void increaseSize()
    {
        int newSize = 2 * totalCapacity;
        vector<int> *newData = new vector<int>(newSize);
        for (int k = stack1Start, l = 0; k <= stack1End; k++, l++)
        {
            newData->at(l) = data->at(k);
        }

        for (int k = stack2Start, l = newSize / 2; k <= stack2End; k++, l++)
        {
            newData->at(l) = data->at(k);
        }
        this->j = (j - stack2Start) * 2;
        this->data = newData;
        this->totalCapacity = newSize;
        this->stack1End = (newSize / 2) - 1;
        this->stack2Start = (newSize / 2);
        this->stack2End = newSize - 1;
    }
    // Function to push an integer into the stack1.
    void push1(int x)
    {
        if (i > stack1End)
        {
            this->increaseSize();
        }
        // code here
        data->at(i) = x;
        i++;
    }

    // Function to push an integer into the stack2.
    void push2(int x)
    {
        // code here
        if (j > stack2End)
        {
            this->increaseSize();
        }
        data->at(j) = x;
        j++;
    }

    // Function to remove an element from top of the stack1.

    int pop1()
    {
        // code here
        if (i == 0)
        {
            return -1;
        }
        int val = data->at(i - 1);
        i--;
        return val;
    }

    // Function to remove an element from top of the stack2.
    int pop2()
    {
        // code here
        if (j == stack2Start)
        {
            return -1;
        }
        int val = data->at(j - 1);
        j--;
        return val;
    }
};