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
const int maxn = 5001;
//sacnf("%lf") printf("%f")
ll read()
{
    ll x = 0, f = 1;
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

struct Node
{
    int x, y;
    bool operator<(const Node & rhs) const
    {
        return x < rhs.x || (x == rhs.x && y < rhs.y);
    }
} nodes[maxn];
bool vis[maxn][maxn];
int n, m, p, a;

bool inside(int x, int y)
{
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

void solve()
{
    cin >> n;
    while(n--){
        cin >> a;
        if(a%2) puts("0 0");
        else cout << a/4+(a%4)/2 << ' ' << a/2 << endl;
    }
}

int main()
{

    //    freopen("F:/Overflow/in.txt","r",stdin);
    //    ios::sync_with_stdio(false);
    solve();
    return 0;
}
