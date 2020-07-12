#include<bits/stdc++.h> 

using namespace std;
int dp[105][105],a[105][105];	int m,n,way=1;
int dfs(int x,int y)
{
	if(x<0||y<0||x>=m-1||y>=n-1)
	return 0;
	if(dp[x][y+1]>dp[x+1][y])
	{
		dfs(x,y+1);
	}
	if(dp[x][y+1]<dp[x+1][y])
	{
		dfs(x+1,y);
	}
	if(dp[x][y+1]==dp[x+1][y])
	{
		dfs(x+1,y);
		dfs(x,y+1);
		way++;
	}
}
int main()

{
	for(int i=0;i<105;i++)
	{
		for(int j=0;j<105;j++)
		{
			dp[i][j]=-505;
		}
	}

	scanf("%d%d",&m,&n);
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&dp[i][j]);
			a[i][j]=dp[i][j];
		}
	}
	
	for(int i=m;i>0;i--)
	{
		for(int j=n;j>0;j--)
		{
			if(j==n&&i==m)
				continue;
			dp[i-1][j-1]+=max(dp[i][j-1],dp[i-1][j]);
		}
	}
	dfs(0,0);
	printf("%d %d\n",dp[0][0],way)	;
	return 0;

}
