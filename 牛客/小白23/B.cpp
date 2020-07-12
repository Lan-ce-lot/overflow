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
int t, n;
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
int ans;

bool is_prime(ll n)
{
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			return 0;
		}
	}
	return 1;
}
void solve()
{
	cin >> t;
	while (t--)
	{
		A.clear();
		cin >> n;
		divide(n);
		int temp = INF;
		if (is_prime(n))
		{
			cout << n << endl;
			continue;
		}
		for (int i = 0; i < A.size(); i++)
		{
//			cout << A[i].first << ' ' << A[i].second << endl;
			temp = min(temp, int(pow(A[i].first, A[i].second)));
//			ans = A[i].first;
		}
		
		
		for (int i = 0; i < A.size(); i++)
		{
			if (temp % (int(pow(A[i].first, A[i].second))) != 0)
			{
				temp = int(pow(A[i].first, A[i].second));
//				ans = A[i].first;
			}
		}
		
		
		cout << temp << endl;
	}
}
/*
2 4
3 2
5 1
7 1

8
40320
2 7
3 2
5 1
7 1
0
362880
2 7
3 4
5 1
7 1
0
3628800
2 8
3 4
5 2
7 1
0
39916800
2 8
3 4
5 2
7 1
11 1
0

*/
int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

