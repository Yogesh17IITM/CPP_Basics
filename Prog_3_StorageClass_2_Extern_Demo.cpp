/* Demonstration of the 'extern' storage class */
#include<iostream>

extern int count;

void DispCount()
{
	std::cout <<"Count is: "<<count<<std::endl;	
}
