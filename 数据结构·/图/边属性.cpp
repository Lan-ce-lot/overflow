#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<algorithm> 
#include<vector> 
using namespace std;
typedef long long ll;
#define PI 3.1415927
#define M(a) memset(a,0,sizeof(a))
const int MAX_N=100000;
const int INF=0x3f3f3f3f;

vector<int> G[MAX_N];
/*����������
struct edge {int to,cost;};
vector<edge> G[MAX_N]; 
*/
int main()
{
	int V,E;
	scanf("%d %d",&V,&E);
	for(int i=0;i<E;i++)
	{
		int s,t;
		scanf("%d %d",&s,&t);
		G[s].push_back(t);
		//���������ͼ������Ҫ�ٴ�t 
	}
	/*
	ͼ�Ĳ��� 
	*/ 

//	system("pause");
	return 0;

}
