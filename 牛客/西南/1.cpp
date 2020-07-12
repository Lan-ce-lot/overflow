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
	int a;
	scanf("%d",&a);
	if(a==1)
	printf("*****");
	else
	{
		for(int i=0;i<a;i++)
	{
		for(int j=0;j<i;j++)
			cout<<" ";
		puts("*****");
	 } 
	for(int i=a-1;i;i--)
	{
		for(int j=0;j<i-1;j++)
			cout<<" ";
		i==1?printf("*****"):puts("*****");
	}
	}
	
	return 0;
}
