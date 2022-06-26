/*
    Demonstraing usage of Lambda Expressions
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string str1 = "Hai";
    string str2 = " Hello";

    // Traditional way
    vector<char> chArr;
    for (int idx = 0; idx < str1.length(); idx++)
        chArr.push_back(str1[idx]);

    for (int idx = 0; idx < str2.length(); idx++)
        chArr.push_back(str2[idx]);

    for (auto &iCh : chArr)
        cout << iCh;
    cout << endl;

    cout << "\nUsing Lamda:" << endl;

    // Using Lambda Expression
    chArr.clear();
    auto PushBack = [&](string iStr)
    {
        for (int idx = 0; idx < iStr.length(); idx++)
            chArr.push_back(iStr[idx]);
    };

    PushBack(str1);
    PushBack(str2);
    for (auto &iCh : chArr)
        cout << iCh;
    cout << endl;

    return 0;
}