#include <bits/stdc++.h>
using namespace std;

// Problem : https://www.geeksforgeeks.org/problems/product-array-puzzle4525/1
// Solution in O(n^2) Time
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &arr)
    {
        // code here
        // O(n^2) Approach
        vector<int> output;
        for (int i = 0; i < arr.size(); i++)
        {
            int product = 1;
            for (int j = 0; j < arr.size(); j++)
            {
                if (i == j)
                {
                    continue;
                }
                product *= arr[j];
            }
            output.push_back(product);
        }
        return output;
    }
};

// Better Approach in O(n) Time
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &arr)
    {
        // code here
        // O(n) Approach
        int n = arr.size();
        vector<int> output;
        int zeroIndex = -1;
        int product = 1;
        for (int i = 0; i < n; i++)
        {
            if (!arr[i])
            {
                zeroIndex = i;
                continue;
            }
            product *= arr[i];
        }
        for (int i = 0; i < n; i++)
        {
            int data;
            if (zeroIndex != -1)
            {
                if (i == zeroIndex)
                {
                    int result = 1;
                    for (int j = 0; j < n; j++)
                    {
                        if (zeroIndex == j)
                        {
                            continue;
                        }
                        result *= arr[j];
                    }
                    data = result;
                }
                else
                {
                    data = 0;
                }
            }
            else
            {
                data = product / arr[i];
            }
            output.push_back(data);
        }
        return output;
    }
};

// Optimal Approach in O(n) Time
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &arr)
    {
        // code here
        // O(n) Approach
        int n = arr.size();
        vector<int> output(n, 0);
        int zeroIndex = -1;
        int product = 1;
        int totalZeros = 0;
        for (int i = 0; i < n; i++)
        {
            if (!arr[i])
            {
                zeroIndex = i;
                totalZeros++;
                continue;
            }
            product *= arr[i];
        }

        if (totalZeros > 1)
        {
            return output;
        }

        if (totalZeros > 0)
        {
            output[zeroIndex] = product;
            return output;
        }

        for (int i = 0; i < n; i++)
        {
            int data = product / arr[i];
            output[i] = data;
        }
        return output;
    }
};