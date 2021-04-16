#include<iostream>
#include<unordered_map>
#include<algorithm>

using namespace std;

int FindFirstUniqChar(const string& iStr)
{
    int oRet = -1;    

    unordered_map<char, int> uMap;
    for (auto& iCh : iStr)
        uMap[iCh]++;

    vector<char> ListOfUniqChar;
    for (auto& iMap : uMap)
    { 
        if (iMap.second == 1)
        {
            ListOfUniqChar.push_back(iMap.first);
        }
    }

    for (int idx=0; idx<iStr.length(); idx++)
    {
        if (find(ListOfUniqChar.begin(), ListOfUniqChar.end(), iStr[idx]) != ListOfUniqChar.end())
        {
            oRet = idx;
            break;
        }
    }

    return oRet;
}


int main()
{
    string str = "GeekForGeeks";
    cout << FindFirstUniqChar(str) << endl;   

    return 0;
}

