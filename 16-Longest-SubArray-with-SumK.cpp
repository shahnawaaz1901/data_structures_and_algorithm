#include <bits/stdc++.h>
using namespace std;

// Bruteforce Approach with O(n^3) Time Complexity and O(1) Space Complexity
class Solution
{
public:
    int longestSubarray(vector<int> &arr, int x)
    {
        // code here
        int maxLength = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                int sum = 0;
                for (int k = i; k <= j; k++)
                {
                    sum += arr[k];
                    if (sum == x)
                    {
                        maxLength = max(k - i + 1, maxLength);
                    }
                }
            }
        }
        return maxLength;
    }
};

// Optimized Approach with O(n^2) Time Complexity and O(1) Space Complexity
class Solution
{
public:
    int longestSubarray(vector<int> &arr, int x)
    {
        // code here
        int maxLength = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            int length = 0;
            for (int j = i; j < n; j++)
            {
                sum += arr[j];
                length++;
                if (sum == x)
                {
                    maxLength = max(maxLength, length);
                }
            }
        }
        return maxLength;
    }
};

// Optimized Solution with O(n) Time Complexity and O(n) Space Complexity
class Solution
{
public:
    int longestSubarray(vector<int> &arr, int x)
    {
        // code here
        int maxLength = 0;
        int n = arr.size();
        unordered_map<long long, int> sumWithIndexes;
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            if (sum == x)
            {
                maxLength = max(i + 1, maxLength);
            }
            int rem = sum - x;
            if (sumWithIndexes.find(rem) != sumWithIndexes.end())
            {
                maxLength = max(maxLength, i - sumWithIndexes[rem]);
            }
            if (sumWithIndexes.find(sum) == sumWithIndexes.end())
            {
                sumWithIndexes[sum] = i;
            }
        }
        return maxLength;
    }
};