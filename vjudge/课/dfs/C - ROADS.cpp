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

int t, n, k, r;
struct Node {
    int to, l, c;
    Node(int to_ = 0, int l_ = 0, int c_ = 0):to(to_), l(l_), c(c_){}
};
vector<Node> G[10005];
int lenth = INF, cost;
bool vis[105];

void dfs(int no, int l, int c) {
    if ( c > k || l > lenth)return;
    if (no == n) {lenth = min(lenth, l);return;}

    for (int i = 0, sz = G[no].size(); i < sz; i++) {
        int to = G[no][i].to;
        if (!vis[to]) {
            vis[to] = 1;
            dfs(to, G[no][i].l + l, G[no][i].c + c);
            vis[to] = 0;
        }
    }
}


void solve()
{
    scanf("%d %d %d", &k, &n, &r);// n->node, r->edge
    Node nn; 
    for (int i = 0; i < r; i++) {
        int _from, _to, _lo, _co;
        scanf("%d %d %d %d", &_from, &nn.to, &nn.l, &nn.c);
//        cout << _to << _lo << _co <<endl;
        G[_from].push_back(nn);
    }

    dfs(1, 0, 0);
    printf("%d\n", (lenth == INF ? -1 : lenth));
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();

    return 0;
}

