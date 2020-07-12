#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
#define PI 3.1415927
#define M(a) memset(a, 0, sizeof(a))
const int INF = 0x3f3f3f3f;
char map[105][105];
int vis[105][105];
int m, n, u, v;
struct node
{
	int x, y, step;

} s, no;
int X[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int Y[8] = {0, -1, -1, -1, 0, 1, 1, 1};
bool in(int x, int y)
{
	return 0 <= x && x < n && 0 <= y && y < m && map[x][y] != '*';
}
int bfs()
{
	int ans = 0;
	queue<node> q;
	q.push(s);
	map[s.x][s.y] = '*';
	while (!q.empty())
	{
		node top = q.front();
		q.pop();
		for (int i = 0; i < 8; i++)
		{
			int x1 = top.x + X[i];
			int y1 = top.y + Y[i];
			if (in(x1, y1))
			{
				no.x = x1, no.y = y1;
				q.push(no);
				vis[x1][y1] = vis[top.x][top.y] + 1;
				map[x1][y1] = '*';
				ans = max(vis[x1][y1], ans);
			}
		}
	}
	return ans;
}
int main()
{
	scanf("%d%d%d%d", &m, &n, &s.y, &s.x);

	for (int i = 0; i < n; i++)
	{
		scanf("%s", map[i]);
	}
	s.y -= 1;
	s.x -= 1;
	s.x = n - s.x - 1;
	printf("%d\n", bfs());
	return 0;
}
