#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int dp[105][105];
int main()
{
	int c;
	scanf("%d",&c);
	while(c--)
	{
		int n;
		scanf("%d",&n);
		memset(dp,0,sizeof(dp));
		for(int i = 0;i < n;i++)
			for(int j = 0;j <= i;j++)
				scanf("%d",&dp[i][j]);
		for(int i = n - 1;i > 0;i--)
			for(int j = n - 1;j > 0;j--)
				dp[i - 1][j - 1] += max(dp[i][j],dp[i][j - 1]);
		printf("%d\n",dp[0][0]); 
	}
	return 0;
} 

