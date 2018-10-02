/* Strings */

/* String Increment */
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string para, line;
	int shft = 1;		// Incrementation length
	int i = 0;		
	int buff=0;
	
	cout<<"Enter a Sentence"<<endl;
	do
	{
		getline(cin,line);
		para += line;
	}
	while(line != "");
	cout <<"Your sentence is: "<<para<<endl;

	for(i=0;i<para.size();i++)
	{
		if(para[i] != ' ' && (isalpha(para[i]) || isdigit(para[i])) )
		{
			para[i] = para[i]+shft;
		}		

		if( (islower(para[i]-shft)) && (para[i]>'z') )
		{
			buff = (para[i]-'z')-1;	
			para[i] = 'a'+buff;
		}
		else if( (isupper(para[i]-shft)) && (para[i]>'Z'))
		{
			buff = (para[i]-'Z')-1;
			para[i] = 'A'+buff;
		}
		else
		{
			//exit(0);
		}		
	}
		
	cout<<para<<endl;
	return 0;
}
