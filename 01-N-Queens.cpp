#include <bits/stdc++.h>
using namespace std;

// Problem : https://www.geeksforgeeks.org/problems/n-queen-problem0315/0

// One Solution with O(n!) Time Complexity and O(n^2) Space Complexity
class Solution
{
public:
    bool validPath(vector<vector<int>> &chessBoard, int i, int j, int n)
    {
        if (i < 0 || i >= n || j < 0 || j >= n)
        {
            return false;
        }

        // CheckRow
        for (int x = i - 1; x >= 0; x--)
        {
            if (chessBoard[x][j])
            {
                return false;
            }
        }

        // CheckColumn
        for (int y = j - 1; y >= 0; y--)
        {
            if (chessBoard[i][y])
            {
                return false;
            }
        }

        // Check Left Diagonal
        for (int x = i - 1, y = j - 1; x >= 0 && y >= 0; x--, y--)
        {
            if (chessBoard[x][y])
            {
                return false;
            }
        }

        // Check Right Diagonal
        for (int x = i - 1, y = j + 1; x >= 0 && y < n; x--, y++)
        {
            if (chessBoard[x][y])
            {
                return false;
            }
        }

        return true;
    }

    void solveNQueens(vector<vector<int>> &output, vector<vector<int>> &chessBoard, int i, int n)
    {
        if (i == n)
        {
            vector<int> ways;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (chessBoard[i][j])
                    {
                        ways.push_back(j + 1);
                        break;
                    }
                }
            }
            output.push_back(ways);
            return;
        }

        for (int j = 0; j < n; j++)
        {
            chessBoard[i][j] = 1;
            if (validPath(chessBoard, i, j, n))
            {
                solveNQueens(output, chessBoard, i + 1, n);
            }
            chessBoard[i][j] = 0;
        }
    }

    vector<vector<int>> nQueen(int n)
    {
        // code here
        vector<vector<int>> output;
        vector<vector<int>> chessBoard(n, vector<int>(n, 0));
        solveNQueens(output, chessBoard, 0, n);
        return output;
    }
};