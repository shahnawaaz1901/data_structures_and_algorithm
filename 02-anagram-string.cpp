#include <iostream>
#include <vector>
using namespace std;

// https: // www.geeksforgeeks.org/problems/anagram-1587115620/1

// Brutforce Approach
class Solution
{
public:
    bool areAnagrams(string &s1, string &s2)
    {
        // code here
        if (s1.length() != s2.length())
        {
            return false;
        }
        for (int i = 0; i < s1.length(); i++)
        {
            bool isFound = false;
            for (int j = 0; j < s2.length(); j++)
            {
                if (s1[i] == s2[j])
                {
                    isFound = true;
                    s2[j] = '0';
                    break;
                }
            }
            if (!isFound)
            {
                return false;
            }
        }
        return true;
    }
};

// Better Approach
class Solution
{
public:
    bool areAnagrams(string &s1, string &s2)
    {
        // code here
        if (s1.length() != s2.length())
        {
            return false;
        }

        vector<int> frequency(256, 0);
        for (int i = 0; i < s1.size(); i++)
        {
            frequency[s1[i]]++;
        }

        for (int i = 0; i < s2.size(); i++)
        {
            frequency[s2[i]]--;
        }

        for (int i = 0; i < 256; i++)
        {
            if (frequency[i] != 0)
            {
                return false;
            }
        }
        return true;
    }
};

// Optimal Approach
class Solution
{
public:
    int getIndex(char a)
    {
        return (int)a - 97;
    }
    bool areAnagrams(string &s1, string &s2)
    {
        // code here
        if (s1.length() != s2.length())
        {
            return false;
        }

        vector<int> frequency(26, 0);
        for (int i = 0; i < s1.size(); i++)
        {
            frequency[getIndex(s1[i])]++;
        }

        for (int i = 0; i < s2.size(); i++)
        {
            frequency[getIndex(s2[i])]--;
        }

        for (int i = 0; i < 26; i++)
        {
            if (frequency[i] != 0)
            {
                return false;
            }
        }
        return true;
    }
};