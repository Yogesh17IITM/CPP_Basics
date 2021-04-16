#include <iostream>
#include<vector>
#include <set>
using namespace std;

string RemoveDuplicates(string iStr)
{
    string oStr = "";
    vector<char> chList;
    for (auto& ich : iStr)
        chList.push_back(ich);

    // Set: Stores only unique characters
    set<char> UniqueStr(chList.begin(), chList.end());
    for (auto& iCh : UniqueStr)
        oStr += iCh;
       
    return oStr;
}

int main()
{
    string str = "GeekForGeeks";
    cout << "Uniq Str: " << RemoveDuplicates(str) << endl;
}