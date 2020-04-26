/* 
Objective:
	To demonstrate default parameters and function overloading

Example:
	Converting lowercase into UPPERCASE

Key Topics:
	1) Function - calling with Default parameter(s)
*/

// Std Libraries
#include<iostream>

// The 'Using' directives
using namespace std;

// Function Prototype (with default formal parameter)
void ConvertLowerIntoUpperCase(char * ipChar = NULL);
int add(int a, int b = 10, int c = 20);		// Here 'b' and 'c' are Default parameters
/* Note: 
	1) Default parametering happens from right to left.
	   So, it is always recommended to keep default params at the right and non-default param at the left
	2) This function can also be created using funciton overloading
		(a) add(int)
		(b) add(int, int)
		(c) add(int, int, int)
		But here, instead of creating three functions, creating a function with default args
		will be efficient
*/

/* Main Program */
int main()
{
	char name[20];
	char *ptr;
		
	cout<<"Enter your name: "<<endl;
	cin >> name;
	ptr = name;

	// Display Name
	ConvertLowerIntoUpperCase(ptr);			// ptr = actual parameter	
	if(ptr)
	{
		/*Note: Here ptr is NOT null. That is, actual parameter is not affected*/
		cout <<"Hello "<<ptr<<endl;	
	}
	else
	{
		cout<<"Invalid Input !!!"<<endl;
	}	

	// Demonstrating the usage of Default parameter
	cout <<"1: Sum is "<<add(100)<<endl;
	cout <<"2: Sum is "<<add(100, 200)<<endl;
	cout <<"3: Sum is "<<add(100, 200, 300)<<endl;
}

/* Function definitions */
void ConvertLowerIntoUpperCase(char * ipChar)
{
	if (ipChar)
	{
		for(;(*ipChar!='\0');ipChar++)	
		{
			if(*ipChar>='a' && *ipChar<='z')
			{
				*ipChar = *ipChar - 32;		// Modifying pointer value
			}
		}
	}

	// Note:
	// 1) Changing the poiner 'ipChar' (formal parameter) to NULL will NOT affect the actual parameter 'ptr'
	// 2) But, modifying the pointer value will affect the actual parameter
	ipChar = NULL;

	// Note: To modify 'ipChar', you may use double pointer!
}

int add(int a, int b, int c) {return (a+b+c);}
