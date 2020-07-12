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
const double eps = 1e-10;
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
//高斯消元解方程组
//a[][]装矩阵系数和等式右边的值
//==============================================================
double a[110][110];
int gauss()
{
    int c, r;//c列,r行
    for (c = 0, r = 0; c < n; c++)//枚举每一列c
    {
        int t = r;
        for (int i = r; i < n; i++)//找绝对值最大行
            if (fabs(a[i][c]) > fabs(a[t][c]))
                t = i;

        if (fabs(a[t][c]) < eps) continue;

        for (int i = c; i <= n; i++) swap(a[t][i], a[r][i]);//最大行换到第r行
        for (int i = n; i >= c; i--) a[r][i] /= a[r][c];//将该行每个数除第c个数
        for (int i = r + 1; i < n; i++)//将下面所有行第c个消成0
            if (fabs(a[i][c]) > eps)
                for (int j = n; j >= c; j--)
                    a[i][j] -= a[r][j] * a[i][c];
        r++;
    }

    if (r < n)
    {
        for (int i = r; i < n; i++)
            if (fabs(a[i][n]) > eps)
                return 2;//无解
        return 1;//无穷解
    }

    for (int i = n - 1; i >= 0; i--)//完美阶梯型化简
        for (int j = i + 1; j < n; j++)
            a[i][n] -= a[i][j] * a[j][n];

    return 0;//唯一解
}







//==============================================================
void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            cin >> a[i][j];
        }
    }
    int t = gauss();
    if (t == 0)
    {
        for (int i = 0; i < n; i++)
        {
            printf("%.2f\n", a[i][n]);
        }
    }
    else if (t == 1)
    {
        puts("Infinite group solutions");
    }
    else
    {
        puts("No solution");
    }
}

int main()
{
    solve();
//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    return 0;
}

