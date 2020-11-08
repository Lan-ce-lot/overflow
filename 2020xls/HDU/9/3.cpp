///*************************************************************************
// > FileName:
// > Author:      Lance
// > Mail:        lancelot_hcs@qq.com
// > Date:        9102.1.8
// > Description:
// ************************************************************************/
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
ll t, n, a, b, k;

void solve()
{
    t =read();
    while (t--) {
        a = read(), b = read(), k = read();
        if (a > b) {
            swap(a, b);
        }
        k++;
        n = b - a;
        if (n % k) {
            puts("1");
            continue;
        } else {
            if (int(n * ((2 - k) * 1ll + sqrt(k * k * 1.0 + 4.0)) / 2 / k) == a) {
                puts("0");
            } else {
                puts("1");
            }
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