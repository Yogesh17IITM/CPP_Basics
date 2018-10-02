/* Function Example */

/* Program for finding sum of 'N' natural numbers */

#include<iostream>
using namespace std;
int sum(int x);

int main()
{
	int a, result;
	cout<<"Enter a number"<<endl;
	cin>>a;
	result=sum(a);
	cout <<"The sum upto "<<a<<" is: "<<result<<endl;
	return 0;
}

int sum(int x)
{
	return 0.5*x*(x+1);
}

