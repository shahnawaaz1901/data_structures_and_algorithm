#include <bits/stdc++.h>
using namespace std;

// Problem : https://www.geeksforgeeks.org/problems/expression-contains-redundant-bracket-or-not/1

// Approach 1 in O(n) Time Complexity and O(n) Space Complexity using Stack
class Solution
{
public:
    bool checkRedundancy(string &s)
    {
        // code here
        stack<char> characters;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != ')')
            {
                characters.push(s[i]);
            }
            else
            {
                int count = 0;
                while (characters.top() != '(')
                {
                    characters.pop();
                    count++;
                }

                if (count <= 1)
                {
                    return true;
                }
                characters.pop();
            }
        }
        return false;
    }
};

// Approach 2 in O(n) Time Complexity and O(n) Space Complexity using Vectors
class Solution
{
public:
    bool checkRedundancy(string &s)
    {
        // code here
        vector<char> characters;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != ')')
            {
                characters.push_back(s[i]);
            }
            else
            {
                int x = characters.size() - 1;
                int count = 0;
                while (characters[x] != '(')
                {
                    count++;
                    characters.pop_back();
                    x--;
                }
                characters.pop_back();
                if (count <= 1)
                {
                    return true;
                }
            }
        }
        return false;
    }
};