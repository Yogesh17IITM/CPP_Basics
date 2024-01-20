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

    int nPermutations = 1 << iStr.length(); // which is 2 power of iStr.length().
    // if string length is 3, then 2^(3) - 1 =  7 subsequences can be formed

    // using '1' and '0', with different positions we can form different numbers/values.
    // For example, let us consider value from 1 to 7

    // write down the value, its equivalent bit expressions and mapping 1's with string characters
    // 1(a)    0001     _ _ _ a  ---> Read from reverse
    // 2(b)    0010     _ _ b _
    // 3(ab)   0011     _ _ b a
    // 4(c)    0100     _ c _ _
    // 5(ac)   0101     _ c _ a
    // 6(bc)   0110     _ c b _
    // 7(abc)  0111     _ c b a

    // Iterate over permutations
    for (int iPerm = 1; iPerm < nPermutations; iPerm++) // O(nPermutations)
    {
        string subStr = "";
        // Iterate over string idx positions
        for (int idx = 0; idx < iStr.length(); idx++) // O(iStrlength())
        {
            // bitwise AND comparision
            if (iPerm & (1 << idx))
                subStr += iStr[idx];
        }

        if (!subStr.empty())
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