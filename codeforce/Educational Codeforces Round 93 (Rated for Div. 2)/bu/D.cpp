///*************************************************************************
// > FileName:
// > Author:      Lance
// > Mail:        lancelot_hcs@qq.com
// > Date:        9102.1.8
// > Description:
// ************************************************************************/
////#include <bits/stdc++.h>
////#pragma comment(linker, "/STACK:102400000,102400000")//add_stack
//#include <algorithm>
//#include <iostream>
//#include <cstdlib>
//#include <cstring>
//#include <sstream>
//#include <vector>
//#include <cstdio>
//#include <bitset>
//#include <string>
//#include <cmath>
//#include <deque>
//#include <queue>
//#include <stack>
//#include <map>
//#include <set>
//using namespace std;
//typedef long long ll;
//typedef pair<int, int> PII;
//const double pi = acos(-1.0);
//const double eps = 1e-6;
//const int mod = 1e9 + 7;
//#define debug(a) cout << "*" << a << "*" << endl
//const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
//const int maxn = 1000005;
////sacnf("%lf") printf("%f")
//ll read()
//{
//    ll x = 0,f = 1;
//    char ch = getchar();
//    while (ch < '0' || ch > '9')
//	{
//		if (ch == '-')
//		f = -1;
//		ch = getchar();
//	}
//    while (ch >= '0' && ch <= '9')
//	{
//		x = x * 10 + ch - '0';
//		ch = getchar();
//	}
//    return x * f;
//}
//int t, n;
//
//void solve()
//{
//
//}
//
//int main()
//{
//
////    freopen("F:/Overflow/in.txt","r",stdin);
////    ios::sync_with_stdio(false);
//    solve();
//    return 0;
//}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

const int N = 205;
int r[N],g[N],b[N];
int f[N][N][N];
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int R,G,B;cin >> R >> G >> B;
	for(int i = 1;i <= R;++i)	cin >> r[i];sort(r + 1,r + R + 1,greater<int>());
	for(int i = 1;i <= G;++i)	cin >> g[i];sort(g + 1,g + G + 1,greater<int>());
	for(int i = 1;i <= B;++i)	cin >> b[i];sort(b + 1,b + B + 1,greater<int>());
	int res = 0;
	for(int i = 0;i <= R;++i)
	{
		for(int j = 0;j <= G;++j)
		{
			for(int k = 0;k <= B;++k)
			{
				auto& v = f[i][j][k];
				if(i >= 1 && j >= 1)	v = max(v,f[i - 1][j - 1][k] + r[i] * g[j]);
				if(j >= 1 && k >= 1)	v = max(v,f[i][j - 1][k - 1] + g[j] * b[k]);
				if(i >= 1 && k >= 1)	v = max(v,f[i - 1][j][k - 1] + r[i] * b[k]);
				res = max(res,v);
			}
		}
	}
	cout << res << endl;
    return 0;
}
