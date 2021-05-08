/*  
    Program for demonstrating increment of characters in strings

    Input: Sentence, incremental index
    Output: Sentence with each characted incremented by given index.
    
    Author: Yogesh
*/
#include <iostream>
#include <string>
using namespace std;
int main ()
{
  string sentence;
  int h, hnew;
  cout<<"Type any sentence/paragraph (without punctuations): "<<endl;
  cout<<"Note: Do not press the key 'Enter' until you finish the paragraph"<<endl;
  getline(cin,sentence);
  cout<<"\n Enter the incremental index:"<<endl;
  cin>>h;
  cout<<"Your sentence/paragraph is: \n "<<sentence<<"\n"<<endl;

  for(int i=0;i<sentence.length();i++)
  {
    if(sentence[i]!=' ')
    {
      if(isalpha(sentence[i]) || isdigit(sentence[i]))
      {
        sentence[i] = sentence[i] + h;
        if(sentence[i]>'z' && islower(sentence[i]-h))
        {
          hnew = (sentence[i]-'z')-1;
          sentence[i] = 'a'+hnew;
        }
        else if (sentence[i]>'Z' && isupper(sentence[i]-h))
        {
          hnew = (sentence[i]-'Z')-1;
          sentence[i] = 'A'+hnew;
        }
      }
      else
      {
        cout<<"ERROR: INVALID INPUT"<<endl;
        exit(0);
      }
    }
  }
  cout <<sentence<<endl;
}
