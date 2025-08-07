#include <bits/stdc++.h>
using namespace std;

// Problem : https://www.geeksforgeeks.org/problems/buy-stock-2/0

// Bruteforce Approach O(n) Time Complexity
class Solution
{
public:
    int maximumProfit(vector<int> &prices)
    {
        // code here
        if (prices.empty())
        {
            return 0;
        }
        int buyPrice = prices[0];
        int buyDay = 0;
        int totalProfit = 0;
        int profit = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] < buyPrice)
            {
                buyPrice = prices[i];
                buyDay = i;
            }

            if (prices[i] - buyPrice > profit && i > buyDay)
            {
                profit = prices[i] - buyPrice;
                totalProfit = profit;
            }
        }
        return totalProfit;
    }
};

// Optimal Approach with O(n) Time Complexity and Less Variables
class Solution
{
public:
    int maximumProfit(vector<int> &prices)
    {
        // code here
        int bP = INT_MAX;
        int mP = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            if (prices[i] > bP)
            {
                int profit = prices[i] - bP;
                mP = max(mP, profit);
            }
            bP = min(bP, prices[i]);
        }
        return mP;
    }
};
