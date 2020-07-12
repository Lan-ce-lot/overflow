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
const double pi = acos(-1.0);
const int eps = 1e-10;
const int mod = 1e9 + 7;
#define debug(a) cout << "*" << a << "*" << endl
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 105;
char maze[maxn][maxn];
bool vis[maxn][maxn];
int t, n, m;
int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
int temp = 0, ans = 0;
int sx[maxn], sy[maxn];
int num = 0;

struct node
{
    int x, y, step;
    node(int xx = 0, int yy = 0, int ss = 0) : x(xx), y(yy), step(ss) {}
};

bool test(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m || maze[x][y] != '#' || vis[x][y])
        return 0;
    return 1;
}

void bfs(int x, int y, int xx, int yy)
{
    queue<node> q;
    q.push(node(x, y, 0));
    q.push(node(xx, yy, 0));
    vis[x][y] = 1;
    vis[xx][yy] = 1;
    node top;
    int s = 0;
    while (!q.empty())
    {
        top = q.front();
        if (top.step >= temp)
            return;
        q.pop();
        for (int i  = 0; i < 4; i++)
        {
            if (test(top.x + dir[i][0], top.y + dir[i][1]))
            {
                vis[top.x + dir[i][0]][top.y + dir[i][1]] = 1;
                q.push(node(top.x + dir[i][0], top.y + dir[i][1], top.step + 1));
            }
        }
    }
    for (int i = 0; i < num; i++)
    {
        if (!vis[sx[i]][sy[i]])
            return;
    }
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < m; j++)
//        {
//            if (maze[i][j] == '#' && vis[i][j] == 0)
//            {
//                return ;
//            }
//        }
//    }
    temp = min(temp, top.step);
}


void solve()
{
    cin >> t;
    int con = 0;
    while (t--)
    {
        con++;
        temp = 100000000;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++)
            scanf("%s", maze[i]);
        num = 0;
        for (int i = 0,coo = 0; i < n ; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (maze[i][j] == '#')
                {
                    sx[coo] = i;
                    sy[coo++] = j;
                    num++;
                }
            }
        }
        for (int i = 0; i < num; i++)
        {
            for (int j  = 0; j < num; j++)
            {
                memset(vis, 0, sizeof(vis));
                bfs(sx[i], sy[i], sx[j], sy[j]);
            }
        }
        cout << "Case " << con << ": ";
        if (temp == 100000000)
        {
            temp = -1;
        }
        cout << temp << endl;
    }
}
int main()
{
//    ios::sync_with_stdio(false);
    solve();

    return 0;
}

//#include <cstdio>
//#include <cstring>
//#include <queue>
//#include <iostream>
//using namespace std;
//const int N = 10;
//int vis[N][N], t, n, m, sx[100], sy[100], cnt, num, ans, temNum;
//char g[N][N], tem[N][N];
//int dx[4] = {1, 0, 0, -1};
//int dy[4] = {0, 1, -1, 0};
//struct node{
//	int x, y;
//	node(int x, int y): x(x), y(y){}
//};
//bool ok(int x, int y) {
//	if(x < 0 || y < 0 || x >= n || y >= m || tem[x][y] == '.' || vis[x][y]) return false;
//	return true;
//}
//void bfs(int sx1, int sy1, int sx2, int sy2) {
//	queue<node> q;
//	memcpy(tem, g, sizeof g);
//	memset(vis, 0, sizeof vis);
//	int step = 0;
//	q.push(node(sx1, sy1));
//	q.push(node(sx2, sy2));
//	vis[sx1][sy1] = 1;
//	vis[sx2][sy2] = 1;
//	tem[sx1][sy1] = '.';
//	tem[sx2][sy2] = '.';
//	while (q.size()) {
//		step++;
//		if (step >= ans) return;//小小的剪枝
//		// 将上一秒的全部出队  j = q.size()
//		for (int i = 0, j = q.size(); i < j; i++) {
//			node t = q.front();
//			q.pop();
//			for (int k = 0; k < 4; k++) {
//				int fx = t.x + dx[k];
//				int fy = t.y + dy[k];
//				if (ok(fx, fy)) {
//					vis[fx][fy] = 1;
//					tem[fx][fy] = '.';
//					q.push(node(fx, fy));
//					temNum--;
//					if (temNum == 0) {
//						ans = step;
//						return;
//					}
//				}
//			}
//		}
//	}
//}
//
//int main() {
//	scanf("%d", &t);
//	for (int ci = 1; ci <= t; ci++) {
//		scanf("%d%d", &n, &m);
//		for (int i = 0; i < n; i++) {
//			scanf("%s", g[i]);
//		}
//		cnt = 0; num = 0;
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < m; j++) {
//				if (g[i][j] == '#') {
//					//记录一下#的位置
//					sx[cnt] = i;
//					sy[cnt++] = j;
//					num++; //记录个数
//				}
//			}
//		}
//		//遍历所有的情况
//		ans = 1000;
//		num -= 2;
//		if (num > 0) {
//			//暴力枚举2个起点所在位置
//			for (int i = 0; i < cnt; i++) {
//				for (int j = i + 1; j < cnt; j++) {
//					temNum = num;
//					bfs(sx[i], sy[i], sx[j], sy[j]);
//				}
//			}
//			printf("Case %d: %d\n", ci, ans == 1000 ? -1 : ans);
//		} else {
//			printf("Case %d: 0\n", ci);
//		}
//	}
//	return 0;
//}
