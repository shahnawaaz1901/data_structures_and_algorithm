#include <bits/stdc++.h>
using namespace std;

// Problem : https://www.geeksforgeeks.org/problems/search-in-a-matrix-1587115621/1

// Brutefoce Approach O(n^2)
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &mat, int x)
    {
        // code here
        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[i].size(); j++)
            {
                if (mat[i][j] == x)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

// Optimal Approach O(log(n*m))
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &mat, int x)
    {
        // code here
        int rowLow = 0;
        int rowHigh = mat.size() - 1;
        int colLow = 0;
        int colHigh = mat[0].size() - 1;
        int rowMid = 0;
        int colMid = 0;
        while (rowLow <= rowHigh)
        {
            rowMid = (rowLow + rowHigh) / 2;
            int colMidStored = (colLow + colHigh) / 2;
            while (colLow <= colHigh)
            {
                colMid = (colLow + colHigh) / 2;
                if (mat[rowMid][colMid] == x)
                {
                    return true;
                }
                else if (mat[rowMid][colMid] > x)
                {
                    colHigh = colMid - 1;
                }
                else
                {
                    colLow = colMid + 1;
                }
            }

            if (mat[rowMid][colMidStored] > x)
            {
                rowHigh = rowMid - 1;
            }
            else
            {
                rowLow = rowMid + 1;
            }
            colLow = 0;
            colHigh = mat[0].size() - 1;
        }
        return false;
    }
};