/* This program demonstrates how the access specifier works 
 * Note: Compilation will be unsuccessful. 
 *       Understand and try debugging. */
#include<iostream>
using namespace std;

class ScopeTest
{
	/* Notice the 'redclaration' error encountered */
	private:
		//int x=20;
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
