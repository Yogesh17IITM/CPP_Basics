/*
Objective:
    To demonstrate bitwise operations

Example:
    String comparision using bitwise operation (XOR)

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
// void CompareChar(char *iChA, char *iChB); // could be 'bad' function signature as it is unclear whether the input should be array or a pointer of some char variable
void CompareChar(char iChA[], char iChB[]); // suitable one as it clearly says the input is going to be array

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
void CompareChar(char iChA[], char iChB[])
{
    while ((*iChA != '\0') && (*iChB != '\0'))
    {
        if ((*iChA ^ *iChB) != 0) // 'XOR' operation will give bit value 1 if the bits are different
        {
            break;
        }
        // proceed with comparision of next character
        iChA++;
        iChB++;
    }

    if ((*iChA == '\0') && (*iChB == '\0')) // Condition satisfies only if both char arrays are same
        cout << "Both strings are equal" << endl;
    else
        cout << "Both strings are NOT equal" << endl;
}