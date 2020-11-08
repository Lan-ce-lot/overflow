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
const int mod = 998244353;
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
int t, n;

ll a, b, c, d, x, y;

ll qpow(ll a, ll n) {
	ll res = 1;
	while (n) {
		if (n & 1) {
			res = (res * a) % mod;
		}
		a = (a * a) % mod;
		n >>= 1;
	}
	return res; 
}
//==============================================================
vector<int> get_divisors(int x)//x的每个约数
{
    vector <int> res;
    for (int i = 1; i <= x / i; i++)
    {
        if (x % i == 0)
        {
            res.push_back(i);
            if (i != x / i)
                res.push_back(x / i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

vector<PII> A;//底数和指数

void divide(int x)
{
    A.clear();
    for (int i = 2; i <= x / i; i++)//底数和指数
    {
        if (x % i == 0)
        {
            int s = 0;
            while (x % i == 0) x /= i, s++;
//            cout << i << ' ' << s << endl;
            A.push_back({i, s});
        }
    }
    if (x > 1) A.push_back({x, 1});//cout << x << ' ' << 1 << endl;
}
vector<int> res;
void solve()
{
//	cout << qpow(3, 3);
//	cin >> a >> b;
	a = read(), b = read(), c = read(), d = read(), x = read(), y = read();
	ll ans = 1;
	for (int i = a; i <= b; i ++) {
		for (int j = c; j <= d; j++) {
			ans = (ans * __gcd(qpow(x, i), qpow(y, j))) % mod;
			cout << qpow(x, i) << '*' << qpow(y, j) << ' ';
			printf("%6d", __gcd(qpow(x, i), qpow(y, j)));
		}
		puts("");
	}//	ll l = b - a + 1;
//	ll r = d - c + 1;
//	ll tot = l * r;
//	ll g = __gcd(x, y);
////	ll ans = qpow(g, tot);
	cout << ans << endl;
	ans = 1;
	ll tem = __gcd(x, y);
	ll tem_x = x;
	ll tem_y = y;
	ll con_x = 0, con_y = 0;
	divide(tem);
	cout << (*(A.end() - 1)).first;
	ll hh = (*(A.end() - 1)).first;
	for (auto it : A) cout << it.first << ' ';puts("");
	while (tem_x % hh == 0) {
		tem_x /= hh;
		con_x++;
	}
	while (tem_y % hh == 0) {
		tem_y /= hh;
		con_y++;
	}	
	cout << con_x << ' ' << con_y << endl;
	debug(tem);
	 for (int i = a; i <= b; i++) {
	 	for (int j = c; j <= d; j++) {
//	 		ans = (ans *qpow(hh, min(i * con_x, j * con_y))) % mod;
//	 		printf("%6d", qpow(hh, min(i * con_x, j * con_y)));
		}
		puts("");
	}
	cout << ans << endl;
	ll all = (b - a + 1) * (d - c + 1) ;
	ll jiao1 = max(a, c);
	ll jiao2 = min(b, d);
//	if (a) {
//		
//	}
	
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

