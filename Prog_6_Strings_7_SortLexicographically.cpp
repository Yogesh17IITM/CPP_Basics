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
#include <algorithm>

using namespace std;

vector<string> SortStringLexicographically(vector<string> str)
{
    vector<string> ostr;
    vector<pair<string, string>> mkeyval;

    // util - lambda function for comparing strings
    auto compare = [](pair<string, string> &pairA, pair<string, string> &pairB) -> bool
    {
        bool ret = false;

        // sort alphabetically if it is cjaracter
        if (::isalpha(pairA.second[0]) && ::isalpha(pairB.second[0]))
        {
            ret = (pairA.second.compare(pairB.second) <= 0); // '=' : to return true if both are equal
        }
        // sort ascending if it is number
        else if (::isdigit(pairA.second[0]) && ::isdigit(pairB.second[0]))
        {
            ret = (pairA.second.compare(pairB.second) <= 0);
        }
        // sort letters and then numerics if it is mixed
        else
        {
            ret = (::isalpha(pairA.second[0]) && ::isdigit(pairB.second[0]));
        }

        return ret;
    };

    // iterate over the entities in vectors
    for (auto &istr : str)
    {
        auto pos = istr.find(" ", 0);
        string key = istr.substr(0, pos + 1);             // get key (along with space at end)
        string val = istr.substr(pos + 1, istr.length()); // get value

        // Form a key-val pair
        mkeyval.push_back(make_pair(key, val));
    }

    // sort lexicographically
    sort(mkeyval.begin(), mkeyval.end(), compare);

    // combine key and corresponding values
    for (auto &ikeyval : mkeyval)
        ostr.push_back(ikeyval.first + ikeyval.second);

    return ostr;
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