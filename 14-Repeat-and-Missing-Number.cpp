#include <bits/stdc++.h>
using namespace std;

// Problem : https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1
// Bruteforce Approach with O(n^2) Time Complexity and O(1) Space Complexity
class Solution
{
public:
    vector<int> findTwoElement(vector<int> &arr)
    {
        // code here
        vector<int> output;
        int n = arr.size();
        // Find Repeating Number
        for (int i = 0; i < n; i++)
        {
            bool isRepeatElementFound = false;
            for (int j = i + 1; j < n; j++)
            {
                if (arr[i] == arr[j])
                {
                    output.push_back(arr[i]);
                    break;
                }
            }
            if (isRepeatElementFound)
            {
                break;
            }
        }

        // Find Missing Number
        for (int i = 0; i < n; i++)
        {
            int num = i + 1;
            bool isFound = false;
            for (int j = 0; j < n; j++)
            {
                if (arr[j] == num)
                {
                    isFound = true;
                    break;
                }
            }
            if (!isFound)
            {
                output.push_back(num);
                break;
            }
        }
        return output;
    }
};

// Optimized Approach with O(n) Time Complexity and O(n) Space Complexity
class Solution
{
public:
    vector<int> findTwoElement(vector<int> &arr)
    {
        // code here
        vector<int> output(2);
        unordered_map<int, int> freqCount;
        int n = arr.size();
        // Find Repeating Number
        for (int i = 0; i < n; i++)
        {
            if (freqCount[arr[i]])
            {
                output[0] = arr[i];
            }
            freqCount[arr[i]]++;
        }

        // Find Missing Number
        for (int i = 1; i <= n; i++)
        {
            if (!freqCount[i])
            {
                output[1] = i;
            }
        }
        return output;
    }
};

// Optimal Approach with O(n) Time Complexity and O(1) Space Complexity
class Solution
{
public:
    vector<int> findTwoElement(vector<int> &arr)
    {
        // code here
        vector<int> output(2);
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            int index = abs(arr[i]) - 1;
            if (arr[index] < 0)
            {
                output[0] = index + 1;
                continue;
            }
            arr[index] = -arr[index];
        }

        for (int i = 0; i < n; i++)
        {
            if (arr[i] > 0)
            {
                output[1] = i + 1;
            }
        }
        return output;
    }
};