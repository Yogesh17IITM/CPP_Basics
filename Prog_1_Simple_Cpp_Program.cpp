/* Simple C++ Program */

/* Program for converting 12 hrs format into 24 hrs format 
   Input	: Time in HH:MM AM/PM
   Output	: Equivalent time in 24 hrs format   
*/
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string time;
	int hr=1000;
	int i=1000;
	
	cout<<"Enter the time in HH:MM(AM/PM) format. Eg.12:20PM"<<endl;
	cin>>time;
    	hr = std::stoi(time); 
    
	if(time.compare(5,6,"AM") == 0)
	{
		if(hr!=12)
		{
		    cout<<hr;
		}
		else if(hr==12)
		{
		    cout<<"00";
		}
		else
		{
		    cout<<"Invalid input"<<endl;
		}
	}
	else if(time.compare(5,6,"PM") == 0)
	{
	    if(hr!=12)
	   	    cout<<hr+12;
	   	else if(hr==12)
	   	    cout<<hr;
	   	else
	   	    cout<<"Invalid input"<<endl;
	}
	else
	{
	    	cout<<"Invalid input"<<endl;
	}
	
	for(i=2;i<5;i++)
	{
       	cout<<time[i];    
    }
	cout<<" hrs"<<endl;    
	return 0;
}

