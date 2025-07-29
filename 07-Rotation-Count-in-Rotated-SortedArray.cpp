#include <bits/stdc++.h>
using namespace std;

// Problem : https://www.geeksforgeeks.org/problems/rotation4723/1
// Bruteforce Approach O(n) Time Complexity
class Solution
{
public:
    int findKRotation(vector<int> &arr)
    {
        // Code Here
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] < arr[i - 1])
            {
                return i;
            }
        }
        return 0;
    }
};

// Optimal Approach O(logn) Time Complexity
class Solution
{
public:
    int findKRotation(vector<int> &arr)
    {
        // Code Here
        int i = 0;
        int j = arr.size() - 1;
        int min = INT_MAX;
        int minIndex = -1;
        while (i <= j)
        {
            int mid = (i + j) / 2;
            if (arr[mid] < min)
            {
                minIndex = mid;
                min = arr[mid];
            }
            if (arr[mid] <= arr[j])
            {
                j = mid - 1;
            }
            else
            {
                i = mid + 1;
            }
        }
        return minIndex;
    }
};