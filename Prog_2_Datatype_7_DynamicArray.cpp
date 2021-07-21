/* Example of Dynamic Array */

#include<iostream>
using namespace std;

void ResizeArray(int *& ioArr, int  & ioCurrSize)
{
   if(ioArr != nullptr)
   {
       int newSize = 2 * ioCurrSize;
       int * iNewArr = new int[newSize];
       
       // copy all the elements (upto size = ioCurrSize)
       memcpy(iNewArr, ioArr, ioCurrSize * sizeof(int));
       
       // fill remaining with default value "-1"       
       for(int idx=ioCurrSize; idx<newSize; idx++)
           iNewArr[idx] = -1;
       
       // update size
       ioCurrSize = newSize;
       delete[] ioArr;
       ioArr = iNewArr;
   }
}

int main()
{
    int size = 3;
    int * Arr = new int[size]{1,2,3};
    
    ResizeArray(Arr, size);   
    
    cout<<"Array Size: "<<size<<endl;
    for(int idx=0; idx<size; idx++)
        cout<<Arr[idx]<<" ";
    cout<<endl;
    
    return 0;
}