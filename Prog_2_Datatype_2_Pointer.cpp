/*
Objective:
    1) To demonstrate how to declare and define methods
    2) To demonstrate the usage of consts and pointers

Example:
    Display Greeting message

Key Topics:
    1) Methods - Pass By reference
    2) Const and pointers
*/

// Std Libraries
#include <iostream>
#include <string>

// 'Using' directives
using namespace std;

// Function Prototype or Method declaration
// int welcome(const string &iStrName);     // simple function

// Template function (to handle all datas)
template <typename T>
void welcome(T &iData)
{
    cout << "[Simple Data] Hello " << iData << endl;
}

// Template function (to handle all pointer datas)
template <typename T>
void welcome(T *iPtrData)
{
    if (nullptr != iPtrData)
        cout << "[Pointer Data] Hello " << *iPtrData << " address: " << iPtrData << endl;
}

/* Main Function */
int main()
{
    /*
    CV-qualifers - 	"const" and "volatile"
        1) const - variable can be set only at initialization and cannot be changed further
        2) volatile - Value will be changed everytime when it is used.
    */
    const string strName = "Yogesh";
    string strUser = "Default";

    // Function call
    welcome(strName);

    // string * pStrName = &strName;			// Compilation Error! to maintain Constantness of data

    // 1. Assigning data to pointer
    cout << "case 1.1 :";
    welcome(strUser);
    string *pStrName = &strUser; // Works fine
    *pStrName = "User";
    cout << "case 1.2 :";
    welcome(strUser);

    // 2. Assigning const data to pointer
    const string *pConstStrName = &strName;
    // string *pStrName = &strName; // Not allowed. Cannot assign const data to a pointer type.
    //  *pConstStrName = "Hello";				// Not allowed to modify data
    cout << "case 2.1 : ";
    welcome(pConstStrName);

    pConstStrName = &strUser;
    // *pConstStrName = "Ram";					// Not allowed to modify data
    cout << "case 2.2 : ";
    welcome(pConstStrName);

    // 3. Assigning data to const pointer
    string *const ConstPtrStrName = &strUser;
    cout << "case 3 : ";
    welcome(ConstPtrStrName);
    // ConstPtrStrName = &strName;				// Changing Pointee NOT allowed

    // 4. Assigning const data to const pointer
    const string *const ConstPtrConstStrName = &strUser;
    //*ConstPtrConstStrName = "hai";				// Data Modification NOT allowed
    // ConstPtrConstStrName = &strName;				// changing pointee NOT allowed
    cout << "case 4 : ";
    welcome(ConstPtrConstStrName);

    return 0;
}

/* Simple Function Definition */
// int welcome(const string &iStrName)
// {
//     cout << "Welcome " << iStrName << endl;
//     return 0;
// }