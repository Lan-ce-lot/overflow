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
//==============================================================
//�й�ʣ�ඨ��
//1.exgcd��gcd�����Է��̵���������
//2.���ϱ���
//3.
//==============================================================
ll x = 0, m[maxn], a[maxn];
ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if (!b)
    {
        x = 1, y = 0;
        return a;
    }

    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
//m[]����ģ����a[]����
ll china(int n, ll *m, ll *a)
{
    ll M = 1, d, y, x, sum = 0;

    //�������Գ����Ļ�M��Ҳ�����Գ�������С������
    for (int i = 0; i < n; i++)
        M *= m[i];

    for (int i = 0; i < n - 1; i++)
    {
        //�����ȥ��������г����Ļ�w
        ll w = M / m[i];
        //����m[i]*x+w*y=gcd(m[i],w)��һ����y
        d = exgcd(m[i], w, x, y);
        if ((a[i] - a[i + 1]) % d)
        {
        	cout << a[i] << i << d<<endl;
        	puts("-1");
        	return -1;
		}
        //�ۼ�������y��ͬ�����϶�Mȡ�࣬�����ù�ʽ:
        //(a+b)%c=(a%c+b%c)%c
        sum = (sum + y * w * a[i]) % M;
    }
    return (M + sum) % M;//�������Է��̵���С��
}

void solve()
{
    cin >> n;
//    n = 3;
//    m[0] = 23;
//    m[1] = 233;
//    m[2] = 2333;

    for (int i = 0; i < n; i++)
        cin >> m[i] >> a[i];
	if (china(n, m, a) != -1)
	{
		cout << china(n, m, a) << endl;
	}
    
    return ;
}

int main()

{
    solve();
//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    return 0;
}
