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
using namespace std;
const int maxn=105;
bool vis[maxn][maxn]; // ���ʱ��
int map[maxn][maxn]; // ���귶Χ
int dir[4][2]={0,1,0,-1,1,0,-1,0}; // ����������(x,y)��Χ���ĸ�����

bool test(int x,int y) // �߽�������Լ���������ж�
{
	if(!vis[x][y] && x >= 0 && y >= 0 && y < m&& x < n) // ��������
		return 1;
	else // ��Լ��������ͻ
		return 0;
}

void dfs(int x,int y)
{
	vst[x][y]=1; // ��Ǹýڵ㱻���ʹ�
	if(map[x][y]==G) // ����Ŀ��̬G
    {

		return;
    }
	for(int i=0;i<4;i++)
	{
		if(test(x+dir[i][0],y+dir[i][1])) // ���չ���������һ���ڵ�
			dfs(x+dir[i][0],y+dir[i][1]);
	}
	return; // û���²������ڵ㣬����
}
int main()
{

return 0;
}
