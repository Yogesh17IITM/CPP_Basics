/*
Objective:
    Sort string lexicographically

Problem:
    There are list of string sets (in lower case) available with an
    identifier (alpha-numeric) at the beginning of the each string sets.
    You have to sort the string sets lexicographically.

Sample Input:
    {"ab1 pillow bed fan towel",
     "gh2 goat cow tiger lion",
     "h34 44 67 34 56",
     "yr1 love friend enemy brother"}

Sample Output:
    {"gh2 goat cow tiger lion",
     "yr1 love friend enemy brother",
     "ab1 pillow bed fan towel",
     "h34 44 67 34 56",
    }

Explanation:
    String are sorted out lexicographically (alphabetical order).
    [G]oat < [L]ove < [P]illow
    Numerics should be kept at the last in the ascending order.
*/

#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

bool Compare(pair<string, string> & iKeyVal, pair<string, string> & jKeyVal)
{
    bool obRc = false;
    string iStr = iKeyVal.second;
    string jStr = jKeyVal.second;

    if (isdigit(iStr[0]) || isdigit(jStr[0]))
    {
        obRc = (iStr[0] > jStr[0]) ? true : false;
    }
    else
        obRc = (iStr[0] < jStr[0]) ? true : false;
    return obRc;
}

int main()
{
    vector<string> str{ "ab1 pillow bed fan towel",
                        "gh2 goat cow tiger lion",
                        "h34 44 67 34 56",
                        "yr1 love friend enemy brother" };

    // Separate Key and values     
    vector<pair<string, string>> ListOfKeyVal;
    for(auto &iStr:str)
    { 
        string strKey;
        string strValue;

        stringstream sstream(iStr);
        string word;
        pair<string, string> KeyVal;

        while (getline(sstream, word, ' '))
        {  
           strKey = word;
           break;           
        }

        if(0 < strKey.size())
            strValue = iStr.substr(strKey.length(), iStr.length() - strKey.size());

        KeyVal = make_pair(strKey, strValue);
        ListOfKeyVal.push_back(KeyVal);
    }

    sort(ListOfKeyVal.begin(), ListOfKeyVal.end(), Compare);

    for (auto& iStr : ListOfKeyVal)
        cout << iStr.first << iStr.second << endl;

    return 0;
}