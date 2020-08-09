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
const int maxn = 250;
const int M = 26 + 26 * 26;
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
int t, n;
struct node {
    string s_1, equal, s_2;
}N[maxn];
 
int f[M];
 
inline bool check_low(char c) {
    return c >= 'a' && c <= 'z';
}
 
inline int turn(char c) {
    if (check_low(c)) return c - 'a';
    else if(c >= 'A' && c <= 'Z') return c - 'A';
}
int con1 = 0, con2 = 0, con3 = 0, con4 = 0;
void solve()
{
    n = read();
    for (int i = 0; i < n; i++) cin >> N[i].s_1 >> N[i].equal >> N[i].s_2;
     
    for (int i = 0; i < 26 * M; i++) {
        for (int j = 0; j < n; j++) {
            int l1 = N[j].s_1.size(), l2 = N[j].s_2.size();
            if (islower(N[j].s_2[0])) f[N[j].s_1[0]-'A'] |= 1 << (N[j].s_2[0] -'a'),con1++;
            else if (l1 == 1 && l2 == 1) f[N[j].s_1[0] - 'A'] |= f[N[j].s_2[0] -'A'], con2++;
            else if (l1 > l2)
                for (int k = 0; k < 26; k++) {
                    if (f[N[j].s_1[0] - 'A'] >> k & 1)
                        f[26 + k * 26 + N[j].s_1[2] - 'a'] |= f[N[j].s_2[0] - 'A'], con3++;
                }
                         
            else
                for (int k = 0; k < 26; k++)
                    if (f[N[j].s_2[0] - 'A']>>k&1)
                        f[N[j].s_1[0] - 'A'] |= f[26 + k * 26 + N[j].s_2[2] -'a'];         
        }
    }
    for (int i = 0; i < 26; i++) {
        printf("%c: ", char(i + 'A'));
        for (int j = 0; j < 26; j++) if (f[i] >> j & 1) printf("%c", char('a' + j));
        puts("");
    }
}
 
int main()
{
 
//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

