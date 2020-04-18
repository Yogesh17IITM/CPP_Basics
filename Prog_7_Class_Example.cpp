/* 
Objective: 
	To Demonstrate C++ Class creation

Example:
	Calculating area of circle

Key Topics:
	1) C++ Class - Object creation and accessing members
	2) Usage of Manifest constants (#defines)
*/

// Std libraries
#include<iostream>
#include<cmath>

// Manifest constants
#define PI 4.0*atan(1.0)	

// Using directives
using namespace std;

// Class definitions
class area
{	
	public:
		double radius;			// Class members as variables
		double area, Circum;	// class members as variables

		// Note: You can also declare and/or define methods
};

/* Main Proram */
int main()
{
	area Circle;
	cout <<"Enter the radius of the circle: "<<endl;
	cin>>Circle.radius;

	/* Calc. area of circle */
	Circle.area=PI*Circle.radius*Circle.radius;

	/* Calc. circumference of circle*/
	Circle.Circum= 2.0*PI*Circle.radius;

	cout<<"Area: "<<Circle.area<<"\nCircumference: "<<Circle.Circum<<endl;
	return 0;
}
