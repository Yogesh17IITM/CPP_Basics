/* Class Example */

/* Calculating area of circle */
#include<iostream>
#define PI 3.14
using namespace std;
class area
{
	/* Private Class members as Variables */
	int radius;			
	float area, circum;
	
	public:
	/* Class members as Functions */
		void getRadius()
		{
			cout << "Enter the radius: "<<endl;
			cin>>radius;			
		}

		void CalcArea()
		{
			area = PI*radius*radius;
			cout << "Area is: "<<area<<endl;
		}

		void calcCircum()
		{
			circum = 2*PI*radius;	
			cout << "Circumf. is: "<<circum<<endl;
		}
};

int main()
{
	area Circle;
	Circle.getRadius();
	Circle.CalcArea();
	Circle.calcCircum();
	return 0;
}

