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
const int mod = 7;
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
//============================================
//矩阵快速幂
//大范围的递推
//矩阵乘法和乘法的相似性
//单位元1->单位矩阵
//复杂度和快速幂类似O(log n)
//============================================

struct mat
{
    int m[maxn][maxn];
    int n;//n阶矩阵
};

mat operator * (mat a, mat b)
{
    mat ret;
    ll x;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
        {
            x = 0;
            for (int k = 0; k < 2; k++)
                x = (x + (ll)a.m[i][k] * b.m[k][j] % mod) % mod;
            ret.m[i][j] = x;
        }
    return ret;
}

mat init_unit(mat A, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                A.m[i][j] = 1;
            else
                A.m[i][j] = 0;

        }
    return A;
}

mat pow_mat(mat a, ll n)
{
    mat ret = init_unit(ret, 2);//单位元
    while (n)
    {
        if (n & 1)
            ret = ret * a;
        a = a * a;
        n >>= 1;
    }
    return ret;
}
void print_mat(mat a)
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << a.m[i][j] << ' ';

        }
        puts("");
    }
}
//============================================
void solve()
{
    int a, b, c;
    while (~scanf("%d%d%d", &a, &b, &n))
    {
        if (a == 0&& b == 0&& n == 0)
            return;
        if(n == 1 || n == 2)
            puts("1");
        else
        {
            mat A, B;
            B.m[0][0] = a;
            B.m[0][1] = b;
            B.m[1][0] = 1;
            B.m[1][1] = 0;
//            A = init_unit(A, 2);
            A = pow_mat(B, n - 2);
//            debuga(A);
            printf("%d\n", (A.m[0][0] + A.m[0][1]) % mod);
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
