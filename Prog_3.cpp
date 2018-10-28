/* FUNCTTION EXAMPLES */

/* This is a program displaying greeting message both in 
 * Upper and Lower case.
 *
 * Description:
 *         The function 'is a function definition
 *         with char pointer as an argument.
 *
 * Input		: Enter your name
 * Expected outout	: Greetings with your name 
 *                        in UPPERCASE	
*/
#include<iostream>
using namespace std;

/* Function prototypes */
void GreetMsgUpper(char *ptrUpper);    
void GreetMsgLower(char *ptrLower);

/* Main Function */
int main()
{
	/* Variables declaration */
	char name[20];		

	cout<<"Enter your name: "<<endl;
	cin >> name;

	/* Call GreetMsgUpper() to display greet msg
	 * in Upper case */
	GreetMsgUpper(name);
	cout <<"\n Hello, "<<name<<", this is Upper case"<<endl;

	/* Call GreetMsgUpper() to display greet msg
	 * in Lower case */
	GreetMsgLower(name);
	cout <<"\n Hi, "<<name<<", this is Lower case"<<endl;

	return 0;
}

/* Description:
 *        Function GreetMsgUpper() displays greet msg in 
 *        Upper case 
 */
void GreetMsgUpper(char *ptrUpper)
{
	for(;(*ptrUpper!='\0');ptrUpper++)
	{
		if( (*ptrUpper>='a') && (*ptrUpper<='z') )
		{
			*ptrUpper = *ptrUpper-32;
		}
	}
}

/* Description:
 *        Function GreetMsgLower() displays greet msg in 
 *        Lower case 
 */
void GreetMsgLower(char *ptrLower)
{
	for(;(*ptrLower!='\0');ptrLower++)
	{
		if( (*ptrLower>='A') && (*ptrLower<='Z') )
		{
			*ptrLower = *ptrLower+32;
		}
	}
}
