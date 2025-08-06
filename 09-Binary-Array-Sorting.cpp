#include <bits/stdc++.h>
using namespace std;

// Problem : https://www.geeksforgeeks.org/problems/binary-array-sorting-1587115620/0

// Bruteforce Approach in O(n) Time Complexity and O(1) Space Complexity
class Solution
{
public:
    void binSort(vector<int> &arr)
    {
        // code here
        int count1 = 0;
        int count0 = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i])
            {
                count1++;
            }
            else
            {
                count0++;
            }
        }

        int i = 0;
        while (count0--)
        {
            arr[i] = 0;
            i++;
        }

        while (count1--)
        {
            arr[i] = 1;
            i++;
        }
    }
};

// Optimal Approach in O(n) Time Complexity and O(1) Space Complexity
class Solution
{
public:
    void binSort(vector<int> &arr)
    {
        // code here
        int i = 0;
        int j = arr.size() - 1;
        while (i < j)
        {
            if (arr[i] == 0)
            {
                i++;
            }
            else if (arr[j] == 1)
            {
                j--;
            }
            else
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++;
                j--;
            }
        }
    }
};