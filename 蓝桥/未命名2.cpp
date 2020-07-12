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
int main()
{
	double N=9.1227;
	double a,b;
	int i=0;
	while(scanf("%lf",&a))
	{
		printf("%.3lf\n",(N-a)*(N-a));
	 } 
	while(~scanf("%lf%lf",&a,&b))
	{
		i++;
		printf("%d:%lf-%lf=%.3lf\n",i,max(a,b),min(a,b),fabs(b-a));
	}
	return 0;
}
