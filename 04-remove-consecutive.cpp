#include <iostream>
using namespace std;

// Problem : https://www.geeksforgeeks.org/problems/consecutive-elements2306/1

// Bruteforce Approach
class Solution
{
public:
    string removeConsecutiveCharacter(string &s)
    {
        // code here.
        if (s.length() == 0)
        {
            return "";
        }

        for (int i = 1; s[i] != '\0';)
        {
            if (s[i] == s[i - 1])
            {
                int j = i;
                while (s[j] != '\0')
                {
                    s[j - 1] = s[j];
                    j++;
                }
                s[j - 1] = '\0';
            }
            else
            {
                i++;
            }
        }
        return s;
    }
};

// Optimal Approach
class Solution
{
public:
    string removeConsecutiveCharacter(string &s)
    {
        // code here.
        if (s.length() == 0)
        {
            return "";
        }
        string output = "";
        output.push_back(s[0]);

        for (int i = 0; i < s.length(); i++)
        {
            if (output[output.length() - 1] == s[i])
            {
                continue;
            }
            output.push_back(s[i]);
        }
        return output;
    }
};