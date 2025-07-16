#include <iostream>
#include <vector>
using namespace std;

// Problem : https://www.geeksforgeeks.org/problems/search-in-a-rotated-array4618/1

// Bruteforce Approach
class Solution
{
public:
    int search(vector<int> &arr, int key)
    {
        // Code Here
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == key)
            {
                return i;
            }
        }
        return -1;
    }
};

// Better Approach
class Solution
{
public:
    int search(vector<int> &arr, int key)
    {
        // Code Here
        int low = 0;
        int high = arr.size() - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (arr[mid] == key)
            {
                return mid;
            }

            if (arr[low] <= arr[mid])
            {
                if (arr[low] <= key && arr[mid] > key)
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            else
            {
                if (arr[high] >= key && arr[mid] < key)
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};