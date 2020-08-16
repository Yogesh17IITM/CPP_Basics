/* 
Objective:
	To demonstrate CPP Constructors and destructor concepts

Example:
	Print string in Reverse

Key Topics:
    1) Constructor
    2) Destructor
    3) Stack Concepts

Notes:
    NA
*/
#include <iostream>
#include <vector>

using namespace std;

/* Stack Class */
class Stack
{
    // Data Members
    char * _pStr;
    int _Top;
public:   

    // Constructor/ Destructor doesn't return any value
    Stack();            // Default Constructor  
    Stack(int iSize);   // Parameterized Constructor
    ~Stack();           // Destructor

    // Methods
    void push(char x);
    void pop();
    char top();
    int empty();
private:
};

/* MAIN PROGRAM */
int main()
{   
    vector<Stack> StackList;

    Stack objStack;         // Object Created here (Object life starts here)
    char str[5] = "ABCD";
    for (int idx = 0; idx < 5; idx++)
    {
        objStack.push(str[idx]);
    }

    Stack objStackNew(6);  // Object Created here (Object life starts here)  
    char strnew[6] = "Hello";
    for (int idx = 0; idx < 6; idx++)
    {
        objStackNew.push(strnew[idx]);
    }

    StackList.push_back(objStack);
    StackList.push_back(objStackNew);

    // Reverse String
    for (int idx=0; idx<StackList.size(); ++idx)
    {
        while(!StackList[idx].empty())
        {
            cout<<StackList[idx].top();
            StackList[idx].pop();
        }    
        cout<<endl;
    }

    // objStack life ends here
    return 0;
}

// Class Member Definition
Stack::Stack() : _pStr(new char[5]), _Top(-1) // Initializing data members of class
{
    cout <<"Default Constructor"<<endl;
}
Stack::Stack(int iSize) : _pStr(new char[iSize]), _Top(-1) // Initializing data members of class
{
    cout <<"Parameterized Constructor"<<endl;
}
Stack::~Stack() 
{      
    //delete _pStr; 
    cout <<"Destructor"<<endl;
}
void Stack::push(char x) {_pStr[++_Top] = x;}
void Stack::pop() {_Top--;}
char Stack::top() {return _pStr[_Top];}
int Stack::empty() {return (_Top == -1);}