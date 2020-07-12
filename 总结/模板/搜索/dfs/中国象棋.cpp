/*************************************************************************
 > FileName:
 > Author:      huangchangsheng
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description:
 ************************************************************************/
/*
该DFS 框架以2D 坐标范围为例，来体现DFS 算法的实现思想。
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
const int maxn=105;
bool vis[maxn][maxn]; // 访问标记
char map[maxn][maxn]; // 坐标范围
int dir[8][2]={{2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}}; // 方向向量，(x,y)周围的四个方向

bool test(int x, int y) // 边界条件和约束条件的判断
{
	if(!vis[x][y] && x >= 0 && y >= 0 && y < 9&& x < 10 && map[x][y] != '#') // 满足条件
		return 1;
	else // 与约束条件冲突
		return 0;
}
int flag = 0;
void dfs(int x, int y)
{
	vis[x][y]=1; // 标记该节点被访问过
	if(map[x][y]=='T') // 出现目标态G
    {
        flag = 1;
		return;
    }
	for(int i=0;i<8;i++)
	{
		if(test(x+dir[i][0],y+dir[i][1])) // 按照规则生成下一个节点
			dfs(x+dir[i][0],y+dir[i][1]);
	}
	return; // 没有下层搜索节点，回溯
}
int sx, sy;
int main()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 'S')
                sx = i, sy = j;
        }
    }
    dfs(sx, sy);
    puts(flag?"Yes":"No");
    return 0;
}
