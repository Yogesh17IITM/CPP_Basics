/*
Objective:
    1) To demonstrate how to use bitwise operator for calc. permutations

Example:
    Print all the subsequence of a given string. Eg., abc

    Subsequences are:
        a
        ab
        abc
        ac
        b
        bc
        c

Key Topics:
    1) AND operator
    2) Left-shifting
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> PrintAllSubsequences(const string &iStr)
{
    vector<string> oStr;

    int nPermutations = 1 << iStr.length();

    for (int iPerm = 0; iPerm < nPermutations; iPerm++)
    {
        string subStr = "";
        for (int idx = 0; idx < iStr.length(); idx++)
        {
            if (iPerm & (1 << idx))
                subStr += iStr[idx];
        }

        if (0 < subStr.length())
            oStr.push_back(subStr);
    }

    sort(oStr.begin(), oStr.end());
    return oStr;
}

int main()
{
    string str = "abc";
    vector<string> strSubsequences = PrintAllSubsequences(str);
    for (auto &it : strSubsequences)
        cout << it << endl;
    return 0;
}