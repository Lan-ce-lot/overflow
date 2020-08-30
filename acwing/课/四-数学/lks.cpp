/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description:
 ************************************************************************/
//#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")//add_stack
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
const int eps = 1e-10;
const int mod = 1e9 + 7;
#define debug(a) cout << "*" << a << "*" << endl
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 1000005;

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
//==============================================================
//组合数递推法,利用公式
//C(a, b) (a < 2000, b < 2000)
//==============================================================
ll c[2005][2005];//c[a][b]表示从a个苹果中选b个的方案数

void get_combination(int N)
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j <= i; j++)
            if (!j)
                c[i][j] = 1;
            else
                c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
}

//==============================================================
//预处理 + 逆元(如果mod是prime用小费马定理快速幂取模，否则用拓展欧几里德)
//10^5 ~ 6
//==============================================================
ll fact[maxn];//阶乘取模的结果
ll infact[maxn];//阶乘的逆
ll q_pow(ll n, ll x, ll mod)
{
    ll res = 1;
    while (x)
    {
        if (x & 1) res = res * n % mod;
        n = n * n % mod;
        x >>= 1;
    }
    return res;
}

void get_combination1(int N)
{
    fact[0] = infact[0] = 1;
    for (int i = 1; i < N; i++)
    {
        fact[i] = fact[i - 1] * i % mod;
        infact[i] = infact[i - 1] * q_pow(i, mod - 2, mod) % mod;
    }

}

ll com(ll a, ll b)
{
    return fact[a] * infact[b] % mod * infact[a - b] % mod;
}
//==============================================================
//Lucas定理
//mod是质数是适用
//若p是质数，则对于任意整数1 <= m <= n,有：
//C(n, m) = C(n % p, m % p) * C(n / p, m / p) (mod p)
//10^18
//O()
//ll q_pow()要一个快速幂
//==============================================================

ll C(int a, int b, ll mod)//快速幂 + 逆元求组合数(这个可以用的)
{
    ll res = 1;
    for (int i = 1, j = a; i <= b; i++, j--)
    {
        res = res * j % mod;
        res = res * q_pow(i, mod - 2, mod) % mod;

    }
    return res;
}
//==============================================================
ll Lucas(ll a, ll b, ll mod)//调用即可，C(a, b)
{
    if (a < mod && b < mod )
    {
        return C(a, b, mod);
    }
    return C(a % mod , b % mod, mod) * Lucas(a / mod, b / mod, mod) % mod;

}

//==============================================================
//分解质因数法
//当需要求出具体值而非取模时适用
//1.筛法求范围内所有质数
//2.通过C(a, b) = a! / b!/ (a - b)! 这个公式的每个质因子的次数。
//: n!中质数p的次数是n / p + n / p ^ 2 + n / p ^ 3...(向下取整)
//3.高精度乘法将所有质因子相乘
//O()
//==============================================================
int primes[maxn], cnt;
int sum[maxn];//每个质数的次数
bool st[maxn];

void get_primes(int n)//线性筛
{
    for (int i = 2; i <= n; i++)
    {
        if (!st[i]) primes[cnt++] = i;
        for (int j = 0; primes[j] <= n / i; j++)
        {
            st[primes[j] * i] = 1;
            if (i % primes[j] == 0) break;
        }
    }
}

int get(int n, int p)
{
    int res = 0;
    while (n)
    {
        res += n / p;
        n /= p;
    }
    return res;
}

vector<int> mul(vector<int> &a, int b)
{
    vector<int> c;
    int t = 0;
    for (int i = 0; i < a.size(); i++)
    {
        t += a[i] * b;
        c.push_back(t % 10);
        t /= 10;
    }
    while (t)
    {
        c.push_back(t % 10);
        t /= 10;
    }
    return c;
}

void big_com(int a, int b)
{
    get_primes(a);
    for (int i = 0; i < cnt; i++)
    {
        int p = primes[i];
        sum[i] = get(a, p) - get(a - b, p) - get(b, p);

    }

    vector<int> res;
    res.push_back(1);

    for (int i = 0; i < cnt; i++)
        for (int j = 0; j < sum[i]; j++)
            res = mul(res, primes[i]);

    for (int i = res.size() - 1; i >= 0; i--)
    {
        printf("%d", res[i]);
    }
    puts("");
}
//==============================================================
void solve()
{
    ll l, r, p;
    scanf("%d", &t);
    while (t--) {
        l = read(), r = read(), p = read();

        printf("%lld\n", Lucas(l + r, l, p));
    }
    // cin >> l >> r;
    // big_com(l, r);
//    get_combination(2005);
//    get_combination1(2000 + 5);
//    cin >> t;
//    while (t--)
//    {
//        cin >> l >> r >> p;
//        cout << Lucas(l, r, p) << endl;
//    }
}

int main()
{
    solve();
//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    return 0;
}


#pragma GCC optimize(2)
//#pragma GCC optimize(3,"Ofast","inline")


#include<stdio.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
#include<map>
//#include<unordered_map>
#include<set>
#include<queue>
#include<deque>
#include<stack>
#include<vector>
#include<bitset>
using namespace std;
typedef long long ll; 
typedef unsigned int ull; 
/pedef pair<int, int> P; 
const int mod = 1e9 + 7;
const int N = 3e5 + 5;
struct ed{
	int to, nxt, w;
}e[N << 1];
int head[N], tot = 1;
void add(int u, int v){
	e[tot].to = v, e[tot].nxt = head[u], head[u] = tot++;
}

int dis[N], n, res, num = 1;
ll a[N][2], sum[N], ans, x;
map<ll, int> mp;
int find(int x)
{
	return dis[x] == x ? x : dis[x] = find(dis[x]); 
}
void uni(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x > y)
		dis[y] = x;
	else if (y > x)
		dis[x] = y;
}
ll gcd(ll a, ll b)
{
	return b == 0 ? a : gcd(b, a % b);
}
int  main()
{
	scanf("%d", &n);
	for (int i = 0; i <= n; i++)	dis[i] = i;
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &x);
		mp[x]++;
	}
	map<ll, int>::iterator it;
	for (it = mp.begin(); it != mp.end(); it++)
	{
		a[num][0] = it->first;
		a[num][1] = it->second;
		it->second = num;
		num++; 
	}
	for (int i = 1; i <= num; i++)
	{
		if (a[i][0] % 3 == 0 && mp[a[i][0] / 3 * 2])
			uni(i, mp[a[i][0] / 3 * 2]);
	}
	for (int i = 1; i <= num; i++)
	{
		sum[find(i)] += a[i][0] * a[i][1];
	}
	for (int i = 1; i < num; i++)
	{
		if (sum[i])
			ans = max(ans, sum[i]);
	}
	printf("%lld\n", ans);
}
