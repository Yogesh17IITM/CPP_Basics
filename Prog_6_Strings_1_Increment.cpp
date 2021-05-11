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


#include<iostream>
using namespace std;

string DisplayEncryptedMsg(string iString, int iShiftIdx)
{
    string oEncryptedString = iString;
    if (0 == iShiftIdx)    
        return oEncryptedString;
    
    for(auto & iCh: oEncryptedString)
    {
        if (::isalpha(iCh))
        {
            int chStartIdx = 65;    // 'A' --> 65
            if (::islower(iCh))
            {
                // Encrypt Uppercase                
                chStartIdx = 97; // 'a' --> 97                
            }
            
            // Encrypt Message
            iCh = char(int(iCh - chStartIdx + iShiftIdx) % 26 + chStartIdx);
        }
        else
        {
            continue;
        }
    }
    return oEncryptedString;
}

int main()
{
    string str = "ABC DEF1";    
    cout << DisplayEncryptedMsg(str, 23);
	return 0;
}