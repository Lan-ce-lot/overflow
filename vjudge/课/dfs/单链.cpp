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
const int maxn = 1000005, N = 10005;

//===================================================================================
// h存储链表头，e[]存储节点的值，ne[]存储节点的next指针，idx表示当前用到了哪个节点
struct node {
    int to, l, c;
};
int h[N];
node e[N];
int ne[N], idx = 0;

// 初始化memset(h, -1, sizeof h);

void insert(int a, node b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}
//===================================================================================


int t, n, k, r;
int lenth = INF, cost;
bool vis[105];

void dfs(int no, int l, int c) {
    if (vis[no] || c > k || l >= lenth)return;
    if (no == n) {lenth = min(lenth, l);return;}

    for (int i = h[no]; i != -1; i = ne[i]) {
        int to = e[i].to;
        vis[no] = 1;
        dfs(to, e[i].l + l, e[i].c + c);
        vis[no] = 0;
    }
}


void solve()
{
    scanf("%d %d %d", &k, &n, &r);// n->node, r->edge
    memset(h, -1, sizeof h);
    for (int i = 0; i < r; i++) {
        int _from, _to, _lo, _co;
        scanf("%d %d %d %d", &_from, &_to, &_lo, &_co);
        insert(_from, {_to, _lo, _co});
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

