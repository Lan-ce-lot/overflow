#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<algorithm> 
#include<queue>//·��ѹ�� poj1182
using namespace std;
#define MAX_N 150005
int par[MAX_N];
int rank[MAX_N];//���߶� 
void init(int n)//��ʼ�� 
{
	for(int i = 0;i < n;i++)
	{
		par[i] = i;
		rank[i] = 0;
	}
 } 
 
int find (int x)//��ѯ���ĸ� 
{
	return par[x] == x ? x : par[x] = find(par[x]);
//    int r = x;

//    while(par[r] != r)
//        r = par[r];
        //��ѯ���������ص���x�ĸ����
//    int i = x, j;
//    while(i != r)
//    {
//        j = par[i];
//        par[i] = r;
//        i = j;
//    }
//   return r;
 } 
 
void unite(int x,int y)//�ϲ�,x,y�ļ��� 
{
	x = find(x);
	y = find(y);
	
	if(x==y)
		return; 
	par[y] = x;
	
//	if(x == y)return;
//	if(rank[x] < rank[y])
//	{
//		par[x] = y;
//	}
//	else
//	{
//		par[y] = x;
//		if(rank[x] == rank[y])
//		rank[x]++;
//		
//	}
}
 
bool same(int x,int y)//�ж�x��y�Ƿ�����ͬһ������ 
{
	return find(x) == find(y);
}

int N,K;
int T[MAX_N],X[MAX_N],Y[MAX_N];
void solve()
{
	init(N*3);
	int ans=0;
	for(int i=0;i<K;i++)
	{
		int t = T[i];
		int x = X[i]-1,y=Y[i] - 1;
		if(x<0||N<=x||y<0||N<=y)
		{
			ans++;
			continue;
		}
		if(t == 1)
		{
			if(same(x,y+N)||same(x,y+2*N))
			{
				ans++;
			}
			else
			{
				unite(x,y);
				unite(x+N,y+N);
				unite(x+N*2,y+N*2);
				
				
				
			}
		}
		else
		{
			if(same(x,y)||same(x,y+2*N))
			{
				ans++;
			}
			else
			{
				unite(x,y+N);
				unite(x+N,y+2*N);
				unite(x+2*N,y);
				
			}
		}
		
	}
	printf("%d\n",ans);
 } 
 
int main()
{
	scanf("%d%d",&N,&K);
	for(int i=0;i<K;i++)
	{
		scanf("%d%d%d",&T[i],&X[i],&Y[i]);
	}
	solve();
	return 0;
}
