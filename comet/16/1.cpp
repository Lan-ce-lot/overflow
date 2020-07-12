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
//中国剩余定理
//1.exgcd求gcd和线性方程的两个参数
//2.乘上倍数
//3.
//==============================================================
ll x = 0, m1, a1;
ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if (!b)
    {
        x = 1, y = 0;
        return a;
    }

    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
void solve()
{
    t = 3;
    t--;
    //cin >> a1 >> m1;
    a1 = 23;
    cin >> m1;
    while (t--)
    {
        ll m2, a2;
        if (t == 1)
        {
        	a2 = 233;
		}
		else
		{
			a2 = 2333;
		}
        cin  >> m2;
        ll k1, k2;//k1 * a1 - k2 * a2 = m2 - m1;
        ll d = exgcd(a1, -a2, k1, k2);
        if ((m2 - m1) % d)
        {
            x = -1;
            break;
        }

        k1 *= (m2 - m1) / d;
        ll tem = a2 / d;
        k1 = (k1 % tem + tem) % tem;

        m1 = a1 * k1 + m1;
        a1 = abs(a1 / d * a2);
    }

    if (x != -1) 
	{
//		if (x)
		x = (m1 % a1 + a1) % a1;
//		else
//		x = 23 * 233 * 2333;
	}
	if (x == 0)
	{
		x = 23 * 233 * 2333;
	}
    cout << x << endl;

    return ;
}

int main()
{
    solve();
//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    return 0;
}
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<vector>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
#define pb push_back
#define first fi
#define second se
#define IO std::ios::sync_with_stdio(false)
typedef long long ll;
const int maxn = 100008;
const ll mod = 1e9+7;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18 + 10;
const double eps = 1e-6;
using namespace std;
ll a,b,c,res;
ll qpow(ll q,ll w,ll p){
	ll ans=1;
	while(w){
		if(w&1) ans=(ans*q)%p;
		q=(q*q)%p;
		w/=2ll;
	}
	return ans;
}
ll solve(ll x,ll m){
	ll s=qpow(res/m,m-2ll,m);
	ll ans=(x*s*(res/m))%res;
	return ans;
}
int main()
{
	scanf("%lld%lld%lld",&a,&b,&c);
	res=23*233*2333;
	if(!a&&!b&&!c){
		printf("%lld\n",res);
		return 0;
	}
	ll ans=(solve(a,23)+solve(b,233)+solve(c,2333))%res;
	printf("%lld\n", ans);
}

