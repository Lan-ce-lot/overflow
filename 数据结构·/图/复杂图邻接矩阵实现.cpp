/*************************************************************************
 > FileName:
 > Author:      HuangChangsheng
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description: Realization of Graph
 ************************************************************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <cstdlib>
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

const int MaxVertexNum = maxn;
typedef int WeightType;
typedef int Vertex;//顶点
typedef struct GNode *MGraph;
struct GNode
{
    int Nv;//顶点数
    int Ne;//边数
    WeightType G[MaxVertexNum][MaxVertexNum];
};



MGraph CreateGraph(int VertexNum)
{
    Vertex V, W;
    MGraph Graph;

    Graph = (MGraph)malloc(sizeof(struct GNode));
    Graph->Nv = VertexNum;
    Graph->Ne = 0;
    for (V = 0; V < Graph->Nv; V++)
        for (W = 0; W < Graph->Nv; W++)
            Graph->G[V][W] = 0;
    return Graph;
}

typedef struct ENode *Edge;
struct ENode
{
    Vertex V1, V2;    //有向边<V1, V2>
    WeightType Weight;//权重
};

void InsertEdge(MGraph Graph, Edge E)
{
    Graph->G[E->V1][E->V2] = E->Weight;//插入边<V1, V2>
    Graph->G[E->V2][E->V1] = E->Weight;//无向图还要<V2, V1>
//    cout << E->V1 << E->V2;
}

/*
input case:
Nv Ne
V1 V2 Weight
*/

void PrintGraph(MGraph Graph)
{
	puts("");
	for (int i = 1; i <= Graph->Nv; i++)
	{
		for (int j = 1; j <= Graph->Nv; j++)
		{
			j == Graph->Nv?printf("%d\n", Graph->G[i][j]):printf("%d ", Graph->G[i][j]);
		}
	}
}

MGraph BuildGraph()
{
    MGraph Graph;
    Edge E;
    Vertex V;
    int Nv, i;

    scanf("%d", &Nv);
    Graph = CreateGraph(Nv);
    scanf("%d", &(Graph->Ne));
    if (Graph->Ne != 0)
    {
        E = (Edge)malloc(sizeof(struct ENode));
        for (i = 0; i < Graph->Ne; i++)
        {
            scanf("%d%d%d", &E->V1, &E->V2, &E->Weight);
            InsertEdge(Graph, E);
        }
        PrintGraph(Graph);
        //      for (V = 0; V < Graph->Nv; V++)//如果顶点有数据
        //           scanf("%d" , &(Graph->Data[V]));
        return Graph;
    }
    
}



int main()
{
    BuildGraph();
    return 0;
}
