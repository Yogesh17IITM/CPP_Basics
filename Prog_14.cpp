/* The 'dot (.)' and 'arrow (->) operator */

/* 
   Following key areas are covered
   1) A simple program demonstrates the usage of strcpy() and strcmp().
   2) Structure definition and variable declaration.
   3) Pointer to the variable of a structure (*male_ptr).
   4) New Pointer declaration to a structure (*female_ptr).     		
*/

#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	/* Local Structure Definitions */
	struct Employee
	{
		char name[20];			// Should be large enough to store the data
		int age;		
	} gender;	
	
	/* Local Declarations */
	Employee *male_ptr = &gender;		/* Declaring a pointer to the structure "Employee" and 
					   	   the address of the variable "gender" to it */
	Employee *female_ptr = new Employee();  // Declaring another pointer to a structure "Employee"
	char yourName[20];	
	char ipGender[5];

	cout<<"Specify your gender (male/female): "<<endl;
	cin>>ipGender;
	cout<<"Enter your name: "<<endl;
	cin>>yourName;
	cout<<"Enter your age: "<<endl;
	cin>>gender.age;

	strcpy(gender.name,"MyComputer");
	cout<<"Welcome to "<<gender.name<<endl;

	if (strcmp(ipGender,"male")==0)
	{
		strcpy(male_ptr->name,yourName);// Notice here 'gender.name' has been overwritten
		male_ptr->age = gender.age;
		cout<<"Hello Mr."<<gender.name<<", you are "<<male_ptr->age<<" now!"<<endl;
	}
	else if (strcmp(ipGender,"female")==0)
	{
		strcpy(female_ptr->name,yourName);
		cout<<"Hello Ms."<<gender.name<<", you are "<<female_ptr->age<<" now!"<<endl;
		// Notice here the 'gender.name' is NOT overwritten because the address is different
	
		strcpy(gender.name,female_ptr->name);
		female_ptr->age = gender.age;
		cout<<"Oops! Sorry wrong details. Please check the details now"<<endl;
		cout<<"Hello Ms."<<gender.name<<", you are "<<female_ptr->age<<" now!"<<endl;
	}
	else
	{
		cout<<"Invalid gender details !"<<endl;
	}

	return 0;
}
