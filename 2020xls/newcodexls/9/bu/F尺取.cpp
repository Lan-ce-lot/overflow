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
const int maxn = 4000005;
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
int t, n, m, ans = INF, temp = 0, vis[maxn], all = 0;

struct node {
    int day, dow;
    bool operator < (const node& W) const {return dow < W.dow;}
}N[maxn];

void solve() {
    n = read(), m = read();
    for (int i = 1; i <= n; i++) {
        int te = read();
        for (int j = 1; j <= te; j++) 
            N[all].day = i, N[all++].dow = read();
    }
    
    sort(N, N + all);
    for (int i = 0, j = 0; i < all; i++) {
        if (vis[N[i].day] == 0) temp ++;
        vis[N[i].day] ++;
        while (temp >= m && j <= i) {
            if ((--vis[N[j].day] == 0)) temp--;
            ans = min(N[i].dow - N[j].dow, ans);
            j++;
        }
    }
    
    printf("%d", ans);
}

int main() {

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}


