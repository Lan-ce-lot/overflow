/*************************************************************************
 > FileName:
 > Author:      huangchangsheng
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description:
 ************************************************************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <cmath>
#include <sstream>
using namespace std;
typedef long long ll;
const double pi = acos(-1.0);
const int eps = 1e-10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;                             //int2147483647 ll9e18 unsigned ll 1e19
const int maxn = 1005;
int a[maxn];
int G[maxn][maxn], Nv, Ne;
void BuildGraph()
{
    int i, j, v1, v2, w;

    scanf("%d", &Nv);
    //CreateGraph
    for (i = 0; i < Nv; i++)
        for (j = 0; j < Nv; j++)
            G[i][j] = 0;

    scanf("%d", &Ne);
    for (i = 0; i < Ne; i++)
        scanf("%d%d%d", &v1, &v2, &w);
    //InsertEdge
    G[v1][v2] = w;
    G[v2][v1] = w;
}

int main()
{

    return 0;
}

