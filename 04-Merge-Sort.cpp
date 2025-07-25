#include <bits/stdc++.h>
using namespace std;

// Problem : https://www.geeksforgeeks.org/problems/merge-sort/1

class Solution
{
public:
    void merge(vector<int> &arr, int l, int r)
    {
        if (l > r)
        {
            return;
        }

        int i = l;
        int mid = (l + r) / 2;
        int j = mid + 1;
        vector<int> sortedElements;
        while (i <= mid && j <= r)
        {
            if (arr[i] < arr[j])
            {
                sortedElements.push_back(arr[i]);
                i++;
            }
            else
            {
                sortedElements.push_back(arr[j]);
                j++;
            }
        }

        while (i <= mid)
        {
            sortedElements.push_back(arr[i]);
            i++;
        }
        while (j <= r)
        {
            sortedElements.push_back(arr[j]);
            j++;
        }

        for (int i = 0; i < sortedElements.size(); i++)
        {
            arr[i + l] = sortedElements[i];
        }
    }
    void mergeSort(vector<int> &arr, int l, int r)
    {
        // code here
        if (l >= r)
        {
            return;
        }

        int mid = (l + r) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);

        merge(arr, l, r);
    }
};