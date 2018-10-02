/* Demonstation of Tenary Operator */
#include<iostream>

int main()
{
	int x = 5; 		// Try with any negative value
	int var=100;
	
	/* Using If.. else..*/
	if (x>0)
		var=1;
	else
		var=0;
	
	std::cout<<"Var is: "<<var<<std::endl;
	

	var=100;		// Resetting the same variable

	/* Using Tenary operator */
	var = (x>0)? 1 : 0;	// <Condition>? <TRUE statement> : <FALSE statement>
	std::cout<<"Var is: "<<var<<std::endl;

	return 0;
}
