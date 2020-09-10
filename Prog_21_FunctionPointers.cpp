/* 
Objective: 
	To demonstrate the usage of function pointers

Example:
	Arithmetic operations

Key Topics:
	1) Function Pointers
    2) Function and call by value    
*/

// Std Libraries
#include <iostream>

// The 'Using' directive
using namespace std;

// Arithmetic operations
int add(int a, int b) {return (a+b);}
int sub(int a, int b) {return (a-b);}
int multiply(int a, int b) {return (a*b);}

/* Main program */
int main()
{
    // Definiting function pointer
    int (*FuncPtrArithmetic[]) (int a, int b) = {add, sub, multiply};
    int count = (sizeof(FuncPtrArithmetic)/sizeof(int) );

    cout <<"Size: "<< count << endl;

    for (int idx=0; idx<count; idx++)
    {
        cout << (*FuncPtrArithmetic[idx])(1,2)<< endl;
    }

    return 0;
}