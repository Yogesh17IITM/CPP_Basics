/* Function Example */

/* Program for finding factorial

   Input	    : Type a number for finding Factorial
   Exp. output	: Factorial of that given no.
*/

#include <iostream>
using namespace std;

// Function Prototype
long unsigned int fact(int iNum);
long unsigned int recursiveFact(int iNum); // Calc. using recurive mechanism

int main()
{
    int num;
    cout << "Enter a number: " << endl;
    cin >> num;

    cout << "The Factorial of " << num << " is : " << fact(num) << endl;
    cout << "The Factorial of " << num << " is : " << recursiveFact(num) << endl;
    return 0;
}

// Function Definition
long unsigned int fact(int iNum)
{
    long unsigned int res = 1;
    while (iNum > 0) // O(N)
    {
        res = res * iNum;
        iNum--;
    }
    return res;
}

long unsigned int recursiveFact(int iNum) // O(N)
{
    if (0 == iNum)
        return 1;

    return (iNum * recursiveFact(iNum - 1));
}
