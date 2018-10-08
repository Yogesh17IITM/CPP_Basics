/* C++ Inheritence */
#include<iostream>
using namespace std;
static int stCount=0;    // Notice static cannot be used inside class

class parent 
{
	int count=0;
	public:
		parent()    // constructor
		{
			++count;
			++stCount;    // Retains value even it goes out of the scope
			cout<<count<<" Parent constructor "<<stCount<<endl;
		}

		void Greet()
		{
			cout << "Parent" <<endl;
		}
};		

class first : public parent
{
	public:
		void Greet()
		{
			cout <<"first "<<endl;
		}
};

class second : private parent
{
	public:
		void Greet()
		{
			cout <<"second "<<endl;
		}
};

class third : public parent
{
	// Notice how function call happens
};

class multiple : public first, public second  // Multiple Inheritence
{
	public:
		multiple()
		{  cout<<"Multiple Constructor "<<endl;} 
};


int main()
{
	// Creating Objects for each class
	parent oParent;
	first oFirst;
	second oSecond;
	third oThird;
	cout<<"\n Multiple inheritence"<<endl;
	multiple oMultiple;

	// Func. call
	oParent.Greet();
	oFirst.Greet();
	oSecond.Greet();
	oThird.Greet();

	return 0;
}
