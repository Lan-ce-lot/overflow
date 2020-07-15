/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description: Dinic
 ************************************************************************/
//#include <bits/stdc++.h>
//#pragma comment(linker, "/STACK:102400000,102400000")//add_stack
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <vector>
#include <cstdio>
#include <bitset>
#include <string>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#define ll long long
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,n,a) for(int i=n;i>=a;i--)
#define endl '\n'
#define mem(a) memset(a,0,sizeof(a))
#define IO ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
const int maxn=1e5+5;
int n,m,S,T;
int head[maxn], d[maxn],cur[maxn],tot;
struct E{
	int to,next;
	ll cap;
}edge[maxn<<1];
void add(int u,int v,int w){
	edge[tot].to=v;
	edge[tot].next=head[u];
	edge[tot].cap=w;
	head[u]=tot++;
}
bool bfs(){
	memset(d,0,sizeof(d));	
	queue<int> q;
	q.push(S);d[S]=1;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=head[u];i!=-1;i=edge[i].next){
			int v=edge[i].to;
			if(d[v]||edge[i].cap<=0) continue;
			q.push(v);d[v]=d[u]+1;
		}
	}
	for(int i=0;i<=n;i++) cur[i]=head[i];
	
	return d[T]!=0;
}

ll dfs(int u,ll flow){
	if(u==T) return flow;
	for(int i=cur[u];i!=-1;i=edge[i].next){
		cur[u]=i;
		int v=edge[i].to;
		if(d[v]!=d[u]+1||edge[i].cap<=0) continue;
		int delta=dfs(v,min(flow,edge[i].cap));
		if(delta<=0) continue;
		edge[i].cap-=delta;
		edge[i^1].cap+=delta;
		return delta;
	}
	return 0;
}
ll get_maxFlow(){
	ll maxFlow=0,delta;
	while(bfs()){
		while(delta=dfs(S,INF)){
			maxFlow+=delta;
		}
	}
	return maxFlow;  	
}
int main(){
	while(~scanf("%d%d", &m, &n)){
		S = 1; 
		T = n;
		memset(head,-1,sizeof(head));
		for(int i=1;i<=m;i++){
			int u,v;
			ll w;
			scanf("%d%d%lld", &u, &v, &w);
			add(u,v,w);
			add(v,u,0);
		}
		printf("%lld\n", get_maxFlow());
//		cout<<get_maxFlow()<<endl;
	}
}

