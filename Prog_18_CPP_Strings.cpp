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

// Std Libraries
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<unordered_set>
#include<unordered_map>
#include<queue>
#include<utility>

// Using directive
using namespace std;

// Function Prototype
vector<string> FindMostPopularKeywords(vector<string> & iKeywords, vector<string> & iReviews, int & iPopular);

/* Main Program */
int main()
{
    // Inputs
    int nPopular = 2; // Top 'n' popular words
    vector<string> KeyWords{"anacell", "cetracular", "betacellular"};
    vector<string> Reviews{"Anacell provides the best services in the city", "betacellular has awesome services",
    "Best services provided by anacell, everyone should use anacell",};

    vector<string> PopularKeywords;
    PopularKeywords = FindMostPopularKeywords(KeyWords, Reviews, nPopular);

    for(auto iPopularKey:PopularKeywords)
        cout<<iPopularKey<<" ";

    return 0;
}

/* Function definitions */
vector<string> FindMostPopularKeywords(vector<string> & iKeywords, vector<string> & iReviews, int & iPopular)
{
    vector<string> oPopularKeywords;

    unordered_set<string> hashkey;
    for(auto curKey:iKeywords)
        hashkey.insert(curKey);

    unordered_map<string, int> mapKeyVal;
    for(auto curSentence:iReviews)
    {
        // convert all sentence to lowercase
        for (auto &alias:curSentence)
            alias = ::tolower(alias);

        // Stream each word from sentence
        stringstream sstream(curSentence);
        string Word;
        while(getline(sstream, Word, ' '))
        {
            if(hashkey.find(Word) != hashkey.end())
            {
                mapKeyVal[Word]++;
            }
        }
    }

    // Now sort out the Most popular word    
    priority_queue<pair<int, string>> sortedKeyVal;
    for(auto iKeyVal:mapKeyVal)
        sortedKeyVal.push(make_pair(iKeyVal.second, iKeyVal.first));

    while(!sortedKeyVal.empty())    
    {
        oPopularKeywords.push_back(sortedKeyVal.top().second);
        sortedKeyVal.pop();
    }

    return oPopularKeywords;
}