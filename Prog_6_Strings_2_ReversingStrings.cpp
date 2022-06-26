/*
    Write a function to reverse the words
    Input : "Hai Hello How are you?"
    Output: "you? are How Hello Hai"
*/

#include <iostream>
using namespace std;

string ReverseString(string iString)
{
    reverse(iString.begin(), iString.end());
    iString.append(" "); // adding dummy space at the end

    auto StartPos = 0;
    auto EndPos = 0;

    // If string starts with " "
    if (iString[0] == ' ')
        StartPos++;

    while ((EndPos = iString.find(" ", StartPos)) &&
           (EndPos != string::npos)) // every word is found and traversed with the help of the delimiter ' '
    {
        reverse(iString.begin() + StartPos, iString.begin() + EndPos);
        StartPos = EndPos + 1;
    }
    iString.erase(iString.end() - 1, iString.end()); // removing dummy space at the end

    return iString;
}

int main()
{
    string str = "Hai Hello How are you?";
    cout << "[" << ReverseString(str) << "]" << endl;
    return 0;
}

/*
SIMPLE SOLUTION (WITHOUT USING ANY PRE_DEFINED FUNCTIONS)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
#include<iostream>
using namespace std;

// Function to reverse the given string
string ReverseString(string iStr)
{
    string strRev = "";
    if(iStr.length() > 0)
    {
        for(int idx=iStr.length()-1; idx>=0; idx--)
        {
            strRev += iStr[idx];
        }
    }
    return strRev;
}

void PrintInReverse(string iStr)
{
    // 1) Reverse all the chars
    string strRev = ReverseString((" "+iStr));  // adding dummy space at the beginning of the sentence (before reversing).

    // 2) Find spaces and reverse words
    string tempStr="";
    int iCurrIdx = 0;
    string oRevString = "";

    for(auto & iCh : strRev)
    {
        if(iCh != ' ')
        {
            tempStr+=iCh;
        }
        else
        {
            if(tempStr.length() != 0)
            {
                oRevString+=ReverseString(tempStr) + iCh;
                tempStr="";
            }
            else
            {
                oRevString+=iCh;
            }
        }
    }

    oRevString = oRevString.substr(0, oRevString.length()-1);   (removing the dummy space at the end)
    cout<<oRevString<<endl;
}

int main()
{
    string str = "Hai Hello  How are you?";
    PrintInReverse(str);
    return 0;
}
*/