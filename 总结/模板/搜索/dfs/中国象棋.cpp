/*************************************************************************
 > FileName:
 > Author:      huangchangsheng
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description:
 ************************************************************************/
/*
��DFS �����2D ���귶ΧΪ����������DFS �㷨��ʵ��˼�롣
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
const int maxn=105;
bool vis[maxn][maxn]; // ���ʱ��
char map[maxn][maxn]; // ���귶Χ
int dir[8][2]={{2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}}; // ����������(x,y)��Χ���ĸ�����

bool test(int x, int y) // �߽�������Լ���������ж�
{
	if(!vis[x][y] && x >= 0 && y >= 0 && y < 9&& x < 10 && map[x][y] != '#') // ��������
		return 1;
	else // ��Լ��������ͻ
		return 0;
}
int flag = 0;
void dfs(int x, int y)
{
	vis[x][y]=1; // ��Ǹýڵ㱻���ʹ�
	if(map[x][y]=='T') // ����Ŀ��̬G
    {
        flag = 1;
		return;
    }
	for(int i=0;i<8;i++)
	{
		if(test(x+dir[i][0],y+dir[i][1])) // ���չ���������һ���ڵ�
			dfs(x+dir[i][0],y+dir[i][1]);
	}
	return; // û���²������ڵ㣬����
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
