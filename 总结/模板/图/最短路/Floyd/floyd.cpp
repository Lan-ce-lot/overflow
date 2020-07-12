/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description: floyd，用的邻接矩阵
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
int t, n, m;//n点，m边

void floyd()
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (G[i][j] > G[i][k] + G[k][j])
                    G[i][j] = G[i][k] + G[k][j];
}

int main()
{
//    ios::sync_with_stdio(false);
    while (~scanf("%d%d", &n, &m))
    {
        if (n == 0 && m == 0)
            break;
        fill(G[0], G[0] + maxn * maxn, INF);
        for (int i = 0; i < m; i++)
        {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            if (c < G[a][b])
                G[b][a] = G[a][b]= c;
        }
        floyd();
        printf("%d\n", G[1][n]);
    }
    return 0;
}
//46MS	5328K
