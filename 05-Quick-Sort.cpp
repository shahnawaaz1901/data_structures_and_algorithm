#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void swap(vector<int> &arr, int i, int j)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    void quickSort(vector<int> &arr, int start, int end)
    {
        // code here
        if (start >= end)
        {
            return;
        }
        int pivotIndex = partition(arr, start, end);
        quickSort(arr, start, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, end);
    }

public:
    int partition(vector<int> &arr, int start, int end)
    {
        int count = 0;
        int selectedElement = arr[start];
        for (int i = start + 1; i <= end; i++)
        {
            if (arr[i] <= selectedElement)
            {
                count++;
            }
        }
        int pivotIndex = start + count;
        swap(arr, start, start + count);
        int i = start;
        int j = end;
        while (i < pivotIndex && j > pivotIndex)
        {
            if (arr[i] <= arr[pivotIndex])
            {
                i++;
            }
            else if (arr[j] > arr[pivotIndex])
            {
                j--;
            }
            else
            {
                swap(arr, i, j);
                i++;
                j--;
            }
        }
        return pivotIndex;
    }
};