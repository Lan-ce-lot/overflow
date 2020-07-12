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
const int maxn = 1000001;

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
map<int, int> M;
void solve()
{
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        M[a[i]]++;
        sum += a[i];

    }//0->10 2 3 4 5 6 7 8 9 11 12 13 14 15 16 17 18 19
    int temp = sum % 10;
    int ans = 0;
    if(temp == 0)
    {
        temp = 10;
    }
    for (int i = 1; i <= 10; i++ )
    {
        for (int j = 1; j <= 10; j++)
            if (M[i] && M[j])
        {
            if (i == j && M[i] > 1 && temp == (i + j) || temp + 10 == i + j)
            {
                cout << temp << endl;return;
            }
            else if (i != j && temp == (i + j) || temp + 10 == i + j)
            {
                cout << temp << endl;return;
            }
        }
    }
    cout << 0 << endl;

}

int main()
{
    solve();
//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    return 0;
}

