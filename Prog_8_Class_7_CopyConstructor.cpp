#include<iostream>

#include<stdio.h>
#include<string.h>
using namespace std;

class Complex
{
    double _Re, _Im;   

public:
    // C'tor
    Complex(double iRe = 0, double iIm = 0) : _Re(iRe), _Im(iIm)
    {
        cout <<"Constructor: |"; print();
    }

    // Copy C'tor (Call By Value Mechanism - here make a copy/ clone of the actual param as formal param)
    Complex(const Complex & iComplex) : _Re(iComplex._Re), _Im(iComplex._Im)
    {     
        cout <<"Copy Constructor: |"; print();
    }
    // NOTE: If user didn't create copy c'tor, compiler will create default copy c'tor

    // BELOW CODE WILL LEAD TO STUCK INTO INFINITE LOOP
    // Complex(Complex iComplex) {}
    // The above constructor uses call by value mechanism
    // Also, the func signature (code within "(" and ")") itself again a call by value 
    // It will itself try to call again and again leads to infinite loop
    // So, we cannot pass a value to the copy c'tor using call-by-value mechanism

    Complex& operator=(const Complex & iComplex)
    {
        this->_Re = iComplex._Re;
        this->_Im = iComplex._Im;
         cout <<"Copy assignment operator: |"; print();
        return *this;
    }

    // D'tor
    ~Complex() {cout <<"Destructor: |"; print();}

    void print() {cout<<_Re<<"+i"<<_Im<<"|"<<endl;}
};


class UsrDefinedString
{
public:
    char * _ch;
    size_t _len;

    UsrDefinedString(char * iCh) : _ch(strdup(iCh)), _len(strlen(iCh)) {} // C'tor

    // Copy c'tor used here for deep copying (i.e., copying the pointed data rather than copying address)
    UsrDefinedString(const UsrDefinedString & iString)  // copy C'tor
    {
        _ch = strdup(iString._ch);      // Deep Copying (object copying)
        _len = iString._len;
    }    

    UsrDefinedString &operator=(const UsrDefinedString & iString)
    {
        cout<<"UsrDefinedString: Copy assignment operator"<<endl;
        if (this != &iString)           // To prevent self-copy (Eg. if we do, C1 = C1, Prg will crash)
        {
            free(_ch);                 // Release existing memory to avoid memory leak
            _ch = strdup(iString._ch); // performing deep copying
            _len = iString._len;
        }
        return *this;   // De-reference to maintain associativity (Say, C1 = C2 = C3)
    }

    ~UsrDefinedString()
    {   
        free(_ch);
    }

    void print() {cout <<"Str: "<<_ch<<" Len: "<<_len<<endl;}
};

void Display(Complex iComplex) 
{
    iComplex.print();
}

void StrToUpper(UsrDefinedString iStr)  // Copy C'tor called
{
    for (size_t i = 0; i < iStr._len; i++)
    {
        iStr._ch[i] = ::toupper(iStr._ch[i]);
    }
    iStr.print();    
    // Note: Without copy c'tor, shallow copy happen and "_ch" will be deleted here itself
    // Since, in shallow copy, only the pointer is copied and not the pointed object
}

int main()
{
    Complex C1(1,1);            // Default Constuctor called
    Complex C2(C1), C3 = C1;    // Copy Constructor called
    Complex C4;                 // Default Constructor called
    C4 = C1;                    // Overloading Operator called

    Display(C4);                // NOTE: Copy c'tor called

    char ch[] = "hello";
    UsrDefinedString obj(ch);
    StrToUpper(obj);

    obj.print();

    UsrDefinedString obj2(ch);
    obj2 = obj;                 // Copy assignment operator
    obj2.print();


    return 0;
}