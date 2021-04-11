/*
Objective: Practice Sets (C++ Strings)

Question:
    Given a list of reviews, a list of keywords and an integer k.
    Find the most popular k keywords in order of most to least frequently mentioned.
    The comparison of strings is case-insensitive.
    Multiple occurances of a keyword in a review should be considered as a single mention.
    If keywords are mentioned an equal number of times in reviews, sort alphabetically.

Sample Input and Output:
    Input:
        k = 2
        keywords = ["anacell", "cetracular", "betacellular"]
        reviews = [
        "Anacell provides the best services in the city",
        "betacellular has awesome services",
        "Best services provided by anacell, everyone should use anacell",]

    Output:
        ["anacell", "betacellular"]

    Explanation:
        "anacell" is occuring in 2 different reviews and "betacellular" is only occuring in 1 review.
*/

#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<unordered_map>
#include<algorithm>
using namespace std;

bool MapCompare(pair<string, int> &a, pair<string, int> &b)
{
    return (a.second > b.second) ? true : false;
}

int main()
{
    vector<string> strReview = { "Anacell provides the best services in the city",
        "betacellular has awesome services",
        "Best services provided by betacellular, everyone should use betacellular" };

    vector<string> strKey = { "cetracular", "betacellular", "anacell" };

    // 1) Convert all to lower case
    for (int idx = 0; idx < strReview.size(); idx++)
    {
        string & iStr = strReview[idx];
        for (int iCh = 0; iCh < iStr.length(); iCh++)
        {
            iStr[iCh] = ::tolower(iStr[iCh]);
        }        
    }

    // Compare keys
    unordered_map<string, int> u_map;
    for (int idx = 0; idx < strReview.size(); idx++)
    {
        stringstream sstream(strReview[idx]);
        string word;
        while (getline(sstream, word, ' '))
        {
            for (int iKey = 0; iKey < strKey.size(); iKey++)
            {                
                //if (word == strKey[iKey])                
                size_t Found = word.find(strKey[iKey]);
                if(Found != string::npos)
                {
                    u_map[strKey[iKey]]++;
                    break;
                }
            }            
        }
    }

    // Sort Map
    vector<pair<string, int>> KeyVal;
    for (auto& it : u_map)
        KeyVal.push_back(it);

    sort(KeyVal.begin(), KeyVal.end(), MapCompare);

    for (auto & iKeyVal : KeyVal)
    {
        cout <<"Key: "<< iKeyVal.first;
        cout << " Count: " << iKeyVal.second<<endl;
    }

    return 0;
}

