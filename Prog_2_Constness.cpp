/* 
Objective:
	1) To demonstrate the usage of constness and const member functions

Example:
	Storing Credit Card Details

Key Topics:
	1) Const data member
    2) Const member function

Note:
    1) Const objects can call only const member functions
    2) Non-Const objects can call const and non-const member functions
    3) Const members can be intialized only in the initialization list as it is not allowed to modify later
*/

#include<iostream>
#include "string.h"

using namespace std;

class CreditCard
{
    const string _Name;         // Name of card holder should NOT be changed
    const char * _CardNumber;   // Card Number also should NOT be changed
    string _Address;            // User's address may be modified at any time when required.

public:
    CreditCard(const string iName, const char * iCardNum, string iAddress = "NA") : _Name(iName), 
    _CardNumber(strcpy(new char[strlen(iCardNum)+1], iCardNum)), _Address(iAddress) 
    {
        // Const members should be initialized in initialization list
        // and Not allowed to initialize in the body
        // For Eg: Below code is NOT allowed as it modifies the const data member
        // _CardNumber = new char[strlen(iCardNum)+1]; 
        // strcpy(_CardNumber, iCardNum);
    }
    ~CreditCard()
    {
        cout << endl;
        cout <<"## Credit-Card Details ##"<<endl;
        cout<<"Name = " << _Name <<endl;
        cout<<"Card Number = "<<_CardNumber<<endl;
        cout<<"Address = "<<_Address<<endl;
    }

    void SetAddress(const string & iAddress) { _Address = iAddress;}
    const char* GetCardNumber() const { return _CardNumber;}
};


int main()
{
    CreditCard obj("Yogesh", "1234 5678 2345 1234");
    obj.SetAddress("Madurai, TN");
    
    cout <<"Printing Card Number (from Non-Const Obj): "<<obj.GetCardNumber()<<endl;
    
    const CreditCard constObj("Priya", "4321 5678 1234 4321"); // Can call only const member func
    cout <<"Printing Card Number  (from Const Obj):: "<<constObj.GetCardNumber()<<endl;

    return 0;
}