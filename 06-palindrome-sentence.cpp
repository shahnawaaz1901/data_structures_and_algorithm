#include <bits/stdc++.h>
using namespace std;

// Problem : https://www.geeksforgeeks.org/problems/string-palindromic-ignoring-spaces4723/0

// Bruteforce Approach with O(n) Time Complexity and O(1) Space Complexity
class Solution
{
public:
    char lowerCase(char s)
    {
        int x = s;
        if (x >= 65 && x <= 90)
        {
            return x + 32;
        }
        return x;
    }
    bool isPalinSent(string &s)
    {
        // code here
        if (s.empty())
        {
            return true;
        }
        int i = 0;
        int j = s.size() - 1;
        while (i <= j)
        {
            int front = s[i];
            int back = s[j];
            if ((front < 97 || front > 122) &&
                (front < 65 || front > 90) &&
                (front < 48 || front > 57))
            {
                i++;
            }
            else if (
                (back < 97 || back > 122) &&
                (back < 65 || back > 90) &&
                (back < 48 || back > 57))
            {
                j--;
            }
            else if (lowerCase(s[i]) != lowerCase(s[j]))
            {
                return false;
            }
            else
            {
                i++;
                j--;
            }
        }
        return true;
    }
};