/*
Ceaser Cipher - Encryption Technique

Description:
    Each letter of a given text is replaced by a letter some fixed number
    of positions down the alphabet.

For example,
    With a shift of 1, A would be replaced by B, B would become C, and so on.

Input:
    string:     ZAB DezF1
    shiftIdx:   1

Output:
    ABC EfaG1
*/

#include <iostream>
using namespace std;

// Spcify the Shift Index (i.e., No. of positions to be shifted)
#define SHIFT_IDX 1

string EncryptedString(const string &str, int idx)
{
    string ostr = "";
    try
    {
        if (str.empty())
            throw -1;

        ostr = str;
        if (idx == 0)
        {
            throw -2;
        }

        for (auto &iCh : ostr)
        {
            // check if it is letter
            if (::isalpha(iCh))
            {
                int chVal = 0;
                char startLetter = ::isupper(iCh) ? 'A' : 'a';
                chVal = ((int)iCh + idx - (int)startLetter) % 26 + (int)startLetter;
                iCh = (char)chVal;
            }
            else
            {
                // it can be digits/special characters/space
                continue;
            }
        }
    }
    catch (const int &eRet)
    {
        if (eRet == -1)
            cout << " \n[ERROR] Empty string provided" << endl;
        else if (eRet == -2)
            cout << " \n[WARNING] Shift index is zero" << endl;
        else
        {
        }
    }

    return ostr;
}

int main()
{
    string str = "ZAB DezF1";
    int shiftIdx = 1;
    cout << EncryptedString(str, shiftIdx) << endl; // Notice: 'Z' and 'z' shifting to valid char instead of some undefined symbols

    shiftIdx = 0;
    cout << EncryptedString(str, shiftIdx) << endl;

    str = "";
    cout << EncryptedString(str, shiftIdx) << endl;

    return 0;
}