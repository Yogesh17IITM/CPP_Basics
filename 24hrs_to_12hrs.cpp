/* This Program demonstrates how to convert time from 24 hrs format into 12 hrs format
   Author:  Yogeshwaran R
*/
#include<iostream>
#include<string>
using namespace std;
int main()
{
  string cur_time;
  cout<<"Program for converting 24 int0 12 hrs format \n"<<endl;
  cout<<"Enter time in 24 hrs format (HH:MM hrs): "<<endl;
  cout<<"For eg: 19:00 hrs"<<endl;
  getline(cin,cur_time);

  int hours24 = stoi(cur_time);
  int i;
  if(cur_time.compare(5,8," hrs")==0)
  {
    if(hours24>=12 && hours24<24)
    {
      if(hours24==12)
      {
        for(i=0;i<5;i++)
        {
          cout<<cur_time[i];
        }
      }
      else
      {
        cout<<hours24-12;
        for(i=2;i<5;i++)
        {
          cout<<cur_time[i];
        }
      }
      cout<<" PM"<<endl;
    }
    else if(hours24>=0 && hours24<12)
    {
      if(hours24==0)
      {
        cout<<12;
        for(i=2;i<5;i++)
        {
          cout<<cur_time[i];
        }
      }
      else
      {
        for(i=0;i<5;i++)
        {
          cout<<cur_time[i];
        }
      }
      cout<<" AM"<<endl;
    }
    else
    {
      cout<<"Invalid Input"<<endl;
    }
  }
  else
  {
    cout<<"Invalid Input"<<endl;
  } 
}
