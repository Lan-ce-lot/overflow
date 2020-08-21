#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<algorithm> 
using namespace std;
typedef long long ll;
#define PI 3.1415927
#define M(a) memset(a,0,sizeof(a))
const int INF=0x3f3f3f3f;
int main()
{
	int a[10]={1,2,10,4,1,6,7,8,9,1};
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9-i;j++)
		{
			if(a[j]>a[j+1])
			{
				int t=a[j];
				a[j]=a[j+1] ;
				a[j+1]=t;
			}
		}
	}
	for(int i=0;i<10;i++)
	{
		cout<<a[i]<<endl;
	}
	return 0;

}
