/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description: hdu1285ȷ����������
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
const int maxn = 1005;

int G[maxn][maxn];
int degree[maxn];//���
int topo[maxn];
void topological_sort(int n)
{
    memset(topo, 0, sizeof(topo));
    int i, j, k, co = 0;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (degree[j] == 0)     //�ҵ����Ϊ0�Ķ���
            {
                topo[co++] = j;
                degree[j]--;
                k = j;              //��k��¼�˶���
                break;
            }
        }
        for (j = 1; j <= n; j++)
        {
            if (G[k][j] == 1)       //�ҵ����˶����ܹ��Ķ���
            {
                G[k][j] = 0;        //��ɾ��
                degree[j]--;        //���ҵ��Ķ������ȼ�һ
            }
        }
    }
}

int t, n, m;
int main()
{
//    ios::sync_with_stdio(false);
    while (~scanf("%d%d", &n, &m))
    {
        memset(G, 0, sizeof(G));
        memset(degree, 0, sizeof(degree));
        while (m--)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            if (G[x][y] == 0)//���ﲻ�ܸģ����Թ���
            {
                G[x][y] = 1;
                degree[y]++;
            }
        }
        topological_sort(n);
        for (int i = 0; i< n; i++)
            printf(i == n - 1 ? "%d\n": "%d ", topo[i]);
    }
    return 0;
}
//124MS	5336K
