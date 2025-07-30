#include <bits/stdc++.h>
using namespace std;

// Problem : https://www.geeksforgeeks.org/problems/permutations-in-array1747/1
class Solution
{
public:
    bool isPossible(int k, vector<int> &arr1, vector<int> &arr2)
    {
        // Your code goes here
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());
        int i = 0, n = arr2.size() - 1;
        while (i < n)
        {
            int temp = arr2[i];
            arr2[i] = arr2[n];
            arr2[n] = temp;
            i++;
            n--;
        }

        for (int i = 0; i < arr1.size(); i++)
        {
            if (arr1[i] + arr2[i] < k)
            {
                return false;
            }
        }
        return true;
    }
};