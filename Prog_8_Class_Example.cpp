/* 
Objective: 
	To Demonstrate C++ Class creation

Example:
	Calculating area of circle

Key Topics:
	1) C++ Class creating and accessing member variables
	2) Manifest constants (#defines) Vs Natural Constants (const)
	3) Defining method
*/

// Std libraries
#include<iostream>
#include<cmath>
#include<string>

// Using directives
using namespace std;

// Manifest constants
#define SUCCESS 0
#define FAIL 100

// Natural Constants
const double CONST_PI  = 4.0 * atan(1.0);

// Method
double GetDoubleParam(const string & istrParamName) 
{
	double oRetVal;
	cout<<"Enter "<<istrParamName<<endl;
	cin >> oRetVal;
	return oRetVal;
}

class CalculateArea
{
	/* Note: Members are Private by default */
	double _radius = 0.0;	
	
	public:
	/* Class members as Functions */

		// Set Methods
		void SetRadius(const double &iRadius) { _radius = iRadius; }

		// Get Methods
		double GetArea() const { return CONST_PI * _radius * _radius; }
		double GetCircumference() const { return 2 * CONST_PI * _radius; }
};

int main()
{
	int rc = FAIL;

	CalculateArea Circle;
	int radius = GetDoubleParam("radius");			

	// Call Set Methods
	Circle.SetRadius(radius);

	if(0 < radius)
		rc = SUCCESS;

	// Call Get Methods	
	double area;

	if(SUCCESS == rc)
	{
		if (0 < (area = Circle.GetArea()))
		{
			cout << "Area : " << area << endl;
			rc = SUCCESS;
		}

		double Circumference;
		if (0 < (Circumference = Circle.GetCircumference()))
		{
			cout << "Circumference : " << Circumference << endl;
			rc = SUCCESS;
		}
	}
	
	return rc;
}

