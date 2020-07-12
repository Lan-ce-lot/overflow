#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int s[1005];
int dp[1005];
int main()
{
	int n;
	while(scanf("%d",&n)&&n)
	{
		memset(dp,0,sizeof(dp));
		for(int i=0;i<n;++i)
		  scanf("%d",&s[i]);
		dp[0]=s[0];
		int maxn=s[0];
		for(int i=1;i<n;++i)
		{
			for(int j=0;j<i;++j)
			{
				if(s[i]>s[j])
				  dp[i]=max(dp[i],dp[j]+s[i]);
			}
			dp[i]=max(dp[i],s[i]);
			maxn=max(maxn,dp[i]);//
		}
		printf("%d\n",maxn);
	}
	return 0;
}
