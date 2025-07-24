#include <bits/stdc++.h>
using namespace std;

// Problem : https://www.geeksforgeeks.org/problems/insertion-sort/1

class Solution
{
public:
    void insertionSort(vector<int> &arr)
    {
        // code here
        for (int i = 0; i < arr.size() - 1; i++)
        {
            for (int j = i + 1; j >= 0; j--)
            {
                if (arr[j] < arr[j - 1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j - 1];
                    arr[j - 1] = temp;
                }
                else
                {
                    break;
                }
            }
        }
    }
};