#include<iostream>
using namespace std;

int & DanglingFunc()
{
    int i = 5;
    cout << "Address of i: " << &i << endl;
    return i;
}

int& NonDanglingFunc()
{
    static int i = 5;
    cout << "Address of i: " << &i << endl;
    return i;
}

int main()
{
    int& a = DanglingFunc();            // reference to variable 'i' which is already deleted.
    cout << "Address of a: " << &a << endl;
    cout << "Val a: " << a << endl;     // Throws some random value

    int& b = NonDanglingFunc();    // reference to variable 'i' which is already deleted.
    cout << "Address of b: " << &b << endl;
    cout <<"Val b: "<< b << endl;       // Throws correct value

    return 0;
}