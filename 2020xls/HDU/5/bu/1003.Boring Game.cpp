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
vector<int> G[1220];
int t, n, k;
ll qpow(ll n, ll x) {

    ll res = 1;
    while (x) {
        if (x & 1) {
            res = (res * n) % mod;
        }
        n = (n * n) % mod;
        x >>= 1;
    }
    return res;
}
int a[maxn];
int tem[maxn];

void look(int k) {
    for (int i = 1; i <= k; i++) {
        for (auto it : G[i]) {
            cout << it << ' ';
        }
        puts("");
    }
}

void solve()
{
    t = read();
    while (t--) {
        n = read(), k = read();
        ll all = 2 * n * qpow(2, k);
        ll row = qpow(2, k);
        for (int i = 0; i <= row; i++) G[i].clear();
        for (int i = 1; i <= all; i++) {
            a[i] = read();
            G[1].push_back(a[i]);
        }
        for (int i = 1; i <= k; i++) {
            int tem = 1 << (i - 1);       // 操作行数
            int con = all / (tem * 2);    // 当前中点
            for (int j = 1; j <= tem; j++) {
                int to = 2 * tem - j + 1;
                reverse(G[j].begin(), G[j].begin() + G[j].size() / 2);      // 反转
                G[to].assign(G[j].begin(), G[j].begin() + G[j].size() / 2); // 拷贝

                for (int k = 0; k < con; k++) G[j][k] = G[j][k + con];
                for (int k = 1; k <= con; k++) G[j].pop_back();
//                look(tem * 2);
            }
        }
        for (int i = 0; i < n * 2; i++)
            for (int j = row; j >= 1; j--) {
                if (j != row || i != 0) printf(" ");
                cout << G[j][i];
            }
        puts("");
    }
}
/*
10
2 2
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
1 1
1 2 3 4
1 2
1 2 3 4 5 6 7 8
*/
int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

