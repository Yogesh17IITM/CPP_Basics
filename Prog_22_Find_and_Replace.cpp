/*
    Topic: Find, replace and erase

    Input : "abc abc def"
    To Do : 
        1) Find "bc" and replace with "???" and print the result
        2) Find "???" and erase it

    Output:
        1) a??? a??? def
        2) a a def
*/

#include<iostream>
using namespace std;

int main()
{
    string str = "abc abc def";

    string strToFind = "bc";
    string strToReplace = "???";

    // Find and replace
    auto pos = 0;
    while ((pos = str.find(strToFind, pos)) &&
           (pos != string::npos))
    {   
        str.replace(pos, strToFind.length(), strToReplace);
        pos += strToReplace.length() + 1;
    }
    cout << str << endl;

    // Find and erase
    pos = 0;
    strToFind = "???";
    while ((pos = str.find(strToFind, pos)) &&
        (pos != string::npos))
    {
        str.erase(pos, strToFind.length());        
    }
    cout << str << endl;

	return 0;
}