/* Function Example */

/* Program for finding factorial 

   Input	    : Type a number for finding Factorial
   Exp. output	: Factorial of that given no.
*/

#include<iostream>
#include<exception>
using namespace std;

// Function Prototype
int fact(int x);

int main()
{
	int f, result;
	cout<<"Enter a number: "<<endl;
	cin>>f;

	result=fact(f);
	cout<<"The Factorial of "<<f<<" is : "<<result<<endl;
	return 0;
}

// Function Definition
int fact(int x)
{
	int i=1;
	int buff=1;

	if (x>0)
	{
		for(i=1;i<=x;i++)
		buff = i*buff;
	}
	else if(x==0)
	{
		buff =1;
	}
	else
	{
		cout << "Invalid Input Parameter"<<endl;
		return('\0');
	}
	return buff;
}
