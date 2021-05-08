/* 
Objective:
	To demonstrate usage of Pointers and Reference as function arguments

Example:
	Swap values

Key Topics:
	1) Pointers
	2) Reference (alias)
    3) Functions - call by value, reference and pointers
    4) Function Overloading (imp. C++ feature)
    5) Macros with params
*/

// Std libraries
#include<iostream>

// using directive
using namespace std;

// Macros
#define ENTER(Message) cout<<"[ENTER] "<<Message<<endl
#define EXIT(Message) cout<<"[EXIT] " <<Message<<endl

// Function prototype
void DisplayValueAndAddress(
    int &a,     // a --> reference parameter (pass by reference)
    int b);     // b --> value parameter (pass by value)

// Function overloading (Function name is same and differ by its function signature)
void Swap(int a, int b);                                // 1. Call by value
void Swap(int * a, int * b);                            // 2. Call by address or pointer
void Swap(int &a, int &b, bool IsCallByReference);      // 3. Call by reference

/*
Below function overloading will create AMBIGUITY
void Swap(int a, int b);
void Swap(int & a, int & b);
*/

/* Main Function */
int main() 
{
    int a =10;
    int &b = a;         // creating alias to the variable "a"
    //int &c;           // WRONG. Alias doesn't have anything to refer to.
    //int &c = 5;       // WRONG. No address refer to as 5 is constant.
    const int &c = 5;   // CORRECT. since we can't change the value (which maintains constantness of the value)
    
    //int &d = b+c; // WRONG. address to refer "b+c" is temporary
    const int &d = b+c; // CORRECT
    
    cout<<"Value 1: " << "a = "<<a<<" b = "<<b<<endl;
    cout<<"Address: "<<"&a = "<<&a<<" &b = "<<&b<<endl;
    ++a;
    cout<<"Value 2: " << "a = "<<a<<" b = "<<b<<endl;

    // Function call
    DisplayValueAndAddress(a,a);    // Here (a,a) are the actual parameters

    int e = 111;
    int f = 222;

    cout <<"Value and address before swapping."<<endl;
    cout <<"a = "<<e<<" &a ="<<&e<<endl;    
    cout <<"b = "<<f<<" &b ="<<&f<<endl;

    // 1. Call by value
    Swap(e, f);            // Values are NOT Swapped
    cout <<"Value and address after swapping."<<endl;
    cout <<"a = "<<e<<" &a ="<<&e<<endl;    
    cout <<"b = "<<f<<" &b ="<<&f<<endl;
    cout <<endl;

    // 2. Call by pointer
    Swap(&e, &f);           // Values are swapped.
    cout <<"Value and address after swapping."<<endl;
    cout <<"a = "<<e<<" &a ="<<&e<<endl;    
    cout <<"b = "<<f<<" &b ="<<&f<<endl;
    cout <<endl;

    // 3. Call by reference
    Swap(e,f, true);        // Values are swapped again
    cout <<"Value and address after swapping."<<endl;
    cout <<"a = "<<e<<" &a ="<<&e<<endl;    
    cout <<"b = "<<f<<" &b ="<<&f<<endl;

    return 0;
}

void DisplayValueAndAddress(int &a, int b)  // Here a and b are formal parameters
{
    ENTER("DisplayValueAndAddress()");
    cout <<"a = "<<a<<" &a ="<<&a<<endl;    // Address is as same as input param
    cout <<"b = "<<b<<" &b ="<<&b<<endl;    // Address is different from input params
    EXIT("DisplayValueAndAddress()");
    return;
}

void Swap(int a, int b)
{    
    // Note: 
    // Actual paramters (e,f) are copied to the formal paramters (a,b).
    // So, the formal parameters (a,b) here won't affect the actual parameter (e,f)
    ENTER("CallByValue");    
    // Value swapping
    a = a+b;
    b = a - b; 
    a = a - b;    
    EXIT("CallByValue");
}

void Swap (int * pA, int * pB)
{   
    // Note: Formal parameters (pA,pB) affects the actual parameter (e,f)
    ENTER("CallByPointer");

    // Pointer may be NULL. So, validate it first.
    if(NULL != pA && NULL != pB)    
    {
        // Value swapping
        *pA = *pA + *pB;
        *pB = *pA - *pB;
        *pA = *pA - *pB;
    }
    EXIT("CallByPointer");
}

void Swap(int & a, int & b, bool IsCallByReference)
{       
    // Note: Formal parameters (a,b) affects the actual parameter (e,f)
    ENTER("CallByReference");
    // Value swapping
    a = a+b;
    b = a - b; 
    a = a - b;
    EXIT("CallByReference");
}