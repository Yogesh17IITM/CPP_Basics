/*
Objective:
    1) To demonstrate how dangling pointer is getting created

Example:
    Display Greeting message

Key Topics:
    1) Pointers
*/

#include <iostream>
using namespace std;

int main()
{
    int *p = new int(5);
    if (p)
    {
        cout << p << " " << *p << endl;
    }
    delete p;

    // The variable 'p' becomes dangling pointer
    // cout << p << " " << *p << endl;
    cout << p << " " << endl; // 00008123 (random address)

    p = nullptr; // DO NOT USE "NULL" as it is equal to 0
    // cout << p << " " << *p << endl;  // ERR: Read access violation
    cout << p << " " << endl; // 00000000
    return 0;
}