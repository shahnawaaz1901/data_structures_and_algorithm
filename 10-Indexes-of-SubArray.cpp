#include <bits/stdc++.h>
using namespace std;

// Problem : https://www.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/0
class Solution
{
public:
    vector<int> subarraySum(vector<int> &arr, int target)
    {
        // code here

        vector<int> output;
        int sum = 0;
        int startIndex = 0;
        for (int i = 0; i < arr.size() && startIndex < arr.size();)
        {
            if (target < sum)
            {
                sum -= arr[startIndex];
                startIndex++;
            }
            else
            {
                sum += arr[i];
                i++;
            }
            if (sum == target)
            {
                output.push_back(startIndex + 1);
                output.push_back(i);
                break;
            }
        }
        while (sum >= target && startIndex < arr.size() && !output.size())
        {
            sum -= arr[startIndex];
            startIndex++;
            if (sum == target)
            {
                output.push_back(startIndex + 1);
                output.push_back(arr.size());
                break;
            }
        }
        if (!output.size())
        {
            output.push_back(-1);
        }
        return output;
    }
};