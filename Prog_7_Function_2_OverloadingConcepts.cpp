/* 
Objective:
	To demonstrate advantage of default parameter over function overloading

Example:
	Sum of given numbers

Key Topics:
	1) Function overloading
	2) Default parameter
	3) Manifest constants
*/

// Std Libraries
#include <iostream>
#include <string>

// The 'Using' directives
using namespace std;

// Manifest constants
#define ENTER(Message) cout << "[ENTER] " << Message << endl
#define EXIT(Message) cout << "[EXIT] " << Message << endl

// Function Prototypes
// 1) with default parameters
int add(int a,       // Normal parameter
        int b = 10,  // Default parameter
        int c = 20); // Default parameter

// 2) without default parameter
int area(int a);
int area(int iLength, int iBreadth); // function overloading (based on #args)

/* 
Note: 
	1) Default parametering happens from right to left.
	   It is always recommended to keep default params at the right and non-default param at the left.
	   So, that it will take default value automatically if you don't specify it.
	2) This function can also be created using function overloading
		(a) add(int)
		(b) add(int, int)
		(c) add(int, int, int)
		But here, instead of creating three functions with three different args, 
		creating a function with default args will be efficient
	3) Function cannot be overloaded based on return type alone.
*/

/* Main Program */
int main()
{
    string name;
    cout << "Enter your name: " << endl;
    cin >> name;

    // Display Name (in Uppercase)
    if (0 < name.size())
    {
        for (auto &iStr : name)
            iStr = ::toupper(iStr);
        cout << "Hello " << name << "\n"
             << endl;
    }

    // Demonstrating the usage of Default parameter
    cout << "1: Sum is " << add(100) << endl;
    cout << "2: Sum is " << add(100, 200) << endl;
    cout << "3: Sum is " << add(100, 200, 300) << endl;
    cout << "\n4: Area is \n" << area(5) << endl;
    cout << "\n5: Area is \n" << area(5, 6) << endl;

    return 0;
}

/* Function definitions */
int add(int a, int b, int c) { return (a + b + c); }

int area(int a)
{
    ENTER("area with one param");
    EXIT("area with one param");
    return (a * a);
}

int area(int iLength, int iBreadth)
{
    ENTER("area with two param");
    EXIT("area with two param");
    return iLength * iBreadth;
}