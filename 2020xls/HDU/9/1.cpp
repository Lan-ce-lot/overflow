#include<stdio.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
using namespace std;
typedef long long ll; 
//typedef pair<int, int> P; 
const int mod = 998244353;
const int N = 2e6 + 5;
struct ed{
    int to, nxt;
}e[N << 1];
int head[N], tot = 1;
void add(int u, int v){
    e[tot].to = v, e[tot].nxt = head[u], head[u] = tot++;
}
ll siz[N], n, t, x, val[N], dep[N], sum, mx;
bool leaf[N];
void dfs1(int x, int fa)
{
    dep[x] = dep[fa] + 1;
    siz[x] = 1;
    leaf[x] = true;
    for (int i = head[x]; i; i = e[i].nxt)
    {
        int v = e[i].to;
        if (v == fa)
            continue;
        dfs1(v, x);
        siz[x] += siz[v];
        leaf[x] = false;
    }
    sum += siz[x];
//    cout << sum << endl;
}
void dfs2(int x, int fa)
{
    val[x] += val[fa] + siz[x];
    for (int i = head[x]; i; i = e[i].nxt)
    {
        int v = e[i].to;
        if (v == fa)
            continue;
        dfs2(v, x);
    }
}
int  main()
{
    scanf("%d", &t);
    while (t--)
    {
        mx = sum = 0;
        tot = 1;
        scanf("%d", &n);
        for (int i = 0; i <= n; i++)
        {
            head[i] = val[i] = leaf[i] = dep[i] = 0;
        }
        for (int i = 2; i <= n; i++)
        {
            scanf("%d", &x);
            add(x, i);
            add(i, x);
        }
        dfs1(1, 0);
        dfs2(1, 0);
//        cout << sum << endl;
        for (int i = 1; i <= n; i++)
        {
            if (leaf[i])
            {
                mx = max(mx, dep[i] * n - val[i]);
            }
        }
        printf("%lld\n", sum + mx);
    }
}
