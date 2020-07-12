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
int a[maxn];
vector<int> M;

void solve()
{
    cin >> t;
    while (t--) {
        M.clear();
        int ans = 0;
        cin >> n ;
        for (int i = 0;i < n; i++) {
            cin >> a[i] ;
        }

        int flag = -1;
        // MAX & MIN
        M.push_back(a[0]);
        for (int i = 0; i < n - 1; i++) {

            if (a[i] < a[i + 1]) {
                if (flag == 0) {
                    M.push_back(a[i]);
                }
                flag = 1;
            }

            if (a[i] > a[i + 1]) {
                if (flag == 1) {
                    M.push_back(a[i]);
                }
                flag = 0;
            }
        }
        if (a[n - 1] != a[n - 2]) M.push_back(a[n - 1]);
        cout << M.size() <<endl;
        for (auto i : M)
            cout << i<< ' ';
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

