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
priority_queue<int, vector<int>, greater<int> > Q; 
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
int t, n, tree[maxn];
int dis[maxn], vis[maxn], G[100][100]; 
vector<int> P;
void dfs(int now) {
	if (now > n ) {
		if (vis[now / 2] == 1) {
//			P.clear();
			return;
		}
		for (int i = 0; i < P.size(); i++) printf("%d%s", P[i], i != P.size() - 1 ? " " : "\n");
//		puts("");
//		P.clear();
		vis[now / 2] = 1;
		return;
	}
	P.push_back(tree[now]);
	dfs(now << 1 | 1);
	P.pop_back();
	
	P.push_back(tree[now]);
	dfs(now << 1);
	P.pop_back();	
	
}

void solve()
{
	n = read();
	for (int i = 1; i <= n; i++) {
		tree[i] = read();
	}
//	P.push_back(tree[1]);
	dfs(1);
	bool isMin =1, isMax = 1;
	for (int i = 2; i <= n; i++) {
		if (tree[i >> 1] > tree[i]) {
			isMin = 0;
		}
		if (tree[i >> 1] < tree[i]) {
			isMax = 0;
		}
	}
	 if (isMin == 1)
        printf("Min Heap");
    else 
        printf("%s", isMax == 1 ? "Max Heap" : "Not Heap"); 
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}
//#include <iostream>
//#include <vector>
//#include <set>
//#include <algorithm>
//using namespace std;
//int n, maxheight = 0;
//vector<vector<int>> v;
//bool visit[10010];
//set<int> s;
//vector<int> temp;
//void dfs(int node, int height) {
//    if(height > maxheight) {
//        temp.clear();
//        temp.push_back(node);
//        maxheight = height;
//    } else if(height == maxheight){
//        temp.push_back(node);
//    }
//    visit[node] = true;
//    for(int i = 0; i < v[node].size(); i++) {
//        if(visit[v[node][i]] == false)
//            dfs(v[node][i], height + 1);
//    }
//}
//int main() {
//    scanf("%d", &n);
//    v.resize(n + 1);
//    int a, b, cnt = 0, s1 = 0;
//    for(int i = 0; i < n - 1; i++) {
//        scanf("%d%d", &a, &b);
//        v[a].push_back(b);
//        v[b].push_back(a);
//    }
//    for(int i = 1; i <= n; i++) {
//        if(visit[i] == false) {
//            dfs(i, 1);
//            if(i == 1) {
//                if (temp.size() != 0) s1 = temp[0];
//                for(int j = 0; j < temp.size(); j++)
//                    s.insert(temp[j]);
//            }
//            cnt++;
//        }
//    }
//    if(cnt >= 2) {
//        printf("Error: %d components", cnt);
//    } 
//	else {
//        temp.clear();
//        maxheight = 0;
//        fill(visit, visit + 10010, false);
//        dfs(s1, 1);
//        for(int i = 0; i < temp.size(); i++)
//            s.insert(temp[i]);
//        for(auto it = s.begin(); it != s.end(); it++)
//            printf("%d\n", *it);
//    }
//    return 0;
//}
