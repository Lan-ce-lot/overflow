///*************************************************************************
// > FileName:
// > Author:      Lance
// > Mail:        lancelot_hcs@qq.com
// > Date:        9102.1.8
// > Description:
// ************************************************************************/
////#include <bits/stdc++.h>
////#pragma comment(linker, "/STACK:102400000,102400000")//add_stack
//#include <algorithm>
//#include <iostream>
//#include <cstdlib>
//#include <cstring>
//#include <sstream>
//#include <vector>
//#include <cstdio>
//#include <bitset>
//#include <string>
//#include <cmath>
//#include <deque>
//#include <queue>
//#include <stack>
//#include <map>
//#include <set>
//using namespace std;
//typedef long long ll;
//typedef pair<int, int> PII;
//const double pi = acos(-1.0);
//const double eps = 1e-6;
//const int mod = 1e9 + 7;
//#define debug(a) cout << "*" << a << "*" << endl
//const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
//const int maxn = 1e5+5;
////sacnf("%lf") printf("%f")
//ll read()
//{
//    ll x = 0,f = 1;
//    char ch = getchar();
//    while (ch < '0' || ch > '9')
//	{
//		if (ch == '-')
//		f = -1;
//		ch = getchar();
//	}
//    while (ch >= '0' && ch <= '9')
//	{
//		x = x * 10 + ch - '0';
//		ch = getchar();
//	}
//    return x * f;
//}
//int t, n, m, S, T;
//
//struct edge {
//	int form, to, cap, 
//}
//
//int head[maxn], ne[maxn], 
//
//
//void solve()
//{
//	while (~scanf("%d%d", &n, &m)) {
////		G.clear(); 
////		G = vector<edge> ();
//		for (int i = 0; i < 205; i++) {
//			G[i].clear();
//		}
//		for (int i = 1; i <= n; i++) {
//			int xx, yy, ee;
////			cout << i << endl;
//			scanf("%d%d%d", &xx, &yy, &ee);
//			add_edge(xx, yy, ee);
////			cout << i << ' ' << n << endl;
//		}
//
//		printf("%d\n", max_flow(1, m));
//	}
//}
//
//int main()
//{
//
////    freopen("F:/Overflow/in.txt","r",stdin);
////    ios::sync_with_stdio(false);
//    solve();
//    return 0;
//}
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
int head[maxn],pre[maxn],flow[maxn],Inq[maxn],tot;
struct E{
	int to,next,cap;
}edge[maxn<<1];
void add(int u,int v,int w){
	edge[tot].to=v;
	edge[tot].next=head[u];
	edge[tot].cap=w;
	head[u]=tot++;
}
bool bfs(){
	mem(Inq);
	queue<int> q;
	q.push(S);Inq[S]=1;flow[S]=INF;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=head[u];i!=-1;i=edge[i].next){
			int v=edge[i].to;
			if(Inq[v]||edge[i].cap<=0) continue;
			flow[v]=min(flow[u],edge[i].cap);
			pre[v]=i;
			q.push(v);Inq[v]=1;
			if(v==T) return 1;
		}
	}
	return 0;
}
int update(){
	int delta=flow[T],u=T;
	while(u!=S){
		int i=pre[u];
		edge[i].cap-=delta;
		edge[i^1].cap+=delta;
		u=edge[i^1].to;
	}
	return delta;
}
int get_maxFlow(){
	int maxFlow=0;
	while(bfs()) maxFlow+=update();
	return maxFlow;  	
}
int main(){
	while(cin>>m>>n){
		S = 1, T = n;
		memset(head,-1,sizeof(head));
		memset(pre,0,sizeof(pre));
		for(int i=1;i<=m;i++){
			int u,v,w;cin>>u>>v>>w;
			add(u,v,w);add(v,u,0);
		}
		cout<<get_maxFlow()<<endl;
	}
}

