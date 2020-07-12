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
int t, n, m, q_x1, q_y1, q_x2, q_y2;
int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
string maze[205];
bool vis[205][205];
struct node
{
	int x, y, st;
};

vector<int> dir_x[maxn][maxn], dir_y[maxn][maxn];
void init()
{
	for (int x = 0; x <= n + 1; x++)
	{
		for (int y = 0; y <= m + 1; y++)
		{
			dir_x[x][y].clear();
			dir_y[x][y].clear();
			
			
			for (int i = 0; i < 4; i++)
			{
				int nx = x + dir[i][0];
				int ny = y + dir[i][1];
				while (nx >= 0 && nx <= n + 1 && ny >= 0 && ny <= m + 1 && maze[nx][ny] != 'X')
				{
					dir_x[x][y].push_back(nx);
					dir_y[x][y].push_back(ny);//cout << nx << ' ' << ny << endl;
					nx += dir[i][0];
					ny += dir[i][1]; 
					
				}
				//puts("");
			}
		}
	}
}




int bfs(int x, int y)
{
	memset(vis, 0, sizeof vis);
	queue<node> Q;
	Q.push({x, y, 0});
	while (!Q.empty())
	{
		
		node top = Q.front();
		//cout << top.x << ' ' << top.y << ' ' << top.st << endl;
		if (top.x == q_x2 && top.y == q_y2)
		{
			return top.st;
		}
		vis[top.x][top.y] = 1;
		Q.pop();
		
		for (int i = 0; i < dir_x[top.x][top.y].size(); i++)
		{
			int xx = dir_x[top.x][top.y][i];
			int yy = dir_y[top.x][top.y][i];
//			cout << xx << ' ' << yy << endl;
			if ( xx >= 0 && xx <= n + 1 && yy >= 0 && yy <= m + 1 && (!vis[xx][yy]) && maze[xx][yy] != 'X')
			{
				
				Q.push({xx, yy, top.st + 1});
				vis[xx][yy] = 1;
			}
		}//puts("");
	}
	return 0;
}



void solve()
{
	int cc = 0;
	while (cin >> m >> n)//n
	{
		cc++;
		char c = getchar();
		if (n == 0 && m == 0)
		{
			return;
		}
		
		for (int i = 1; i <= n; i++)
		{
			getline(cin, maze[i]);
//			cin >> maze[i] + 1;
		}
		maze[0].assign(m, ' '); 
		maze[n + 1].assign(m, ' ');
		for (int i = 1; i <= n; i++)//l, r
		{
			maze[i] = ' ' + maze[i] + ' ';
		}
		
//		for (int i = 0; i <= n + 1; i++)
//		{
//			cout << maze[i] << endl;
//		}
		
		
		
		cout << "Board #" << cc << ':' << endl;
		
		int con = 0;
		while (cin >> q_y1 >> q_x1 >> q_y2 >> q_x2)
		{
			con++;
			
			
			if (q_x1 == 0 && q_y1 == 0 && q_x2 == 0 && q_y2 == 0)
			{
				break;
			}
			cout << "Pair " << con << ": ";
			maze[q_x2][q_y2] = ' '; 
			init();
//			for (int i = 0; i <= n + 1; i++)
//			{
//				
//				for (int j = 0; j <= m + 1; j++)
//				{
//					for (int k = 0; k <= dir_x[i][j].size(); k++)
//					{
//						cout << dir_x[i][j][k] << ' ' << dir_y[i][j][k] << endl;
//					}
//					puts("");
//				}
//			}
			int res = bfs(q_x1, q_y1);
			if (res)
			{
				cout << res << " segments." <<endl;
			}
			else
			{
				cout << "impossible." << endl;
			}
			maze[q_x2][q_y2] = 'X';
		}
		puts("");
	}
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}
/*
5 4
XXXXX
X   X
XXX X
 XXX 
1 3 5 3

*/
