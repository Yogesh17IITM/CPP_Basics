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

#include<iostream>
#include<sstream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

bool Compare(pair<string, int> & iKeyA, pair<string, int>& iKeyB)
{
    bool oRes = false;
    if (iKeyA.second > iKeyB.second)
    {
        oRes = true;
    }
    return oRes;
}

vector<string> FindPopularKeyWords(vector<string> iStrReview,
                                   vector<string> iKeyWords, int k)
{
    vector<string> oStrKeyWords;

    // 1) Convert all characters into lower case.
    //    replace all special characters by space.
    for (auto& iStr : iStrReview)
    {
        for (auto& iCh : iStr)
        {
            iCh = ::tolower(iCh);
        }
    }

    map<string, int> mapKeyVal;

    // 2) Find the popular Key words
    for (auto& iStr : iStrReview)    
    {        
        for (auto& iKey : iKeyWords)
        {
            auto pos = 0;

            // Check if starting word is Keyword
            if (iKey == iStr.substr(0, iKey.length()))
            {                
                mapKeyVal[iKey]++;
                pos = iKey.length() + 1;
            }                

            // Check the popularity of keywords
            while ((pos = iStr.find(iKey, pos)) &&
                   (pos != string::npos) )
            {
                mapKeyVal[iKey]++;
                pos += iKey.length() + 1;
            }            
        }
    }
     
    // 3) Sort KeyWords based on the popularity level
    vector<pair<string, int>> KeyVal;
    for (auto& iKey : mapKeyVal)
        KeyVal.push_back(make_pair(iKey.first, iKey.second));
    sort(KeyVal.begin(), KeyVal.end(), Compare);

    // 4) Extract top 'k' popular words
    for (int idx = 0; ((idx < KeyVal.size()) && (idx < k)); idx++)    
        oStrKeyWords.push_back(KeyVal[idx].first);    

    return oStrKeyWords;
}

int main()
{
    vector<string> strReview = { "Anacell provides the best services in the city",
                                 "betacellular has awesome services",
                                 "Best services provided by anacell, everyone should use anacell" };

    vector<string> strKeyWords = { "anacell", "cetracular", "betacellular" };
    int k = 2;

    vector<string> strPopularKeyWords = FindPopularKeyWords(strReview, strKeyWords, k);

    cout << "[";
    for (auto& iKeyWords : strPopularKeyWords)
        cout <<"\""<< iKeyWords << "\", ";
    cout << "]" << endl;

    return 0;
}