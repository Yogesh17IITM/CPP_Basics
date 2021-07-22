/*
Print Fibonacci series
Series:    0 1 1 2 3 5 8 13 21 34 ...
Index :    0 1 2 3 4 5 6  7  8  9 ..

Mathematical Expression:
    F0 + F1 = F2
    F1 + F2 = F3
    ..
    and so on

In general,
    F(n-2) + F(n-1) = F(n)
*/

#include<iostream>
using namespace std;

// Using Recursive - bad approach
int FibonacciAtIdxUsingRecursive(const int & iNum)   // F(n)
{
    if(iNum <= 1)
        return iNum;
    return FibonacciAtIdxUsingRecursive(iNum-2) + FibonacciAtIdxUsingRecursive(iNum-1); // F(n-2) + F(n-1)
}

int FibonacciAtIdx(const int & iNum)
{
    int oResult = 0;

    int first = 0;
    int second = 1;

    if(iNum == 1)
        oResult = first;
    else if(iNum == 2)
        oResult = second;
    else
    {        
        for(int idx=2; idx<=iNum; idx++)
        {
            oResult = first + second;
            first = second;
            second = oResult;
        }       
    }   
    return oResult;
}

int main()
{    
    cout <<FibonacciAtIdx(6)<<endl;
    cout <<FibonacciAtIdx(9)<<endl;
    return 0;
}