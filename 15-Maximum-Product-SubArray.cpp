#include <bits/stdc++.h>
using namespace std;

// Bruteforce Approach with O(n^3) Time Complexity and O(1) Space Complexity
class Solution
{
public:
    int maxProduct(vector<int> &arr)
    {
        // code here
        int maxProduct = INT_MIN;
        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = i; j < arr.size(); j++)
            {
                int maxP = 1;
                for (int k = i; k <= j; k++)
                {
                    maxP *= arr[k];
                }
                maxProduct = max(maxP, maxProduct);
            }
        }
        return maxProduct;
    }
};

// Optimized Approach with O(n^2) Time Complexity and O(1) Space Complexity
class Solution
{
public:
    int maxProduct(vector<int> &arr)
    {
        // code here
        int maxProduct = INT_MIN;
        for (int i = 0; i < arr.size(); i++)
        {
            int maxP = 1;
            for (int j = i; j < arr.size(); j++)
            {
                maxP *= arr[j];
                maxProduct = max(maxP, maxProduct);
            }
        }
        return maxProduct;
    }
};

// Optimal Approach 1 with O(n) Time Complexity and O(1) Space Complexity
int maxProduct(vector<int> &arr)
{
    // code here
    int maxProduct = arr[0];
    int minimum = arr[0];
    int maximum = arr[0];

    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] < 0)
        {
            swap(minimum, maximum);
        }

        maximum = max(arr[i], maximum * arr[i]);
        minimum = min(arr[i], minimum * arr[i]);
        maxProduct = max(maximum, max(minimum, maxProduct));
    }
    return maxProduct;
}

// Optimal Approach with O(n) Time Complexity and O(1) Space Complexity
class Solution
{
public:
    int maxProduct(vector<int> &arr)
    {
        // code here
        int maxProduct = INT_MIN;
        int prefixProduct = 1;
        int suffixProduct = 1;
        int n = arr.size() - 1;
        for (int i = 0; i <= n; i++)
        {
            if (prefixProduct == 0)
            {
                prefixProduct = 1;
            }

            if (suffixProduct == 0)
            {
                suffixProduct = 1;
            }

            prefixProduct *= arr[i];
            suffixProduct *= arr[n - i];
            maxProduct = max(maxProduct, max(prefixProduct, suffixProduct));
        }
        return maxProduct;
    }
};