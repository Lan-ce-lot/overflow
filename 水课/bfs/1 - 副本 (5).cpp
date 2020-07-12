#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<algorithm> 
#include<queue>
using namespace std;
typedef long long ll;

#define PI 3.1415927
#define M(a) memset(a,0,sizeof(a))
const int INF=0x3f3f3f3f;
int map[3][3];
int 
int bfs()
{
	
}
int main()
{
	int a1,a2,a3;
	
	scanf("%d%d%d",&a1,&a2,&a3);
	for(int i=0;i<3;i++)
	{
		map[0][i]=a1%10;
		a1/=10;
	}
	for(int i=0;i<3;i++)
	{
		map[1][i]=a2%10;
		a2/=10;
	}
		for(int i=0;i<3;i++)
	{
		map[2][i]=a3%10;
		a3/=10;
	}
	bfs();	
	return 0;
 } 
