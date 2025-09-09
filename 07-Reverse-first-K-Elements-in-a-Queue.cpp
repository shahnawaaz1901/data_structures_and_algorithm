#include <bits/stdc++.h>
using namespace std;

// Problem : https://www.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1

// Bruteforce Approach 1 in O(n) Time Complexity and O(n) Space Complexity using Hashmap
class Solution
{
public:
    queue<int> reverseFirstK(queue<int> q, int k)
    {
        // code here
        if (q.empty() || k == 0 || q.size() < k)
        {
            return q;
        }

        int n = q.size();
        int x = k;
        unordered_map<int, int> valuesWithIndx;
        while (x > 0)
        {
            valuesWithIndx[x] = q.front();
            q.pop();
            x--;
        }

        x = k + 1;
        while (x <= n)
        {
            valuesWithIndx[x] = q.front();
            q.pop();
            x++;
        }

        for (int i = 1; i <= n; i++)
        {
            q.push(valuesWithIndx[i]);
        }
        return q;
    }
};

// Bruteforce Approach 2 in O(n) Time Complexity and O(n) Space Complexity using Arrays
class Solution
{
public:
    queue<int> reverseFirstK(queue<int> q, int k)
    {
        // code here
        if (q.empty() || k == 0)
        {
            return q;
        }

        if (q.size() < k)
        {
            return q;
        }

        vector<int> reverseElements;
        vector<int> remainingElements;
        while (k--)
        {
            reverseElements.push_back(q.front());
            q.pop();
        }

        while (q.size())
        {
            remainingElements.push_back(q.front());
            q.pop();
        }

        for (int i = reverseElements.size() - 1; i >= 0; i--)
        {
            q.push(reverseElements[i]);
        }

        for (int i = 0; i < remainingElements.size(); i++)
        {
            q.push(remainingElements[i]);
        }

        return q;
    }
};

// Optimal Approach in O(n) Time Complexity and O(k) Space Complexity using Hashmap
class Solution {
  public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        // code here
        if(q.empty() || k == 0 || q.size() < k){
            return q;
        }
        
        int n = q.size();
        int x = k;
        unordered_map<int, int> valuesWithIndx;
        while(x > 0){
            valuesWithIndx[x] = q.front();
            q.pop();
            x--;
        }
        
        for(int i = 1; i <= k;i++){
            q.push(valuesWithIndx[i]);
        }
        while(k < n){
            q.push(q.front());
            q.pop();
            k++;
        }
        return q;
    }
};