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
const double eps = 1e-6;
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
double a[maxn], l, r;

double f(double x)
{
    double tot = 0;
    for (int i = n + 1; i >= 1; i--)
    {
        tot = tot  * x + a[n + 2 - i];
    }
    return tot;
}
void solve()
{
    scanf("%d%lf%lf", &n, &l, &r);
    for (int i = 1; i <= n + 1; i++)
    {
        scanf("%lf", &a[i]);
    }
    while (r - l > eps)
    {
        double lmid = l + (r - l) / 3.0, rmid = r - (r - l) / 3.0;
        if (f(lmid) < f(rmid))
            l = lmid;
        else
            r = rmid;
    }
    printf("%.5f\n", l);
}

int main()
{
    solve();
//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    return 0;
}
//
//#include<cstdio>
//using namespace std;
//typedef double DB;
//const int N=15;
//const DB EPS=1e-6;
//int n;
//DB a[N],l,r;
//inline DB f(DB x)
//{
//    DB tot=0;
//    for (register int i=n+1;i>=1;--i)
//    tot=tot*x+a[n+2-i];
//    return tot;
//}
//int main()
//{
//    register int i;
//    scanf("%d%lf%lf",&n,&l,&r);
//    for (i=1;i<=n+1;++i)
//    scanf("%lf",&a[i]);
//    while (r-l>EPS)
//    {
//        DB lmid=l+(r-l)/3.0,rmid=r-(r-l)/3.0;
//        if (f(lmid)<f(rmid)) l=lmid; else r=rmid;
//    }
//    printf("%.5lf",l);
//    return 0;
//}
