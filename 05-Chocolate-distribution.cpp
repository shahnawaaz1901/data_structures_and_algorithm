#include <bits/stdc++.h>
using namespace std;

// Problem : https://www.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1

// Optimal Approach Because of use Internal Sorting which takes O(nlogn)
class Solution
{
public:
    int findMinDiff(vector<int> &a, int m)
    {
        // code here
        sort(a.begin(), a.end());
        int minValue = INT_MAX;
        for (int i = 0; i < a.size(); i++)
        {
            if (i + m <= a.size())
            {
                if (a[i + m - 1] - a[i] < minValue)
                {
                    minValue = a[i + m - 1] - a[i];
                }
            }
        }
        return minValue;
    }
};