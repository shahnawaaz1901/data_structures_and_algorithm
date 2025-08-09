#include <bits/stdc++.h>
using namespace std;

// Problem : https://www.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1

// Bruteforce Approach with O(n^3) Time Complexity and O(1) Space Complexity
class Solution
{
public:
    bool hasTripletSum(vector<int> &arr, int target)
    {
        // Code Here
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    int sum = arr[i] + arr[j] + arr[k];
                    if (sum == target)
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

// Optimized Approach with O(n^2) Time Complexity and O(n) Space Complexity
class Solution
{
public:
    bool hasPairSum(vector<int> &arr, int startIndex, int target)
    {
        unordered_map<int, bool> data;
        for (int i = startIndex; i < arr.size(); i++)
        {
            if (data[target - arr[i]])
            {
                return true;
            }
            data[arr[i]] = true;
        }
        return false;
    }
    bool hasTripletSum(vector<int> &arr, int target)
    {
        // Code Here
        int n = arr.size();
        unordered_map<int, int> freq;
        for (int i = 0; i < n; i++)
        {
            int difference = target - arr[i];
            if (hasPairSum(arr, i + 1, difference))
            {
                return true;
            }
        }
        return false;
    }
};

// Optimal Approach with O(n^2) Time Complexity with O(1) Space Complexity
class Solution
{
public:
    bool hasTripletSum(vector<int> &arr, int target)
    {
        // Code Here
        sort(arr.begin(), arr.end());
        int n = arr.size() - 1;
        for (int i = 0; i <= n - 2; i++)
        {
            int left = i + 1;
            int right = n;
            while (left < right)
            {
                int sum = arr[left] + arr[right] + arr[i];
                if (sum == target)
                {
                    return true;
                }
                else if (sum > target)
                {
                    right--;
                }
                else
                {
                    left++;
                }
            }
        }
        return false;
    }
};