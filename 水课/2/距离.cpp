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
#define M(a) memset(a,0x3f,sizeof(a))
const int INF=0x3f3f3f3f;	int a[3000][3000],x,y,z;
int main()
{

	M(a);
	for(int i=0;i<19;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		a[x][y]=a[y][x]=z;
	 } 
	for(int k=1;k<=20;k++)
	{
		for(int i=1;i<=20;i++)
		{
			for(int j=0;j<=20;j++)
			{
				a[i][j]=min(a[i][k]+a[k][j],a[i][j]);
			}
		 } 
	}
	int sum=0;
	for(int i=1;i<=20;i++)
	{
		for(int j=i+1;j<=20;j++)
		{
			sum+=a[i][j];
		}
	}
	printf("%d\n",sum);
//	system("pause");
	return 0;

}

