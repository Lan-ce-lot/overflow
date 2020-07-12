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
int x[105],y[105];
double s[1000000];
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int t,z,b,con=0;
		scanf("%d%d",&t,&z);
		for(int i=0;i<t;i++)
		{
			scanf("%d%d",&x[i],&y[i]);
		}
		for(int i=0;i<t-2;i++)
		{
			for(int j=i+1;j<t-1;j++)
			{
				for(int o=j+1;o<t;o++)
				{
					s[con]=abs(x[i]*(y[j]-y[o])+x[j]*(y[o]-y[i])+x[o]*(y[i]-y[j]))*0.5;
					con++;
				}
			}
		}
		sort(s,s+con,greater<double>());
		printf("%.2lf\n",s[z-1]);
	}
	return 0;
}
