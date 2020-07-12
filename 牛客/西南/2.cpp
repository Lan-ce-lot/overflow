#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<algorithm> 
using namespace std;
typedef long long ll;
#define PI 3.1415927
#define M(a) memset(a,0,sizeof(a))
const int INF=0x3f3f3f3f;
int main()
{
	int n,u[4],d[4],a[6]={0},t=0;
	scanf("%d",&n);
	while(n--)
	{
		for(int i=0;i<4;i++)
		{
			scanf("%d",&u[i]);
			u[i]?a[5]=u[i]:i;

		}
		for(int i=0;i<4;i++)
			scanf("%d",&a[i]);
		for(int i=0;i<4;i++)
		{
			scanf("%d",&d[i]);d[i]?a[4]=d[i]:i;

		}
			
		if(a[5]==a[4]&&a[0]==a[2]&&a[1]==a[3])
		puts("Yes!");
		else
		puts("No!");
		t++;
		if(t%50==0)printf("\n");
	}
//	system("pause");
	return 0;

}
