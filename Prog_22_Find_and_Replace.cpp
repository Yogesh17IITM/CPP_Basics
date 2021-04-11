#include<iostream>
using namespace std;

int main()
{
    string input = "abc abc def";
    cout << "Input: " << input << endl;

    // find bc and replace with ???
    string strToReplace = "bc";
    string strReplaceBy = "???";

    auto pos = 0;
    while ((pos = input.find(strToReplace, pos)) &&
        pos != string::npos)
    {
        input.replace(pos, strToReplace.length(), strReplaceBy);
        pos += strReplaceBy.length() + 1;
    }

    /*pos = input.find(strToReplace, pos);
    input.replace(pos, strToReplace.length(), strReplaceBy);*/

    cout << "Output: " << input << endl;
    return 0;
}