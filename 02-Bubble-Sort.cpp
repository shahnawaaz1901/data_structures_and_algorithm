#include <bits/stdc++.h>
using namespace std;

// Problem : https://www.geeksforgeeks.org/problems/bubble-sort/1

class Solution
{
public:
    void bubbleSort(vector<int> &arr)
    {
        // code here
        for (int i = arr.size() - 1; i >= 0; i--)
        {
            for (int j = 1; j <= i; j++)
            {
                if (arr[j - 1] > arr[j])
                {
                    int temp = arr[j - 1];
                    arr[j - 1] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }
};