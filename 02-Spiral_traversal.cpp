#include <bits/stdc++.h>
using namespace std;

// Problem : https://leetcode.com/problems/spiral-matrix/description/
// Problem : https://www.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1
class Solution
{
public:
    vector<int> spirallyTraverse(vector<vector<int>> &mat)
    {
        // code here
        vector<int> output;
        int totalElements = mat.size() * mat[0].size();
        if (!totalElements)
        {
            return output;
        }
        int k = 0;
        int left = 0;
        int right = mat[0].size() - 1;
        int top = 0;
        int bottom = mat.size() - 1;
        while (k < totalElements)
        {
            for (int i = left; i <= right && k < totalElements; i++, k++)
            {
                output.push_back(mat[top][i]);
            }
            top++;
            for (int i = top; i <= bottom && k < totalElements; i++, k++)
            {
                output.push_back(mat[i][right]);
            };
            right--;
            for (int i = right; i >= left && k < totalElements; i--, k++)
            {
                output.push_back(mat[bottom][i]);
            }
            bottom--;
            for (int i = bottom; i >= top && k < totalElements; i--, k++)
            {
                output.push_back(mat[i][left]);
            }
            left++;
        }
        return output;
    }
};