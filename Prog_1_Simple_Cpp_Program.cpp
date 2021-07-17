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
	string strTime = "12:20AM";	
	
	string strOut;
    string strHour = strTime.substr(0,2);    
	
	if(0 == strTime.compare(5, 2, "PM"))
	{		
        // Handle for 12:MMPM	
        if(0 != strTime.compare(0, 2,"12"))
        {
		    int Hour = ::stoi(strHour) + 12;
		    strHour = ::to_string(Hour);		
        }
	}
	else
	{
        // Handle for 12:MMAM
		if(0 == strTime.compare(0,2,"12"))
            strHour = "00";
	}
    strOut = strHour+strTime.substr(2,3);		        
    
	cout<<strOut<<endl;	
	return 0;
}

