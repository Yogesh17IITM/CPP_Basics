/* CLASS Example */

/* Calculating area of circle */
#include<iostream>
#define Pi 3.14
using namespace std;

class area
{
	public:
		int radius;		// Class members as variables
		float area, Circum;	// class members as variables
};

int main()
{
	area Circle;
	cout <<"Enter the raidus of the circle: "<<endl;
	cin>>Circle.radius;

	/* Calc. area of circle */
	Circle.area=Pi*Circle.radius*Circle.radius;

	/* Calc. circumference of circle*/
	Circle.Circum= 2.0*Pi*Circle.radius;

	cout<<"Area: "<<Circle.area<<"\nCircumference: "<<Circle.Circum<<endl;
	return 0;
}
