/* Converting lowercase into UPPERCASE */

#include<iostream>
using namespace std;
main()
{
	char name[20];
	char *ptr;

	cout <<"Enter your name (in lower case)"<<endl;
	cin >> name;
	ptr = name; 	// Passing address of first element

	for(;(*ptr!='\0');ptr++)	
	{
		if(*ptr>='a' && *ptr<='z')
		{
			*ptr = *ptr - 32;		
		}
	}

	cout << "Welcome, "<<name<<endl;
}
