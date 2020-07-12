#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<algorithm> 
#include<vector>
using namespace std;
typedef long long ll;
#define PI 3.1415927
#define M(a) memset(a,0,sizeof(a))
const int INF=0x3f3f3f3f;
int ans[100005] ;
bool f[100005];
vector<int> son[100005];
int dfs(int u)
{
	int ret=0;
	for(int i=0;i<son[u].size();i++)
	{
		ret+=dfs(son[u][i]);
	}
	ans[u]=ret;
	return ret+1;
}
int main()
{
	int n,x,y,u;
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
	{
		scanf("%d%d",&x,&y);
		son[x].push_back(y);
		f[y]=true;
	}
	for(int i=1;i<=n;i++)
	{
		if(!f[i])
		{
			u=i;
			break;
		}
		
		
	}
	dfs(u);
	for(int i=1;i<=n;i++)
	{
		printf("%d\n",ans[i]);
	}
	return 0;
}
