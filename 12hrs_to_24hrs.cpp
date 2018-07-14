/* This Program dmonstrates how to convert time from 12 hrs format into 24 hrs format
   Author:  Yogeshwaran R
*/
#include<iostream>
#include<string>
using namespace std;

int main()
{
  string cur_time;
  cout<<"Program for converting time from 12 into 24 hours format  \n";
  cout<<"Enter the time (HH:MM(AM/PM)): "<<endl;
  cout<<"For eg., 07:20AM"<<endl;
  getline(cin,cur_time);

  if(cur_time.compare(5,6,"PM")==0)  // Comparing characters from 5 to 6 of string "cur_time" with the characters existing within double quotes i.e "AM"
  {
    int hours = stoi(cur_time);
    int i;
    if(hours==12)
    {
      for(i=0;i<cur_time.length()-2;i++)
      {
        cout<<cur_time[i];
      }
    }
    else if(hours>12)
    {
      cout<<"Invalid Input"<<endl;
      exit(0);
    }
    else
    {
      cout<<hours+12;
      for(i=2;i<cur_time.length()-2;i++)
      {
        cout<<cur_time[i];
      }
    }
  }
  else if(cur_time[5]=='A' && cur_time[6]=='M') // Alternative way of comparing strings
  {
    int hours = stoi(cur_time);
    int i;
    if(hours==12)
    {
      cout<<0<<0;
      for(i=2;i<cur_time.length()-2;i++)
      {
        cout<<cur_time[i];
      }
    }
    else if(hours>12)
    {
      cout<<"Invalid Input"<<endl;
      exit(0);
    }
    else
    {
        for(i=0;i<cur_time.length()-2;i++)
        {
          cout<<cur_time[i];
        }
    }
  }
  else
  {
    cout<<"Invalid Input"<<endl;
    exit(0);
  }
  cout<<" hrs"<<endl;
  return 0;
}
