#include<iostream>
using namespace std;

int main()
{
    string input = "abc abc def";
    cout << "Input: " << input << endl;

    // Topic: Find and replace
    // Problem: find 'bc' and replace with ???
    string strToReplace = "bc";
    string strReplaceBy = "???";

    auto pos = 0;
    while ((pos = input.find(strToReplace, pos)) &&
        pos != string::npos)
    {
        input.replace(pos, strToReplace.length(), strReplaceBy);
        pos += strReplaceBy.length() + 1;
    }
    cout << "Output 1: " << input << endl;

    // Topic: Find and erase
    // Problem: find '???' and erase it
    string strToErase = "???";
    auto posToErase = 0;
    while ((posToErase = input.find(strToErase, posToErase)) &&
        posToErase != string::npos)
    {
        input.erase(posToErase, strToErase.length());
    }
    cout << "Output 2: " << input << endl;

    return 0;
}