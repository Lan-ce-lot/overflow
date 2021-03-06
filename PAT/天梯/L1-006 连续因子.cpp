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
ll t, n;
vector<ll> V;
vector<ll> Res, tem;
bool is_prime(ll a) {
	if (a == 1) return 0;
	if (a == 2 || a == 3) return 1;
	if (a % 6 != 1 && a % 6 != 5) return 0;
	for (int i = 5; i <= a / i + 1; i += 6) {
		if (a % i == 0 || a % (i + 2) == 0) {
			return 0;
		}
	}
	return 1;
	
}
void solve()
{
	n = read();
	if (is_prime(n)) {
		cout << 1 << endl << n << endl;
		return;
	} 
	int ansl = 0, ansr = -1;
	for (ll i = 2; i * i <= n; i++) {
		ll tem = n, j = i;
		while (tem % j == 0) {
			tem /= j;
			j++;
		}
		if (j - i > ansr - ansl + 1) {
			ansl = i;
			ansr = j - 1;
		}
	}
	cout<<ansr-ansl+1<<endl;
	for(ll i=ansl;i<=ansr;i++)
    {
        cout<<i;
        if(i<ansr)cout<<'*';
        else cout<<endl;
    }
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}



