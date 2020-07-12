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
const int maxn = 105;
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
bool vis[maxn];

bool dfs(int now, int l, int k) {
    if (now == l && k == 0) return 1;
    if (now == l) now = 0;

    for (int i = 0; i < n; i++) {
        if (!vis[i] && now + a[i] <= l) {
            vis[i] = 1;
            if (dfs(now + a[i], l, k - 1)) return 1;
            vis[i] = 0;
            if (a[i] + now == l || now == 0) return 0;
        }
    }
    return 0;
}



void solve()
{
    while (cin >> n, n) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            a[i] = read();
            sum += a[i];
        }

        sort(a, a + n, greater<int>());

        for (int i = a[0]; i <= sum; i++) {
            memset(vis, 0, sizeof vis);
            if (sum % i == 0) {if (dfs(0, i, n)) {cout << i << endl;break;}}
        }
    }
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

//#include <iostream>
//#include <algorithm>
//#include<cstring>
//#define ll long long
//using namespace std;
////dfs(s,len,k)表示当前有k根小木棍要凑成长度为len的大木棍，当前已经凑成的量是s
//int n,a[100],visit[100];
//
//bool dfs(int s,int len,int k)
//{
//	if(s==len&&k==0)
//		return true;
//	if(s==len)
//		s=0;
//	for(int i=1;i<=n;++i)
//	{
//		if(!visit[i]&&s+a[i]<=len)
//		{
//			visit[i]=1;
//			if(dfs(s+a[i],len,k-1))
//				return true;
//			visit[i]=0;
//			if(s+a[i]==len)
//				return false;
//			if(s==0)
//				return false;
//		}
//	}
//	return false;
//}
//
//int main()
//{
//	while(scanf("%d",&n)&&n)
//	{
//		int sum=0;
//		for(int i=1;i<=n;++i)
//			scanf("%d",&a[i]),sum+=a[i];
//		sort(a+1,a+1+n);
//		reverse(a+1,a+1+n);
//		for(int i=a[1];i<=sum;++i)
//		{
//			memset(visit,0,sizeof(visit));
//			if(sum%i==0&&dfs(0,i,n))
//			{
//				printf("%d\n",i);
//				break;
//			}
//		}
//	}
//	return 0;
//}
