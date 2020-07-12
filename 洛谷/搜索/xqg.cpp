#include<iostream>
#include<cstring>
#include<queue>
#include<cstdlib>
#include<cmath>
using namespace std;

const int maxn = 50 + 5;
const char *dirs = "NESW";

inline int dir_id(char c)
{
    return strchr(dirs, c) - dirs;
}

struct Node
{
    int x, y, dir, d;
};

inline void turn(Node &u, int t)
{
    if(t == 1)
    {
        u.dir = (u.dir + 3) % 4;
    }
    if(t == 2)
    {
        u.dir = (u.dir + 1) % 4;
    }
}

int n, m, aim_x, aim_y, f_x, f_y;
char f_dir;
int G[maxn][maxn];
int vis[maxn][maxn][4];
queue<Node> q;

inline bool inside(int x, int y)  //nm不可达
{
    return x >= 1 && x < n && y >= 1 && y < m  && !G[x][y] && !G[x + 1][y] && !G[x + 1][y + 1] && !G[x][y + 1];
}
inline void if_print(int x, int y, int d)
{
    if(x == aim_x && y == aim_y)
    {
        cout << d;
        exit(0);
    }
}
inline bool check_road(int fr_x, int fr_y, int e_x, int e_y) //检查路径而不能只检查起始点
{
    int dx = e_x - fr_x, dy = e_y - fr_y;
    if(dx != 0) dx = dx / (abs(dx));
    if(dy != 0) dy = dy / (abs(dy));
    int x = fr_x, y = fr_y;
    while(x != e_x || y != e_y)
    {
        if(!inside(x, y)) return false;
        x += dx;
        y += dy;
    }
    return inside(x, y);
}
void bfs()
{
    q.push((Node)
    {
        f_x, f_y, dir_id(f_dir), 0
    });
    vis[f_x][f_y][dir_id(f_dir)] = 1;
    while(!q.empty())
    {
        Node u = q.front();
        q.pop();
        int x = u.x, y = u.y, dir = u.dir, d = u.d;
        Node u1 = u;
        u1.d++;
        turn(u1, 1);
        if(!vis[x][y][u1.dir])
        {
            vis[x][y][u1.dir] = 1;
            q.push(u1);
        }
        u1 = u;
        u1.d++;
        turn(u1, 2);
        if(!vis[x][y][u1.dir])
        {
            vis[x][y][u1.dir] = 1;
            q.push(u1);
        }

        for(int s = 1; s <= 3; s++)
        {
            if(dir == 0 && check_road(x, y, x - s, y) && !vis[x - s][y][dir])
            {
                vis[x - s][y][dir] = 1;
                q.push((Node)
                {
                    x - s, y, dir, d + 1
                });
                if_print(x - s, y, d + 1);
            }
            if(dir == 1 && check_road(x, y, x, y + s) &&  !vis[x][y + s][dir])
            {
                vis[x][y + s][dir] = 1;
                q.push((Node)
                {
                    x, y + s, dir, d + 1
                });
                if_print(x, y + s, d + 1);
            }
            if(dir == 2 && check_road(x, y, x + s, y) && !vis[x + s][y][dir])
            {
                vis[x + s][y][dir] = 1;
                q.push((Node)
                {
                    x + s, y, dir, d + 1
                });
                if_print(x + s, y, d + 1);
            }
            if(dir == 3 && check_road(x, y, x, y - s) && !vis[x][y - s][dir])
            {
                vis[x][y - s][dir] = 1;
                q.push((Node)
                {
                    x, y - s, dir, d + 1
                });
                if_print(x, y - s, d + 1);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)  for(int j = 1; j <= m; j++) cin >> G[i][j];
    cin >> f_x >> f_y >> aim_x >> aim_y >> f_dir;
	if (f_x == aim_x && f_y == aim_y)
	{
		cout << 0;
		return 0;
	}
    bfs();
    cout << -1;

    return 0;
}
