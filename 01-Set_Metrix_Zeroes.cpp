#include <bits/stdc++.h>
using namespace std;
// Problem : https://leetcode.com/problems/set-matrix-zeroes/
// Problem : https://www.geeksforgeeks.org/problems/set-matrix-zeroes/1

// Bruteforce
class Solution
{
public:
    void setMatrixZeroes(vector<vector<int>> &mat)
    {
        // code here
        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[i].size(); j++)
            {
                if (mat[i][j] == 0)
                {
                    int k = j - 1;
                    while (k >= 0)
                    {
                        if (mat[i][k] != 0)
                        {
                            mat[i][k] = INT_MIN;
                        }
                        k--;
                    }
                    k = j + 1;
                    while (k < mat[i].size())
                    {
                        if (mat[i][k] != 0)
                        {
                            mat[i][k] = INT_MIN;
                        }
                        k++;
                    }
                    k = i - 1;
                    while (k >= 0)
                    {
                        if (mat[k][j] != 0)
                        {
                            mat[k][j] = INT_MIN;
                        }
                        k--;
                    }
                    k = i + 1;
                    while (k < mat.size())
                    {
                        if (mat[k][j] != 0)
                        {
                            mat[k][j] = INT_MIN;
                        }
                        k++;
                    }
                }
            }
        }

        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[i].size(); j++)
            {
                if (mat[i][j] == INT_MIN)
                {
                    mat[i][j] = 0;
                }
            }
        }
    }
};

// Better Approach
class Solution
{
public:
    void setMatrixZeroes(vector<vector<int>> &mat)
    {
        // code here
        if (!mat.size())
        {
            return;
        }
        vector<int> row(mat.size(), 0);
        vector<int> col(mat[0].size(), 0);
        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[i].size(); j++)
            {
                if (mat[i][j] == 0)
                {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[i].size(); j++)
            {
                if (row[i] || col[j])
                {
                    mat[i][j] = 0;
                }
            }
        }
    }
};

// Optimal Approach
class Solution
{
public:
    void setMatrixZeroes(vector<vector<int>> &mat)
    {
        // code here
        int m = mat.size();
        int n = mat[0].size();
        bool firstRow = false;
        bool firstCol = false;
        for (int i = 0; i < m; i++)
        {
            if (!mat[i][0])
            {
                firstCol = true;
            }
        }

        for (int j = 0; j < n; j++)
        {
            if (!mat[0][j])
            {
                firstRow = true;
            }
        }

        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[i].size(); j++)
            {
                if (!mat[i][j])
                {
                    mat[i][0] = 0;
                    mat[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < mat.size(); i++)
        {
            for (int j = 1; j < mat[i].size(); j++)
            {
                if (!mat[i][0] || !mat[0][j])
                {
                    mat[i][j] = 0;
                }
            }
        }

        if (firstCol)
        {
            for (int i = 0; i < m; i++)
            {
                mat[i][0] = 0;
            }
        }

        if (firstRow)
        {
            for (int j = 0; j < n; j++)
            {
                mat[0][j] = 0;
            }
        }
    }
};