/*
    Write a function to reverse the words
    Input : "Hai Hello How are you?"
    Output: "you? are How Hello Hai"
*/

#include<iostream>
using namespace std;

string ReverseString(string iString)
{
    reverse(iString.begin(), iString.end());    
    iString.append(" ");    
       
    auto StartPos = 0;
    auto EndPos = 0;

    // If string starts with " "
    if (iString[0] == ' ')
        StartPos++;

    while ((EndPos = iString.find(" ", StartPos)) &&
        (EndPos != string::npos))
    {
        reverse(iString.begin() + StartPos, iString.begin() + EndPos);
        StartPos = EndPos+1;
    }
    iString.erase(iString.end()-1, iString.end());
    
    return iString;
}

int main()
{
    string str = "Hai Hello How are you?";
    cout << "["<<ReverseString(str) << "]" << endl;
	return 0;
}