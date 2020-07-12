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
const int maxn = 1005;
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

int t, n, m;
int a[maxn], b[maxn];
bool check(double x) {
    double y[maxn];
    for(int i=0;i<n;i++)
    {
        y[i]=a[i]-x*b[i];
    }
    sort(y,y+n);
    double sum=0;
    for(int i=m;i<n;i++)
    {
        sum+=y[i];
    }
    return sum>=0.0;
}

void solve()
{
    while (cin >> n >> m) {
        if (n == 0 && m == 0) return;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        double l = 0, r = INF;

        while (fabs(l - r) > eps) {
            double mid = (l + r) / 2.0;
            if (check(mid)) {
                l = mid;
            } else {
                r = mid;
            }

        }
        printf("%.0f\n", l * 100);
//        sort(T, T + n, cmp);
//        for (int i = 0; i < n; i++) {
//            cout << T[i].a << ' ' << T[i].b <<endl;
//            debug((T[i].b - T[i].a) / T[i].b);

    }
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}
