#include <iostream>
#include <stack>
using namespace std;

// https://www.geeksforgeeks.org/problems/parenthesis-checker2744/1
class Solution
{
public:
    bool isBalanced(string &k)
    {
        // code here
        stack<char> storeData;
        for (int i = 0; i < k.length(); i++)
        {
            if (k[i] == ')' || k[i] == '}' || k[i] == ']')
            {
                if (storeData.size() && k[i] == ')' && storeData.top() == '(')
                {
                    storeData.pop();
                }
                else if (storeData.size() && k[i] == ']' && storeData.top() == '[')
                {
                    storeData.pop();
                }
                else if (storeData.size() && k[i] == '}' && storeData.top() == '{')
                {
                    storeData.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                storeData.push(k[i]);
            }
        }

        return storeData.size() == 0 ? true : false;
    }
};