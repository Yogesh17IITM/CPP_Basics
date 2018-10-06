/* This program demonstrates how the access specifier works */
#include<iostream>
using namespace std;

class ScopeTest
{
	/* Uncomment the below part and compile again */
//	private:
	//	int x=20;
	public: 
		int x=10;
		ScopeTest()
		{
		    cout<<"X = "<<x<<endl;    
		}
};

int main()
{
	ScopeTest Obj;
        return 0;
}
