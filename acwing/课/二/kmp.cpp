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
const int eps = 1e-10;
const int mod = 1e9 + 7;
#define debug(a) cout << "*" << a << "*" << endl
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 100005;

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
int t, n, len1, len2, k;
int ne[maxn];
char s1[maxn];
char p[maxn];//模板串

void get_next()
{
    int t1 = 0, t2;
    ne[0] = t2 = -1;
    while (t1 < len2)
    {
        if (t2 == -1 || p[t1] == p[t2]) ne[++t1] = ++t2;
        else t2 = ne[t2];
    }
}

void KMP()
{
    int t1 = 0, t2 = 0;
    while (t1 < len1)
    {
        if (t2 == -1 || s1[t1] == p[t2]) t1++, t2++;
        else t2 = ne[t2];
        if (t2 == len2) printf("%d ", t1 - len2 + 1 - 1), t2 = ne[t2];
    }
}

int KMP_Count(char x[], int m, char y[], int n)//x 是模式串，y 是主串
{
    int i, j;
    int ans = 0;
    i = j = 0;
    while (i < n)
    {
        if (j == -1 || y[i] == x[j]) i++, j++;
        else j = ne[j];
        if (j >= m)
        {
            ans++;
            j = ne[j];
        }

//        while (j != -1 && y[i] != x[j]) j = ne[j];
//        i++, j++;
//        if (j >= m)
//        {
//            ans++;
//            j = ne[j];
//        }
    }
    return ans;
}

void solve()
{
    cin >> len2 >> p >> len1 >> s1;

    get_next();
    KMP();
//    for (int i = 0; i <= len2 ; i++) cout << ne[i] << ' ';
}

int main()
{
    solve();
//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    return 0;
}

