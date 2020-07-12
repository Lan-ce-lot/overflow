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
int a[105][105],dp[105][105];
int main()
{
	int n,t;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&t);
		for(int i=0;i<t;i++)
		{
			for(int j=0;j<i+1;j++)
			{
				scanf("%d",&dp[i][j]);
			}
			
		}
		for(int i=t-1;i>0;i--)
		{
			for(int j=t-1;j>0;j--)
			{
				dp[i-1][j-1]+=max(dp[i][j],dp[i][j-1]);
			}
		}
		printf("%d\n",dp[0][0]);
	}
	return 0;

}
