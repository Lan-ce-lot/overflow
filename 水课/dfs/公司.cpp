#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<algorithm> 
#include<vector> 
using namespace std;
int a[15][15];
bool vis[15];
int sum=2000000,n;
void dfs(int x,int t)
{
	if(x==n)
	{
		sum=min(sum,t);
		return;
	}
	for(int i=0;i<n;i++)
	{
		if(!vis[i])
		{
			vis[i]=true;
			dfs(x+1,t+a[x][i]);
			vis[i]=false;
		}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&a[i][j]);
		dfs(0,a[0][0]);		
	printf("%d",sum);
}
