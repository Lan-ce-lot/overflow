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
	int n,a[10005],p,q,AND=INF,OR=0,XOR=0;
	while(~scanf("%d%d",&n,&p))
	{
		AND=INF,OR=0,XOR=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);	
			AND&=a[i];	
		}
		for(int i=0;i<p;i++)
		{
			
			scanf("%d",&q);
			
			printf("%d %d %d\n",a[q],a[q],0);
		}
	}
	
	return 0;

}
