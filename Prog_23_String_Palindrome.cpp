#include<iostream>
using namespace std;

bool IsPalindrome(const string& iStr)
{
    bool bIsPalindrome = true;
    int i = 0;
    int j = iStr.length()-1;
    while ((i != j) &&
        (iStr[i++] != iStr[j--]))
    {
        bIsPalindrome = false;
        break;
    }
    return bIsPalindrome;
}

int main()
{
    string str1 = { "abc" };
    string str2 = "abba";
    string str3 = "abcba";

    cout << str1 << " " << (IsPalindrome(str1) ? " Is Palindrome" : "Is Not palindrome") << endl;
    cout << str2 << " " << (IsPalindrome(str2) ? " Is Palindrome" : "Is Not palindrome") << endl;
    cout << str3 << " " << (IsPalindrome(str3) ? " Is Palindrome" : "Is Not palindrome") << endl;

    return 0;
}