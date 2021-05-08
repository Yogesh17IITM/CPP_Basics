/* Size of various Data Types */

#include<iostream>
#include<string>
using namespace std;

int main()
{
	typedef int Alias_int;	// Demonstration of 'typedef'
	cout<<"Size of char: "<< sizeof(char) <<endl;
	cout<<"Size of int: "<< sizeof(int) <<endl;
	cout<<"Size of Alias_int: "<<sizeof(Alias_int) <<endl;
	cout<<"Size of float: "<< sizeof(float) <<endl;
	cout<<"Size of double: "<< sizeof(double) <<endl;
	cout<<"Size of string: "<< sizeof(string) <<endl;

	return 0;
}
