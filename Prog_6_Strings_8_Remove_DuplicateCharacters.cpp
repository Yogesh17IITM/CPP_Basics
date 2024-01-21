/*
    TOPIC: remove duplicate characters in a string

    Input: Hello World hai
    Output: adehilorw
*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

string RemoveDuplicates(string iStr)
{
    string oStr = "";
    vector<char> chList;
    for (auto &ich : iStr)
    {
        if (::isalpha(ich))
            chList.push_back(::tolower(ich)); // convert always to lower-case
    }

    // Set: Stores only unique characters (which is sorted alphabetically)
    set<char> UniqueStr(chList.begin(), chList.end()); // ignore spaces and keep only unique data
    for (auto &iCh : UniqueStr)
        oStr += iCh;

    return oStr;
}

int main()
{
    string str = "Hello World hai";
    cout << "Uniq Str: " << RemoveDuplicates(str) << endl;
}