#include <bits/stdc++.h>
using namespace std;

// Problem : https://www.geeksforgeeks.org/problems/find-duplicates-in-an-array/0

// Bruteforce Approach with O(n^2) Time and O(1) Space Complexity
class Solution
{
public:
    vector<int> findDuplicates(vector<int> &arr)
    {
        vector<int> output;
        for (int i = 0; i < arr.size() - 1; i++)
        {
            for (int j = i + 1; j < arr.size(); j++)
            {
                if (arr[i] == arr[j])
                {
                    output.push_back(arr[i]);
                    break;
                }
            }
        }
        return output;
    }
};

// Better Approach in O(n) Time Complexity and O(n) Space Complexity
class Solution
{
public:
    vector<int> findDuplicates(vector<int> &arr)
    {
        vector<int> output;
        unordered_map<int, int> freq;
        for (int i = 0; i < arr.size(); i++)
        {
            if (freq[arr[i]])
            {
                output.push_back(arr[i]);
                continue;
            }
            freq[arr[i]]++;
        }
        return output;
    }
};

// Optimal Approach with O(n) Time Complexity and O(1) Space Complexity
class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {

        vector<int> result;
        for (int i = 0; i < nums.size(); ++i)
        {
            int index = abs(nums[i]) - 1;
            if (nums[index] < 0)
            {
                result.push_back(abs(nums[i]));
            }
            else
            {
                nums[index] = -nums[index];
            }
        }

        return result;
    }
};