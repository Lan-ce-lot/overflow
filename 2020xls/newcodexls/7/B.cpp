/////*************************************************************************
//// > FileName:
//// > Author:      Lance
//// > Mail:        lancelot_hcs@qq.com
//// > Date:        9102.1.8
//// > Description:
//// ************************************************************************/
//////#include <bits/stdc++.h>
//////#pragma comment(linker, "/STACK:102400000,102400000")//add_stack
////#include <algorithm>
////#include <iostream>
////#include <cstdlib>
////#include <cstring>
////#include <sstream>
////#include <vector>
////#include <cstdio>
////#include <bitset>
////#include <string>
////#include <cmath>
////#include <deque>
////#include <queue>
////#include <stack>
////#include <map>
////#include <set>
////using namespace std;
////typedef long long ll;
////typedef pair<int, int> PII;
////const double pi = acos(-1.0);
////const double eps = 1e-6;
////const int mod = 1e9 + 7;
////#define debug(a) cout << "*" << a << "*" << endl
////const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
////const int maxn = 1000005;
//////sacnf("%lf") printf("%f")
////ll read()
////{
////    ll x = 0,f = 1;
////    char ch = getchar();
////    while (ch < '0' || ch > '9')
////	{
////		if (ch == '-')
////		f = -1;
////		ch = getchar();
////	}
////    while (ch >= '0' && ch <= '9')
////	{
////		x = x * 10 + ch - '0';
////		ch = getchar();
////	}
////    return x * f;
////}
////int t, n;
////
////void solve()
////{
////
////}
////
////int main()
////{
////
//////    freopen("F:/Overflow/in.txt","r",stdin);
//////    ios::sync_with_stdio(false);
////    solve();
////    return 0;
////}
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//typedef long long LL;
//
//const int N = 20;
//
//int p[N];
//
//
//int main()
//{
//    int n, m;
//    cin >> n >> m;
//
//    for (int i = 0; i < m; i ++ ) cin >> p[i];
//
//    int res = 0;
//    for (int i = 1; i < 1 << m; i ++ )
//    {
//        int t = 1, s = 0;
//        for (int j = 0; j < m; j ++ )
//            if (i >> j & 1)
//            {
//                if ((LL)t * p[j] > n)
//                {
//                    t = -1;
//                    break;
//                }
//                t *= p[j];
//                s ++ ;
//            }
//
//        if (t != -1)
//        {
//            if (s % 2) res += n / t;
//            else res -= n / t;
//        }
//    }
//
//    cout << res << endl;
//
//    return 0;
//}
#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<map>
#define debug(a) cout << "*" << a << "*" << endl
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<map>
#define debug(a) cout << "*" << a << "*" << endl
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
int f[10005][10005], n, m, t;
void print(int n, int m)
{
    for (int i = 1; i <= n / m * m; i++)
        printf(" %d", m);
    if (n % m == 0) return;
    else print(m, n % m);
}
int dfs(int n, int m)
{
    if (m == 0) return 0;
    if (f[n][m])
        return f[n][m];
    else
        return f[n][m] = n / m * m + dfs(m, n % m);
}
int main()
{
    //for (int )
    for (int i = 1; i <= 10000; i++)
        f[i][1] = i;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        if (n < m)
            swap(n, m);
        printf("%d\n", dfs(n, m));
        printf("%d", m);
        for (int i = 1; i < n / m * m; i++)
            printf(" %d", m);
        if (n % m != 0)
            print(m, n % m);
        printf("\n");
    }
}
