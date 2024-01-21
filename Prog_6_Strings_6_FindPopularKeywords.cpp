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
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// utility function to compare two pairs
bool compare(pair<string, int> &pairA, pair<string, int> &pairB)
{
    bool brc = false;
    if (pairA.second > pairB.second) // sort descending
    {
        brc = true;
    }
    else if (pairA.second < pairB.second)
    {
        brc = false;
    }
    else
    {
        brc = (pairA.first.compare(pairB.first) < 0); // sort alphabetically
    }
    return brc;
}

// Function to find 'k' popular keywords
vector<string> FindPopularKeyWords(vector<string> review, vector<string> key, int k)
{
    vector<string> ostr;
    map<string, int> mKey;

    // iterate over each review
    for (auto &irev : review)
    {
        string &strReview = irev; // read by string

        // convert all char to lowercase (assuming all given keys are in lower case)
        for (auto &ich : strReview)
        {
            if (::isalpha(ich))
                ich = ::tolower(ich);
        }

        // iterate over keys
        for (auto &ikey : key)
        {
            auto pos = 0;

            // lambda function to evaluate condition
            auto keyExists = [&]() -> bool
            {
                pos = strReview.find(ikey, pos);
                return (pos != string::npos);
            };

            // for a given review, monitor how many keys found
            // DO NOT USE the condition directly as shown below as it doesn't work properly
            // while((pos = strReview.find(ikey, pos)) && (pos != string::npos))
            while (keyExists())
            {
                mKey[ikey] += 1;
                pos += ikey.length();
            }
        }
    }

    // Copy map into vector<pair<..>> to use sorting algorithm
    vector<pair<string, int>> vecPair;
    for (auto &imap : mKey)
        vecPair.push_back(imap);

    // sort by popularity (or alphabetically if equally popular)
    sort(vecPair.begin(), vecPair.end(), compare);

    // Extract the desired results
    int count = 0;
    for (int idx = 0, count = 0; (idx < vecPair.size() && count < k); idx++, count++)
    {
        ostr.push_back(vecPair[idx].first);
    }

    return ostr;
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