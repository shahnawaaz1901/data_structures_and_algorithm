#include <bits/stdc++.h>
using namespace std;

// Problem : https://leetcode.com/problems/maximum-subarray/description/
// Problem : https://www.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1

// Greedy :-
class Solution
{
public:
    int maxSubarraySum(vector<int> &arr)
    {
        // Code here
        int sum = INT_MIN;
        for (int i = 0; i < arr.size(); i++)
        {
            int total = 0;
            for (int j = i; j < arr.size(); j++)
            {
                for (int k = i; k <= j; k++)
                {
                    total += arr[k];
                }
                if (total > sum)
                {
                    sum = total;
                }
                total = 0;
            }
        }
        return sum;
    }
};

// Better Approach
class Solution
{
public:
    int maxSubarraySum(vector<int> &arr)
    {
        // Code here
        int sum = INT_MIN;
        for (int i = 0; i < arr.size(); i++)
        {
            int total = 0;
            for (int j = i; j < arr.size(); j++)
            {
                if (total + arr[j] > sum)
                {
                    sum = total + arr[j];
                }
                total += arr[j];
            }
        }
        return sum;
    }
};

// Optimal Solution
class Solution
{
public:
    int maxSubarraySum(vector<int> &arr)
    {
        // Code here
        int maxSum = INT_MIN;
        int sum = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            sum += arr[i];
            if (sum > maxSum)
            {
                maxSum = sum;
            }

            if (sum < 0)
            {
                sum = 0;
            }
        }
        return maxSum;
    }
};