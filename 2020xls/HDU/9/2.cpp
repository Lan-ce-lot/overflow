/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description:
 ************************************************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const double pi = acos(-1.0);
const double eps = 1e-6;
const int mod = 1e9 + 7;
#define debug(a) cout << "*" << a << "*" << endl
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 500005;
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
ll t, n;
vector<ll> G[maxn];

ll dp[maxn];
ll dept[maxn];
ll tt[maxn], sum = 0;
void dfs(int x, int fa) {
    if (x == 1) dept[x] = 1;
    else dept[x] = dept[fa] + 1;
    dp[x] = 1;
    for (int i = 0; i < G[x].size(); i++) {
        int tem = G[x][i];
        if (tem != fa) {
            
            dfs(tem, x);
            dp[x] += dp[tem];
        }
    }
    sum += dp[x]; 
}

void dfs1(int x, int fa) {
    tt[x] = tt[fa] + dp[x];
    for (int i = 0; i < G[x].size(); i++) {
        int tem = G[x][i];
        if (tem != fa) {
            dfs1(tem, x);
        }
    }
}


void solve()
{
    t = read();
    while (t--) {
        sum = 0;
        n = read();
        int a;

        for (int i = 2; i <= n; i++) {
            a = read();
            G[a].push_back(i);
        }
        dfs(1, 0);
        dfs1(1, 0);
        ll max_ = -INF, index = 0;
        for (int i = 1; i <= n; i++) {
            max_ = max(max_, n * dept[i] - tt[i]);
        }
        printf("%lld\n", sum + max_);
        for (int i = 1; i <= n; i++) {
            G[i].clear();
            dp[i] = 0;
            dept[i] = 0;
            tt[i] = 0;
        }
    }
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

