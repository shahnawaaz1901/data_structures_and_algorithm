#include <iostream>
#include <string>
using namespace std;

// Problem : https://www.geeksforgeeks.org/problems/palindrome-string0817/1
class Solution
{
public:
    // Function to check if a string is a palindrome.
    bool isPalindrome(string &s)
    {
        // code here
        int start = 0;
        int end = s.length() - 1;
        while (start < end)
        {
            if (s[start] != s[end])
            {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};