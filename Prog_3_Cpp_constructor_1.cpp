#include<iostream>
#include <cmath>

using namespace std;

class Complex
{
    double _Re, _Im;
    double ComputeNorm() {return sqrt((_Re * _Re) + (_Im * _Im));}

public:
    // Constructor with default values 
    Complex(double iRe = 0.0, double iIm = 0.0) : _Re(iRe), _Im(iIm) 
    {
        /* Note : Here ": _Re(iRe), _Im(iIm)" --> Initialization list
                  The same initialisation can also be done in the body of the constructor.
                  The top to bottom approach mechanism might not guarantee
                  the order which initialization happens (since initialization order matters)

                  However, if we do the same initialization using initialization list, the order
                  is UNIQUIFIED. It will initialize the data member based on the order of data members
                  defined in this class (in this case _Re (first) and then _Im (Second)). 
                  It is critical to aware that the order in which the data member is created.
        */
        cout<<"Default Constructor called. Re: "<<_Re<<" Im: "<<_Im<<endl;
    }
    ~Complex() 
    {
        cout<<"Destructor called. Re: "<<_Re<<" Im: "<<_Im<<endl;
    }
    void PrintResult()
    {
        cout<<"|"<<_Re<<"+i"<<_Im<<"| = "<<ComputeNorm()<<endl;
    }
};

// Global object of class
Complex GlobalObj(10.0, 11.0);  // Static (Global) Object
                                // Constructed before main Starts
                                // Destructed after main ends

int main()
{
    cout << "Main Starts" << endl;

    // Creating Local Objects of class
    // Format 1
    Complex obj1(1.1,3.4); 

    // Format 2 (style of list initialization)
    Complex obj2 = {2.2, 4.5};

    Complex obj3;

    obj1.PrintResult();
    obj2.PrintResult();
    obj3.PrintResult();
    GlobalObj.PrintResult();

    cout << "Main Ends" << endl;
    return 0;   // D'tor called at this point where scope of "Complex" class ends. 
                // C++ class destructor follows LIFO for destroying objects.
                // (i.e.,) First obj deleted last and last created deleted first.
}
// Global Obj destroyed after main ends