/* Pointer and Objects */
#include<iostream>
using namespace std;

class Time
{
	short int hh, mm, ss;
	public:
	Time()    // Constructor
	{
		hh = mm = ss = 0;
	}

	void getData(int i, int j, int k)
	{
		hh = i;
		mm = j;
		ss = k;
	}

	void printData(void)
	{
		cout<<"\n Time is "<<hh<<":"<<mm<<":"<<ss<<endl;
	}
};

int main()
{
	Time T, *T_ptr;
	T_ptr = &T;           // Assigning address of obj. to obj. pointer (mthd 1)
	Time *T_ptr1 = &T;    // Assigning address of obj. to obj. pointer (mthd 2)
	
	cout<<"Initialize data members using the obj."<<endl;
	T.getData(12,22,11);

	cout<<"Printing members using obj."<<endl;
	T.printData();

	cout<<"\nInitialize data members using the obj. pointer"<<endl;
	T_ptr->getData(01,23,11);

	cout<<"Printing members using obj. pointer"<<endl;
	T_ptr->printData();

	cout<<"\nInitialize data members using the obj. pointer"<<endl;
	T_ptr1->getData(02,12,10);

	cout<<"Printing members using obj. pointer"<<endl;
	T_ptr1->printData();
	return 0;
}


