#include <bits/stdc++.h>
using namespace std;

// Problem : https://www.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1

// Bruteforce Approach with O(m+n) Time Complexity and O(m+n) Space Complexity
class Solution
{
public:
    void mergeArrays(vector<int> &a, vector<int> &b)
    {
        // code here
        vector<int> output;

        int i = 0;
        int j = 0;
        while (i < a.size() && j < b.size())
        {
            if (a[i] < b[j])
            {
                output.push_back(a[i]);
                i++;
            }
            else
            {
                output.push_back(b[j]);
                j++;
            }
        }

        while (i < a.size())
        {
            output.push_back(a[i]);
            i++;
        }

        while (j < b.size())
        {
            output.push_back(b[j]);
            j++;
        }

        i = 0;
        for (int k = 0; k < a.size(); k++, i++)
        {
            a[k] = output[i];
        }

        for (int l = 0; l < b.size(); i++, l++)
        {
            b[l] = output[i];
        }
    }
};