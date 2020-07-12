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
#define lowbit(x) x & -x
const double pi = acos(-1.0);
const double eps = 1e-6;
const int mod = 1e9 + 7;
#define debug(a) cout << "*" << a << "*" << endl
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 1000005;
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
int t, n, m;
struct Node {
    bool l, u, r, d;//1表示西墙，2表示北墙，4表示东墙，8表示南墙
}node[2005][2005];

int maze[2005][2005];
bool vis[2005][2005];

bool test(int x, int y) {
    if (vis[x][y] || x < 1 || y < 1 || x > n || y > m)
        return 1;
    return 0;
}
//bool dfs(int x, int y) {
//    if (test(x, y)) {
//        return 0;
//    }
//    vis[x][y] = 1;
//    if (!node[x][y].l) {
//        return dfs(x, y - 1) + 1;
//    } else if (!node[x][y].u){
//        return dfs(x - 1, y) + 1;
//    } else if (!node[x][y].r) {
//        return dfs(x, y + 1) + 1;
//    } else if (!node[x][y].d) {
//        return dfs(x + 1, y) + 1;
//    }
//
//}
int sum = 0;
void dfs(int x, int y) {
    if (test(x, y)) {
//            cout << sum <<endl;
        return;
    }
    vis[x][y] = 1;
    sum++;
    if (!node[x][y].l) {
//        debug('l');
        dfs(x, y - 1);
    }if (!node[x][y].u){
//        debug('u');
        dfs(x - 1, y);
    }if (!node[x][y].r) {
//        debug('r');
        dfs(x, y + 1);
    }if (!node[x][y].d) {
//        debug('d');
        dfs(x + 1, y);
    }
}
void solve()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &maze[i][j]);
            int temp = maze[i][j];
            while (temp) {
                int lo = lowbit(temp);
                if (lo == 1) {
                    node[i][j].l = 1;
                } else if (lo == 2) {
                    node[i][j].u = 1;
                } else if (lo == 4) {
                    node[i][j].r = 1;
                } else if (lo == 8){
                    node[i][j].d = 1;
                }
                temp -= lo;
            }
        }
    }

//        for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= m; j++) {
//            printf("%d %d %d %d %d %c", node[i][j].l, node[i][j].u, node[i][j].r, node[i][j].d, maze[i][j], j == m?'\n':' ');
//
//        }
//    }
    int count1 = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            sum = 0;
            dfs(i, j);
            if (sum) {
                count1 ++;
            }
            ans = max(ans, sum);
        }
    }
    cout << count1 << endl << ans << endl;


}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

