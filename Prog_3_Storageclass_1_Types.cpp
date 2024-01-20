/*
TOPIC:
    Demonstrate storage class types such as auto, static, extern, mutable and register
*/

#include <iostream>
using namespace std;

int i = 6;
int GetIdxCount()
{
    static int idx = 1;
    return idx++;
}

struct Fixed
{
    int FixedData = 6;
    mutable int ModifiableData = 7;
};

int main()
{
    // 1) Auto
    auto str = "Index";
    auto num = 6;
    cout << str << " : " << num << endl;

    // 2) Extern
    cout << "Val: " << i << " Address: " << &i << endl;
    extern int i; // Check without 'extern'
    i = 4;
    cout << "Val: " << i << " Address: " << &i << endl;

    // 3) static
    cout << GetIdxCount() << endl;
    cout << GetIdxCount() << endl;

    // 4) mutable
    const Fixed cObj;
    // cObj.FixedData = 8;         // Not allowed
    cObj.ModifiableData = 9;
    cout << cObj.ModifiableData << endl;

    // 5) register
    register int reg = 5; // Value stored in register if free register is available.
    cout << "Val: " << reg << endl;

    return 0;
}