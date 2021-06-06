#include<iostream>
using namespace std;

void PrintSubsequence(int iArr[], int iSize)
{
	for (int idx = 0; idx < iSize; idx++)
	{
		for (int jdx = idx; jdx < iSize; jdx++)
		{
			for (int kdx = idx; kdx <= jdx; kdx++)
			{
				cout << iArr[kdx]<<" ";
			}
			cout << endl;
		}		
	}
}

int main()
{
	int arr[] = { 1,2,3,4 };
	int size = sizeof(arr) / sizeof(arr[0]);
	PrintSubsequence(arr, size);
	return 0;
}