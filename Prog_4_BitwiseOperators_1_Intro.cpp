/*
Objective:
    To demonstrate bitwise operations

Example:
    String comparision using bitwise opeation (XOR)

Key Topics:
    1) Char array, Pointers
    2) String comparision
    3) bitwise operations : AND, OR, XOR, Left and Right Shift
*/

// Std Libraries
#include <iostream>

// The 'Using' directive
using namespace std;

// Function declaration
void CompareChar(char *iChA, char *iChB);

/* Main program */
int main()
{
    unsigned int a = 5, b = 6; // (5 = 0101, 6 = (0110)
    int c = 0;
    cout << a << " " << b << endl;

    // Bitwise operations
    cout << "1) AND: " << (a & b) << endl;          // returns 1 only if both bits are 1
    cout << "2) OR: " << (a | b) << endl;           // returns 1 if any of the two bits is 1.
    cout << "3) XOR: " << (a ^ b) << endl;          // returns 1 if the two bits are different.
    cout << "4) Left shift: " << (a << 2) << endl;  /* left shifts the bits of the first operand,
                                                       the second operand decides the number of places to shift.
                                                       010100 = 20 */
    cout << "5) Right shift: " << (a >> 2) << endl; /* right shifts the bits of the first operand,
                                                       the second operand decides the number of places to shift.
                                                       0001 = 1 */
    char chA[] = "Hello";
    char chB[] = "Hello";
    cout << "Comparing strings 1: ";
    CompareChar(chA, chB);

    char chC[] = "Hell";
    cout << "Comparing strings 2: ";
    CompareChar(chA, chC);
    return 0;
}

// Function definition
void CompareChar(char *iChA, char *iChB)
{
    bool bIsSame = true;
    while ((*iChA != '\0') && (*iChB != '\0') && bIsSame == true)
    {
        if (0 != (*iChA ^ *iChB))
            bIsSame = false;

        iChA++;
        iChB++;
    }

    // check if next char still exists in either of char array
    if (*iChA != '\0' || *iChB != '\0')
        bIsSame = false;

    // Display results
    if (bIsSame)
        cout << "Strings are equal" << endl;
    else
        cout << "Strings are NOT equal" << endl;
}