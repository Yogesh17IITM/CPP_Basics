/*
Ceaser Cipher - Encryption Technique

Description:
    Each letter of a given text is replaced by a letter some fixed number
    of positions down the alphabet.

For example,
    With a shift of 1, A would be replaced by B, B would become C, and so on.

Input  : ABC DEF1
Output : XYZ ABC1
*/

#include <iostream>
using namespace std;

// Spcify the Shift Index (i.e., No. of positions to be shifted)
#define SHIFT_IDX 1

string EncryptString(const string &iStr, int iSftIdx)
{
    string oEncryptStr = "";
    for (auto &iCh : iStr)
    {
        // Check if it is of non-char type. If so, append as it is.
        if (!(::isalpha(iCh)))
        {
            oEncryptStr += iCh;
            continue; // skip the below steps and continue to next iteration
        }

        // Determine the start index based on the case (upper/lower)
        int Start_Idx = (::isupper(iCh)) ? (int)'A' : (int)'a'; // For upper 'A' -> 65 and for lower 'a' -> 97

        // Calculate the new idx (New_Idx-Start_idx -> should be cyclic between 0 to 26)
        int New_Idx = ((int)iCh + iSftIdx - Start_Idx) % 26 + Start_Idx;

        // Cast the new index interger value into char type
        oEncryptStr += (char)New_Idx;
    }

    return oEncryptStr;
}

int main()
{
    string str = "ZAB DezF1";
    string strEncrypted = EncryptString(str, SHIFT_IDX);

    // Display Encrpted Message
    cout << strEncrypted << endl; // Notice: 'Z' and 'z' shifting to valid char instead of some undefined symbols

    return 0;
}