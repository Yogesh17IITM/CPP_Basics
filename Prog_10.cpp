/* Strings */

/* String in Reverse order */
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string name;
	int i;
	
	cout<<"Enter your name: "<<endl;
	cin>>name;
	
	cout<<"You name in reverse is: ";
	for(i=name.size()-1;i>=0;i--)
	{
		cout<<name[i];
	}
	cout<<endl;	
}
