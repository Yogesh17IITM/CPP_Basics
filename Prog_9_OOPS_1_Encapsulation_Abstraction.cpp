/*
Objective:
    To Demonstrate C++ Class Encapsulation (Binding data with member)

Example:
    Calculating area and circumference of circle

Key Topics:
    1) C++ Class - Object creation and accessing members
    2) Constructor and Destructor
    3) Usage of Manifest constants (#defines)
    4) Access specifiers (public , private (default))
*/

// Std libraries
#include <iostream>
#include <cmath>

// Manifest constants
#define PI 4.0 * atan(1.0)

// Using directives
using namespace std;

// Class definitions
class Geometry2D
{
    // Members are private by default (accessed only by the methods of this class.)
    // Note: In Structure, members are public by default.
    double _Area;
    double _Circum;
    double _Radius;

public:
    // Methods/Behavior/Functions
    Geometry2D(){};
    Geometry2D(double iRadius) : _Radius(iRadius){}; // Constructor with arguments
    ~Geometry2D() {}

    void CalcArea() { _Area = PI * (_Radius * _Radius); }
    void CalcCircumference() { _Circum = 2. * PI * _Radius; }

    void SetRadius(const double &iRadius) { _Radius = iRadius; }

    double GetArea() const { return _Area; }
    double GetCircumference() const { return _Circum; }
};

/* Main Proram */
int main()
{
    Geometry2D Circle_A(2.0);
    Circle_A.CalcArea();
    Circle_A.CalcCircumference();
    cout << "Area: " << Circle_A.GetArea() << "\nCircumference: " << Circle_A.GetCircumference() << endl;

    Geometry2D Circle_B;
    Circle_B.SetRadius(3.0);

    Circle_B.CalcArea();
    Circle_B.CalcCircumference();
    cout << "Area: " << Circle_B.GetArea() << "\nCircumference: " << Circle_B.GetCircumference() << endl;

    return 0;
}
