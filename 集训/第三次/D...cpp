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
const int INF=0x3f3f3f3f;
int main()
{
	int n,a,b,flag=1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=2;j*i<n;j++)//a=j*i;b=i;a/b=j;
		{
			if(j*i*i>n)
			{
				flag=0;
				a=j*i;b=i;
				break;
			}	
		}
	}
	flag?printf("%d %d",a,b):printf("-1");
	return 0;
}
