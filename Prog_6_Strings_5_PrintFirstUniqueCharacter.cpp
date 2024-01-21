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
using namespace std;

char FirstUniqChar(const string &str)
{
    map<char, int> mCh;

    // 1. Find the char, convert into lower case and maintain a count
    for (auto &ich : str) // O(str.length())
    {
        if (::isalpha(ich))
            mCh[::tolower(ich)] += 1;
    }

    // Iterate over char in string and check if the count is 1
    char uniqChar;
    for (auto &ich : str)
    {
        if ((::isalpha(ich)) && (mCh[::tolower(ich)] == 1))
        {
            uniqChar = ich;
            break; // break it once found
        }
    }

    return uniqChar;
}

int main()
{
    string str1 = "Hello World";
    string str2 = " How are you?";

    cout << FirstUniqChar((str1 + str2)) << endl;

    return 0;
}