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
const int INF=0x3f3f3f3f;
int main()
{
	int n,m,d,q;
	
	scanf("%d%d%d",&n,&m,&d);
	int a[n][m],b[n][m]={0};
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d",&a[i][j]);
			a[i][j]>=d?a[i][j]++:a[i][j]==0;
		}
	}

	scanf("%d",&q);
	while(q--)
	{
		int a,b,x,y ;
		scanf("%d%d%d%d",&a,&b,&x,&y);
		
	}

//	system("pause");
	return 0;

}
