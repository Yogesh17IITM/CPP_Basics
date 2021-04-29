/*
    Write a function to check if the given string is palindrome or not?
*/

#include<iostream>
using namespace std;

#define PRINT(Msg) cout<<Msg<<endl

bool IsPalindrome(const string& iStr)
{
    bool bIsPalindrome = true;

    int idx = 0;
    int jdx = iStr.length()-1;

    while (idx <= jdx)
    {
        if (iStr[idx++] != iStr[jdx--])
        {
            bIsPalindrome = false;
            break;
        }
    }    

    return bIsPalindrome;
}

int main()
{
    // Lambda expression
    auto CheckIfPalindrome = [](string iStr) {
        IsPalindrome(iStr) ? PRINT("YES") : PRINT("NO");
    };

    // Check if Palindrome?
    CheckIfPalindrome("Hello");
    CheckIfPalindrome("abc");
    CheckIfPalindrome("aba");
    CheckIfPalindrome("abccba");
    CheckIfPalindrome("abcdba");
    CheckIfPalindrome("abcdcba");
    
	return 0;
}
