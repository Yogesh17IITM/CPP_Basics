/* 
Objective:
	To demonstrate operator overloading

Example:
	Display greeting message

Key Topics:
	1) C++ Class creation    
    2) Operator Overloading ('=', '*', '->')
    3) 'Explicit' keyword in Constructor
    4) C++ Dynamic memory allocation ('new' and 'delete' operators)
    5) Smart Pointers - to manage lifecycle of pointer automatically

Notes:
    1) Operator Overloading - usually written in 'infix' notations
       Example: 
       1.1) a*b - infix
       1.2) ++a - prefix
       1.3) a++ - postfix

    2) Function always uses 'prefix' notation
        Example: min(a,b)  - where min is prefix with 2 args

    3) How to differentiate operator overloading for a++ vs ++a?
        3.1) MyType& operator++(MyType& s1);       // for prefix (++a)
        3.2) MyType operator++(MyType& s1, int);   // for postfix (a++)
*/

// Std Libraries
#include<iostream>
#include<string>

// 'Using' directives
using namespace std;

/* Class definitions */
// 1) Class SmartPtr - to manage lifecycle of pointer
template<class T>           // Function template
class SmartPtr 
{
    T * _ptr;
public:
    explicit SmartPtr(T *ip = NULL)     // 'explicit' keyword used to avoid any implicit conversion
    { 
        cout <<"SmartPtr constructor() called"<<endl;
        _ptr = ip; 
    }
    virtual ~SmartPtr() 
    {
        cout <<"SmartPtr destructor() called"<<endl; 
        if(NULL != _ptr)
            delete _ptr;                // Freeing up memory
    }    
    SmartPtr& operator=(T *ip)
    {
        cout <<"Overloading operator() called"<<endl;
        this->_ptr = ip;
        return *this;        
    }    
    T &operator*() { return *_ptr; }
    T *operator->() { return _ptr; }
    operator bool() const { return (_ptr) ? true : false; }
};

class MyClass
{
    string _name;
    int _age;
public:
    void SetName(const string &iStrName) { _name = iStrName; }
    string GetName() { return _name; }
    void SetAge(const int &iAge) { _age = iAge; }
    int GetAge() { return _age; }
};

/* Function definitions */
void Greeting(string iName, const int & iAge)
{    
    // convert name to upper case
    for(auto & iStr:iName)
        iStr = ::toupper(iStr);     

    /*
    Dynamic Memory Allocation
    ^^^^^^^^^^^^^^^^^^^^^^^^^
    1) operator 'new' - to allocate memory
    2) operator 'delete' - to deallocate memory

    Note: 
    'new' and 'delete' are operators whereas 'malloc' and 'calloc' in 'c programming' are functions.
    */

    // case 1:
    SmartPtr<MyClass> spMyClass1(new MyClass);      // Initialized by Constructor 
    if(spMyClass1)      // operator overloading 'bool()'
    {
        spMyClass1->SetName(iName);
        spMyClass1->SetAge(iAge);
        cout << "\nHello " << spMyClass1->GetName() << "! You are " << spMyClass1->GetAge() << " now!\n"<< endl;
    }

    // convert name to lower case
    for(auto & iStr:iName)
        iStr = ::tolower(iStr);     

    // case 2:
    SmartPtr<MyClass> spMyClass2;
    spMyClass2 = new MyClass;       // Initialized by '=' overload operator
    // spMyClass2 = spMyClass1;     // Also, works fine (requires deep copying)
    if(spMyClass2)
    {
        spMyClass2->SetName(iName);
        spMyClass2->SetAge(iAge);
        cout << "\nHello " << spMyClass2->GetName() << "! You are " << spMyClass2->GetAge() << " now!\n"<< endl;
    }
    // Note: SmartPtr will be destructed automatically once its scope ends.
}

/* Main Program */
int main()
{
    Greeting("Yogesh", 27);    
    return 0;
}
