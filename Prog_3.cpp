/* FUNCTTION EXAMPLES */

/* This is program for displaying greetings 

   welcome() is a function definition
   with char pointer as an argument.

   Input		: Type your name
   Expected outout	: Greetings with your name 
			  in UPPERCASE	
*/

#include<iostream>

using namespace std;
int welcome(char *var);		// Function prototype

int main()
{
	char name[20];		// Character array
	char *ptr;		// Character pointer

	cout<<"Enter your name: "<<endl;
	cin >> name;
	ptr = name;		// Storing address of name[0] 

	welcome(ptr);		// Function call
	cout <<name<<endl;	
}

/* Function for converting lowercase into UPPERCASE */
int welcome(char *var)
{
	for(;(*var!='\0');var++)
	{
		if( (*var>='a') && (*var<='z') )
		{
			*var = *var-32;
		}
	}
	cout << "welcome, ";	
}
