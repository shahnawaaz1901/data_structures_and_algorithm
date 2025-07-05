#include <bits/stdc++.h>
using namespace std;

// Problem : https://www.geeksforgeeks.org/problems/find-minimum-and-maximum-element-in-an-array4428/1

class Solution
{
public:
    pair<int, int> getMinMax(vector<int> arr)
    {
        // code here
        pair<int, int> minMax;
        minMax.first = INT_MAX;
        minMax.second = INT_MIN;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] > minMax.second)
            {
                minMax.second = arr[i];
            }

            if (arr[i] < minMax.first)
            {
                minMax.first = arr[i];
            }
        }
        return minMax;
    }
};