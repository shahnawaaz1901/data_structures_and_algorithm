#include <bits/stdc++.h>
using namespace std;

// Problem : https://www.geeksforgeeks.org/problems/minimum-element-in-a-sorted-and-rotated-array3611/1
// Bruteforce Approach with O(nlogn) Time Complexity
class Solution
{
public:
    int findMin(vector<int> &arr)
    {
        // complete the function here
        sort(arr.begin(), arr.end());
        return arr[0];
    }
};

// Better Approach O(n) Time Complexity
class Solution
{
public:
    int findMin(vector<int> &arr)
    {
        // complete the function here
        int i = 0;
        int min = INT_MAX;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] < min)
            {
                min = arr[i];
            }
        }
        return min;
    }
};

// Optimal Approach in O(logn) Time Complexity
class Solution
{
public:
    int findMin(vector<int> &arr)
    {
        // complete the function here
        int low = 0;
        int high = arr.size() - 1;
        int min = INT_MAX;
        while (low <= high)
        {
            int mid = (high + low) / 2;
            if (arr[mid] < min)
            {
                min = arr[mid];
            }
            else if (arr[high] <= arr[mid])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return min;
    }
};