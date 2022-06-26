/*
Objective:
    Sort string lexicographically

Problem:
    There are list of string sets (in lower case) available with an
    identifier (alpha-numeric) at the beginning of the each string sets.
    You have to sort the string sets lexicographically.

Sample Input:
    { "gb1 pillow bed fan towel",
      "ah2 goat cow tiger lion",
      "h34 44 67 34 56",
      "m13 23 23 34 46",
      "z24 pillow bed fan car",
      "yr1 love friend enemy brother"}

Sample Output:
    {"gh2 goat cow tiger lion",
     "yr1 love friend enemy brother",
     "z24 pillow bed fan car",
     "ab1 pillow bed fan towel",
     "m13 23 23 34 46",
     "h34 44 67 34 56"}

Explanation:
    String are sorted out lexicographically (alphabetical order).
    [G]oat < [L]ove < [P]illow ([C]ar) < [P]illow ([T]owel)<  [2]3 < [4]4
    Numerics should be kept at the last in the ascending order.
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

bool Compare(pair<string, string> &keyVal_A, pair<string, string> &keyVal_B)
{
    bool oRet = false;

    // Extract the 'Value'
    string &strA = keyVal_A.second;
    string &strB = keyVal_B.second;

    // If one of the value contains digit (NOT BOTH)
    if ((isdigit(strA[1]) && isalpha(strB[1])) ||
        (isdigit(strB[1]) && isalpha(strA[1])))
    {
        oRet = (strA.compare(strB) > 0) ? true : false; // Keep the numbers with low priority compared to string
    }
    else
    {
        int x = strA.compare(strB);
        if (x != 0)
        {
            oRet = (x < 0) ? true : false;
        }
        else
            oRet = true;
    }

    return oRet;
}

vector<string> SortStringLexicographically(vector<string> iListOfStrings)
{
    vector<string> oSortedStr;

    vector<pair<string, string>> KeyVal;

    // 1) Separate out key and value
    // 2) Sort string lexi. acc. to value
    // 3) Pair Key with value
    for (auto &iStrLine : iListOfStrings)
    {
        string word;
        stringstream sstream(iStrLine);
        while (getline(sstream, word, ' '))
        {
            KeyVal.push_back(make_pair(word, iStrLine.substr(word.length())));
            break;
        }
    }

    sort(KeyVal.begin(), KeyVal.end(), Compare);

    for (auto &iKeyVal : KeyVal)
    {
        string str = iKeyVal.first + iKeyVal.second;
        oSortedStr.push_back(str);
    }

    return oSortedStr;
}

int main()
{
    vector<string> iStr = {"gb1 pillow bed fan towel",
                           "ah2 goat cow tiger lion",
                           "h34 44 67 34 56",
                           "m13 23 23 34 46",
                           "z24 pillow bed fan car",
                           "yr1 love friend enemy brother"};

    vector<string> SortedStr = SortStringLexicographically(iStr);
    for (auto &iStrLine : SortedStr)
        cout << iStrLine << endl;

    return 0;
}