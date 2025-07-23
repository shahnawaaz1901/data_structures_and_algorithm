#include <bits/stdc++.h>
using namespace std;

// Problem : https://leetcode.com/problems/set-matrix-zeroes/description/
// Problem : https://www.geeksforgeeks.org/problems/rotate-by-90-degree-1587115621/1

// Bruteforce
class Solution
{
public:
    void rotateMatrix(vector<vector<int>> &mat)
    {
        // code here
        int n = mat.size();
        vector<vector<int>> output(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = n - 1, k = 0; j >= 0; j--, k++)
            {
                output[k][i] = mat[i][j];
            }
        }

        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[i].size(); j++)
            {
                mat[i][j] = output[i][j];
            }
        }
    }
};

// Optimal Approach
class Solution
{
public:
    void rotateMatrix(vector<vector<int>> &mat)
    {
        // code here
        int n = mat.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                int temp = mat[i][j];
                mat[i][j] = mat[j][i];
                mat[j][i] = temp;
            }
        }

        for (int top = 0, bottom = n - 1; top < bottom; top++, bottom--)
        {
            for (int j = 0; j < n; j++)
            {
                int temp = mat[top][j];
                mat[top][j] = mat[bottom][j];
                mat[bottom][j] = temp;
            }
        }
    }
};