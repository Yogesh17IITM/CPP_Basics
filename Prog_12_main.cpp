/* Demonstration of the 'extern' storage class 
   'extern' is used to declare a global variable or function in another file.

   To compile, linking should be done as follows
   g++ <main_function.c> <external_func1.c> ..
*/
#include<iostream>

/* Global Declaration*/
int count=0;			// Variable declaration
extern void DispCount();	// Function declarataion/prototype

/* Main function */
int main()
{
	count = 5;		// Variable initialized in local scope
	DispCount();		// External function for displaying count
	return 0;
}

