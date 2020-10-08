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
//const int maxn = 1000005;
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
typedef long long ll;
const int maxn = 2e5+10;
int V[maxn];
map<int, ll>S;

ll Sum(ll n)
{
    int m = (int)sqrt(n);
    int t = n / m;
    for(int i = 1;i <= m;i++)  V[i-1] = n / i;

    int cnt = 1;
    for(int i = t + m - 2;i >= m;i--)  V[i] = cnt++;


    for(int i = 0;i <= t+m-2;i++)  S[V[i]] = 1LL * V[i] * (V[i]+1) / 2 - 1;

    for(int p = 2;p <= m;p++)
    {
        if(S[p] > S[p-1])
        {
            ll sp = S[p-1];
            ll p2 = p *  p;
            for(int i = 0;i <= t+m-2;i++)
            {
                ll v = V[i];
                if(v < p2)  break;
                S[v] -= p*(S[v/p] - sp);
            }
        }
    }

    return S[n];
}
void solve()
{
	printf("%lld\n", Sum(1000000000));
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

