#include <bits/stdc++.h>
using namespace std;

// Problem : https://leetcode.com/problems/contains-duplicate/
// Problem : https://www.geeksforgeeks.org/problems/check-if-array-contains-duplicates/1

// Greedy
class Solution
{
public:
    bool checkDuplicates(vector<int> &arr)
    {
        // code here
        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = i + 1; j < arr.size(); j++)
            {
                if (arr[j] == arr[i])
                {
                    return true;
                }
            }
        }
        return false;
    }
};

// Better Approach
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); i++)
        {
            freq[nums[i]]++;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (freq[nums[i]] > 1)
            {
                return true;
            }
        }
        return false;
    }
};

// Optimal Approach
class Solution
{
public:
    bool checkDuplicates(vector<int> &arr)
    {
        // code here
        unordered_map<int, int> storedValues;
        for (int i = 0; i < arr.size(); i++)
        {
            if (storedValues[arr[i]])
            {
                return true;
            }
            storedValues[arr[i]]++;
        }
        return false;
    }
};
