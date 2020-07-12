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
int a[100002][11];
int main()
{
	int n,x,t;
	while(1)
	{
		scanf("%d",&n);
		if(n==0)
			return 0;
		int time=0,sum=0;
		memset(a,0,sizeof(a));
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&x,&t);
			if(time<t)time=t;
			a[t][x]++;
		}
		for(int i=time+1;i>0;i--)
		{
			for(int j=0;j<=10;j++)
			{
				if(j==10)
					a[i-1][j]+=max(a[i][j-1],a[i][j]);
				else if(j==0)
					a[i-1][j]+=max(a[i][j+1],a[i][j]);
				else
					a[i-1][j]+=max(a[i][j-1],max(a[i][j],a[i][j+1]));
			}
		} 
		printf("%d\n",a[0][5]);
	 } 
	return 0;
}
