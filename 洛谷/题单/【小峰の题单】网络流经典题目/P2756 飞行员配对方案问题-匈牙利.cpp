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
const int maxn = 1e4+5;
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
//int t, n, m, S, T;
//==============================================
int t, n, n1, n2, m;//n1��,n2��
vector<int> G[maxn];
bool vis[maxn];//�ڶ������ϵĵ��Ƿ񱻱�����
int match[maxn];//�±���ƥ��ֵ��

bool find(int x)
{
    for (int i =0; i < G[x].size(); i++)
    {
        int j = G[x][i];
        if (!vis[j])
        {
            vis[j] = 1;
            if (match[j] == 0 || find(match[j]))//δƥ��������λ
            {
                match[j] = x;
                return 1;
            }
        }
    }
    return 0;
}

void solve()
{
    cin >> m >> n;
    int a, b;
    n1 = m, n2 = n - m;
    while (scanf("%d%d", &a, &b)) {
    	if (a == -1 && b == -1) {
    		int ans = 0;
    		for (int i = 1; i <= n1; i++)//ö�ټ���һ�ĵ�
    		{
        		memset(vis, 0, sizeof vis);
        		if (find(i))
            		ans++;
    		}
    		cout << ans << endl;    		
    		
    		for (int i = m + 1; i <= n; i++) {
    			if (match[i]) cout << match[i] << ' ' << i << endl;
			}
    		return;
		}
		G[a].push_back(b);
	}
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

