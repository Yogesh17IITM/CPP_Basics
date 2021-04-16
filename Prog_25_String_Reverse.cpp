#include<iostream>
#include<sstream>
#include<algorithm>
using namespace std;

string ReverseString(const string& iString)
{
    string oRevStr = iString;

    // reversed all characters
    reverse(oRevStr.begin(), oRevStr.end());
    
    int prevIdx = 0;
    int nextIdx = 0;
    for (int idx = 0; idx < oRevStr.length(); idx++)
    {
        if (oRevStr[idx] == ' ')
        {
            nextIdx = idx;
            reverse(oRevStr.begin() + prevIdx, oRevStr.begin() + nextIdx);            
            while (oRevStr[++idx] == ' ');
            {
                prevIdx = idx;                
            } 
        }

        // Treat for last word
        if (idx == oRevStr.length() - 1)
        {
            reverse(oRevStr.begin() + prevIdx, oRevStr.end());         
            break;
        }
    }
    return oRevStr;
}

int main()
{
    string str = " Hai  Hello ?";
    cout << "[" << str <<"]"<<endl;

    cout << "[" <<ReverseString(str)<<"]" << endl;
    return 0;
}