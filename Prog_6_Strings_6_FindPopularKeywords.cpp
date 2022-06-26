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
        ["anacell", "betacellular", ]

    Explanation:
        "anacell" is occuring in 3 different reviews and "betacellular" is only occuring in 1 review.
        Since k=2, first 2 popular keywords printed.
*/

#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

bool Compare(pair<string, int> &iKeyA, pair<string, int> &iKeyB)
{
    bool bIsGreater = false;

    // Compare the count
    if (iKeyA.second > iKeyB.second) // High-to-low
    {
        bIsGreater = true;
    }
    else if (iKeyA.second == iKeyB.second)
    {
        // Count is equal. Sort alphabetically.
        string str1 = iKeyA.first;
        string str2 = iKeyB.first;
        if (str1.compare(str2) < 0) // low-to high
            bIsGreater = true;
    }
    else
    {
        // do-nothing
    }

    return bIsGreater;
}

bool IsKeyExists(string iWord, vector<string> iKeyWords)
{
    bool bIsExists = false;

    // Change the logic if the number of keywords are huge or dynamic
    if ((iWord == iKeyWords[0]) ||
        (iWord == iKeyWords[1]) ||
        (iWord == iKeyWords[2]))
        bIsExists = true;

    return bIsExists;
}

vector<string> FindPopularKeyWords(vector<string> iStrReview,
                                   vector<string> iKeyWords, int k)
{
    // 1. Concatenate all the strings
    string strConc;
    for (auto &iCurrStr : iStrReview)
    {
        for (auto &iCh : iCurrStr)
        {
            // Include only letters and spaces (ignore special characters, symbols etc.,)
            if (::isalnum(iCh) || (' ' == iCh))
            {
                strConc += ::tolower(iCh);
            }
        }
    }

    // 2) Create Map b/w KeyWords and its count
    map<string, int> mKeyCount;
    for (auto &iCurrKey : iKeyWords)
        mKeyCount[iCurrKey] = 0; // Initialize to zero

    // 3) Find the keywords and increment the counter
    stringstream sstream(strConc);
    string strWord;
    while (getline(sstream, strWord, ' '))
    {
        // Check if the current word is listed in the popular keywords
        if (IsKeyExists(strWord, iKeyWords))
            mKeyCount[strWord] += 1;
    }

    // 4) Convert Map into Vector<pair>
    vector<pair<string, int>> pairKeyCount;
    for (auto &iMap : mKeyCount)
        pairKeyCount.push_back(iMap);

    // 5) Sort the keywords based on the count
    sort(pairKeyCount.begin(), pairKeyCount.end(), Compare);

    // 6) Append the top 'k' popular keywords
    vector<string> oStrKeyWords;
    for (int idx = 0; idx < k; idx++)
        oStrKeyWords.push_back(pairKeyCount[idx].first);

    return oStrKeyWords;
}

int main()
{
    vector<string> strReview = {"Anacell provides the best services in the city",
                                "betacellular has awesome services",
                                "Best services provided by anacell, everyone should use anacell"};

    vector<string> strKeyWords = {"anacell", "cetracular", "betacellular"};
    int k = 2;

    vector<string> strPopularKeyWords = FindPopularKeyWords(strReview, strKeyWords, k);

    cout << "[";
    for (auto &iKeyWords : strPopularKeyWords)
        cout << "\"" << iKeyWords << "\", ";
    cout << "]" << endl;

    return 0;
}