/* 
	Printing subsequence of a given array [1,2,3,4]
	4
	3
	3 4
	2
	2 4
	2 3
	2 3 4
	1
	1 4
	1 3
	1 3 4
	1 2
	1 2 4
	1 2 3
	1 2 3 4
*/

#include<iostream>
#include<vector>
using namespace std;

void Print(vector<int> iArr)
{
	for (int idx = 0; idx < iArr.size(); idx++)
	{
		cout << iArr[idx] << " ";
	}
	cout << endl;
}

void PrintSubsequence(vector<int> iArr, int idx, vector<int> iSubArr)
{
	if (idx == iArr.size())
	{
		if(iSubArr.size() != 0)
			Print(iSubArr);
	}
	else
	{
		PrintSubsequence(iArr, idx + 1, iSubArr);
		iSubArr.push_back(iArr[idx]);
		PrintSubsequence(iArr, idx + 1, iSubArr);
	}
}

int main()
{
	vector<int> vecArr{ 1,2,3,4 };
	vector<int>	vecTemp;

	PrintSubsequence(vecArr, 0, vecTemp);

	return 0;
}