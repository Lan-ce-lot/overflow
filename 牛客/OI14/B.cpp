/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description:
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
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const double pi = acos(-1.0);
const double eps = 1e-6;
const int mod = 1e9 + 7;
#define debug(a) cout << "*" << a << "*" << endl
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 1000005;
//sacnf("%lf") printf("%f")
ll read()
{
    ll x = 0,f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
	{
		if (ch == '-')
		f = -1;
		ch = getchar();
	}
    while (ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
    return x * f;
}




vector<int> G[maxn];
bool vis[maxn];
struct CenterTree{
    int n;
    int ans;
    int siz;
    int son[maxn];
    void dfs(int u,int pa){
        son[u]=1;
        int res=0;
//        for (int i=head[u];i!=-1;i=edges[i].next){
//            int v=edges[i].to;
//            if (v==pa) continue;
//            if (vis[v]) continue;
//            dfs(v,u);
//            son[u]+=son[v];
//            res=max(res,son[v]-1);
//        }
        for (int i=0;i<G[u].size();i++){
            int v=G[u][i];
            if (v==pa) continue;
            if (vis[v]) continue;
            dfs(v,u);
            son[u]+=son[v];
            res=max(res,son[v]-1);
        }
        res=max(res,n-son[u]);
        if (res<siz){
            ans=u;
            siz=res;
        }
    }
    int getCenter(int x){
        ans=0;
        siz=INF;
        dfs(x,-1);
        return ans;
    }
}Cent;

int ans = 0;
void bfs(int u)//0
{
	memset(vis, 0, sizeof vis);
	ans = 0;
	queue<int> Q;
	queue<int> deep;
	Q.push(u);
	int dd = 0;
	deep.push(dd);
	vis[u] = 1;
	while (!Q.empty())
	{
		int top = Q.front();
		int top_d = deep.front();
		Q.pop();
		deep.pop();
		for (int i = 0; i < G[top].size(); i++)
		{
			if (!vis[G[top][i]])
			{
				Q.push(G[top][i]);
				deep.push(top_d + 1);
				vis[G[top][i]] = 1;
				ans = ans + top_d + 1;
			}
			
		}
		
	}
	
}

int t, n;

void solve()
{
	cin >> n;
	Cent.n = n;
	for (int i = 0; i < n - 1; i++)
	{
		int x, y;
		cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
		
	}
	//cout << Cent.getCenter(n) << endl;
	bfs(Cent.getCenter(n));
	
	cout << ans << endl;
	
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

