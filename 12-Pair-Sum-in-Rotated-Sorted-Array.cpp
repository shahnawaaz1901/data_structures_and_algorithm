#include <bits/stdc++.h>
using namespace std;

// Problem : https://www.geeksforgeeks.org/problems/pair-sum-in-a-sorted-and-rotated-array/1

// Bruteforce Approach with O(n^2) Time Complexity and O(1) Space Complexity
class Solution
{
public:
    bool pairInSortedRotated(vector<int> &arr, int target)
    {
        // code here
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (arr[i] + arr[j] == target)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

// Better Approach with O(nlogn) Time Complexity and O(1) Space Complexity
class Solution
{
public:
    int searchInRotatedArray(vector<int> &arr, int key)
    {
        int i = 0;
        int j = arr.size() - 1;
        while (i <= j)
        {
            int mid = (i + j) / 2;
            if (arr[mid] == key)
            {
                return mid;
            }

            if (arr[i] == arr[mid] && arr[mid] == arr[j])
            {
                i++;
                j--;
                continue;
            }

            if (arr[i] <= arr[mid])
            {
                if (arr[i] <= key && arr[mid] > key)
                {
                    j = mid - 1;
                }
                else
                {
                    i = mid + 1;
                }
            }
            else
            {
                if (arr[j] >= key && arr[mid] < key)
                {
                    i = mid + 1;
                }
                else
                {
                    j = mid - 1;
                }
            }
        }
        return -1;
    }
    bool pairInSortedRotated(vector<int> &arr, int target)
    {
        // code here
        for (int i = 0; i < arr.size(); i++)
        {
            int dif = target - arr[i];
            int elementIndex = searchInRotatedArray(arr, dif);
            if (elementIndex != -1 && elementIndex != i)
            {
                return true;
            }
        }
        return false;
    }
};

// More Optimized Approach with O(n) Time Complexity and O(n) Space Complexity
class Solution
{
public:
    bool pairInSortedRotated(vector<int> &arr, int target)
    {
        // code here
        unordered_map<int, bool> data;
        for (int i = 0; i < arr.size(); i++)
        {
            int dif = target - arr[i];
            if (data[dif])
            {
                return true;
            }
            data[arr[i]] = true;
        }
        return false;
    }
};

// Optimal Approach with O(n) Time Complexity and O(1) Space Complexity
class Solution
{
public:
    bool pairInSortedRotated(vector<int> &arr, int target)
    {
        // code here
        int n = arr.size();
        int rotationIndex = 0;
        for (int i = 1; i < n; i++)
        {
            if (arr[i] < arr[i - 1])
            {
                rotationIndex = i;
            }
        }

        int i = rotationIndex;
        int j = rotationIndex - 1 >= 0 ? rotationIndex - 1 : arr.size() - 1;
        while (i != j)
        {
            int sum = arr[i] + arr[j];
            if (sum == target)
            {
                return true;
            }
            else if (sum > target)
            {
                j--;
                if (j < 0)
                {
                    j = arr.size() - 1;
                }
            }
            else
            {
                i++;
                if (i >= n)
                {
                    i = 0;
                }
            }
        }
        return false;
    }
};