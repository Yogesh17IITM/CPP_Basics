/*
    Topic: Find first unique character in a given strings

    Input1 : "Hello World"
    Input2 : " How are you?"

    Assumptions:
    - Assuming case-insensitive
    - only letters are considered (ignore numbers/symbols)

    Output: d
    Explanation:
        Unique characters are: d, a, y, u
        First Uniq Charac: d
*/

#include <iostream>
#include <map>
#include <vector>
using namespace std;

char FirstUniqChar(string str1, string str2)
{
    string str = str1 + str2;

    // 1. Convert all characters to lower-case
    for (auto &iCh : str) // O(str.length())
        iCh = ::tolower(iCh);

    // 2. Convert map b/w character and its count
    map<char, int> mCharCount;

    // Initialize map
    for (auto &iCh : str) // O(str.length())
    {
        // consider only letters (ignore numbers or symbols etc)
        if (::isalpha(iCh))
            mCharCount[iCh] = 0;
    }

    // 3. Increment Counter for each letter
    for (auto &iCh : str) // O(str.length())
    {
        if (::isalpha(iCh))
            mCharCount[iCh] += 1;
    }

    // 4. Find the first uniq character (if the count == 1, then it is unique)
    char oFirstUniqChar;
    for (auto &iCh : str) // O(str.length())
    {
        if (::isalpha(iCh) && (1 == mCharCount[iCh]))
        {
            oFirstUniqChar = iCh;
            break; // Break the loop once found.
        }
    }

    return oFirstUniqChar;
}

int main()
{
    string str1 = "Hello World";
    string str2 = " How are you?";

    cout << FirstUniqChar(str1, str2) << endl;

    return 0;
}