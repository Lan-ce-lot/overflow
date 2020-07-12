#include<bits/stdc++.h>//路径压缩 
using namespace std;
#define MAX_N 10000
int par[MAX_N];
int rank[MAX_N];//树高度 
void init(int n)//初始化 
{
	for(int i = 0;i < n;i++)
	{
		par[i] = i;
		rank[i] = 0;
	}
 } 
int find (int x)
{
	
    return par[x] == x ? x : par[x] == find(par[x]);

//	if(par[x] == x)
//	{
//		return x;
//		
//	}
//	else
//	{
//		return par[x] = find(par[x]);
//	}
 } 
 
void unite(int x,int y)//合并,x,y的集合 
{
	x = find(x);
	y = find(y);
	if(x!=y)
	par[y] = x;	
}
 
bool same(int x,int y)
{
	return find(x) == find(y);
}

int main()
{
	int n,m,a,b;
	while(scanf("%d%d", &n, &m), n||m) //n:city,m:road
	{
		for(int i=0;i<n;i++)
		{
			par[i]=i;
		}
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d",&a,&b);
			uinte(a,b);
			
			
		}
	}
//	system("pause");
	return 0;
}
