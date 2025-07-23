#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// Problem : https://www.geeksforgeeks.org/problems/convert-a-sentence-into-its-equivalent-mobile-numeric-keypad-sequence0547/1

// Bruteforce Approach
string getKeyPressForChar(char a, string mappingArray[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int j = 0;
        string currentElement = mappingArray[i];
        while (currentElement[j] != '\0')
        {
            if (currentElement[j] == a)
            {
                string keyPress = "";
                for (int k = 0; k <= j; k++)
                {
                    keyPress += to_string(i);
                }
                return keyPress;
            }
            j++;
        }
    }
}

string printSequence(string S)
{
    // code here.
    string output = "";
    string mapping[10] = {" ", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};
    for (int i = 0; i < S.length(); i++)
    {
        string result = getKeyPressForChar(S[i], mapping, 10);
        output += result;
    }
    return output;
}
