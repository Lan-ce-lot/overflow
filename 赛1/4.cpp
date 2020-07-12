#include<bits/stdc++.h> 

using namespace std;

int m,n,map1[105][105],ans=0;
int vis[105][105];

int main()
{
	memset(map1,-0x3f3f3f3f,sizeof(map1));
	scanf("%d%d",&m,&n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d",&map1[i][j]);
		}
	}
	for(int i=n;i>0;i--)
	{
		for(int j=m;j>0;j--)
		{
			map1[i-1][j-1]+=max(map1[i][j-1],map1[i-1][j]);
			printf("%d ",map1[i-1][j-1]);
		}
	}
	printf("%d\n",map1[0][0]);
	return 0;

}
