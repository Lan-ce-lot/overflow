#include <iostream>
#include <string.h>
using namespace std;
const int maxn = 1e5 + 5;
int MAX_VALUE = 10, con = 0;
int next_[maxn];
void SegNum(int nSum, int* pData, int nDepth)
{
	if(nSum < 0)
		return;
 
	if(nSum == 0)
	{
		for(int j = 0; j < nDepth; j++) 
			cout << pData[j] << " ", con++;
		cout << endl;
 
		return;
	}
 
	int i = (nDepth == 0 ? next_[0] : pData[nDepth-1]);
	for(; i <= nSum;)
	{
		pData[nDepth++] = i;
		SegNum(nSum-i,pData,nDepth);
		nDepth--;
 
		i = next_[i];
	}
}
 
void ShowResult(int array[],int nLen)
{
	next_[0] = array[0];
	int i = 0;
	for(; i < nLen-1; i++)
		next_[array[i]] = array[i+1];
	next_[array[i]] = array[i]+1;
 	
	int* pData = new int [MAX_VALUE];
	SegNum(MAX_VALUE,pData,0);
	delete [] pData;
}
int num[5001];
int main()
{ 
	MAX_VALUE = 1;
	while (MAX_VALUE <= 30) {
		con = 0;
		int* array = new int[MAX_VALUE];
		for(int i = 0; i < MAX_VALUE; i++) {
			array[i] = i+1;
		}
		//ÕÒÁãÇ®²âÊÔ
		ShowResult(array,MAX_VALUE);
		num[MAX_VALUE ++] = con;
		
	}
	for (int i = 1; i <= 21; i++) cout << num[i] - 1 << endl;
	
	system("pause");
	return 0;
}

