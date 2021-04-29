/*
    Topic: Find first unique character in a given strings

    Input1 : "Hello World"
    Input2 : " How are you?"
    Todo: Concatenate two strings and find the first non-repeating char
    
    Output: d
*/

#include<iostream>
#include<map>
#include<vector>
using namespace std;

char FirstUniqChar(string str1, string str2)
{
    vector<char> chArr;

    // Lambda Expression for push into vector
    auto PushInto = [&](string iStr)
    {
        for (auto& iCh : iStr)
        {
            // convert all char into either upper or lower case
            iCh = ::tolower(iCh);
            chArr.push_back(iCh);
        }
    };

    PushInto(str1);
    PushInto(str2);

    // Use map to count the repetition of a char
    map<char, int> chMap;       // Elements stored are sorted by default.
    for (auto& iCh : chArr)
        chMap[iCh]++;

    // Store only unique Char
    vector<char> UniqChar;
    for (auto& iChMap : chMap)
        if (1 == iChMap.second)
            UniqChar.push_back(iChMap.first);

    // Find the first uniq char from the given string
    char FirstUniqChar = ' ';
    for (auto& iCh : chArr)
    {
        auto pos = find(UniqChar.begin(), UniqChar.end(), iCh);
        if (pos != UniqChar.end())
        {
            FirstUniqChar = iCh;
            break;
        }
    }
    return FirstUniqChar;
}

int main()
{
    string str1 = "Hello World";
    string str2 = " How are you?";

    cout << FirstUniqChar(str1, str2) << endl;

	return 0;
}