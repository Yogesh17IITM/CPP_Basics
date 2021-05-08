/* 
Objective: 
	To Demonstrate the usage of inline functions over Manifest constants with params

Example:
    Calculating Squares of numbers

Key Topics:
	1) Manifest constants Problems and Fix
	2) Inline functions
	3) Pragma regions (facility to expand or collapse a block of code)
*/

// Std Library
#include<iostream>

// Using directive
using namespace std;

// MACROs or Manifest contants
#define SQUARE_TYPE1(a)   a*a     
#define SQUARE_TYPE2(a)   (a)*(a)

// IN-LINE FUNCTION
inline int SQUARE(int iNum)   {return iNum * iNum;}

int main()
{
    int a = 5;       
    cout<<"Result 1: " << SQUARE_TYPE1(a) << endl;       // ans : 25

// PROBLEM 1: Syntactic Pitfall - 'a+1'
#pragma region Problem1    
    cout<<"Result 2: " << SQUARE_TYPE1(a+1) << endl;     // WRONG MACRO EXPANSION
    /*
    Here the result is 30 and NOT 36.
    Because it expands to a+1*a+1. On applying BODMAS rule, 5 + (1 * 5) + 1 = 5 + 5 + 1 = 11
    */

    // FIX:
    cout<<"Result 3: " << SQUARE_TYPE2(a+1) << endl;     // CORRECT MACRO EXPANSION
#pragma endregion Problem1

// PROBLEM 2: Semantic Pitfall '++a'
#pragma region Problem2
    cout<<"Result 4: " << SQUARE_TYPE2(++a) << endl;     // WRONG MACRO EXPANSION
    /*
    Here the macro expands to (++a) * (++a).
    The prefix increment operator "++" will increment twice instead of once.
    So the result will be 49 and NOT 36!
    */

    // FIX: Use inline functions
#pragma endregion Problem2
    // Reset 'a' as it has incremented
    a = 5;      
// Inline functions
#pragma region inlinedemo
    cout<<"Result 5: " << SQUARE(++a) << endl;          // 36. CORRECT RESULT!
    /*
    In Macros, syntactic pitfalls van be fixed by using "(" and ")"
    but the semantic pitfalls cannot be fixed.
    So the inline functions are comparatively efficient than MACROS

    Note: 
    1) Inline functions are available for debug only on DEBUG build
       and not on the RELEASE build to maintain efficiency.
    2) Inline function body should be as small as possible
    3) Inline functions can't be RECURSIVE.
    4) In header .h files, along with function prototype, 
        function body also has to be there in case of inline functions.
    */
#pragma endregion inlinedemo

    return 0;
}