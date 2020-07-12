#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<algorithm> 
#include<vector> 
using namespace std;
typedef unsigned long long ll;
#define PI 3.1415927
#define M(a) memset(a,0,sizeof(a))
const int INF=0x3f3f3f3f;
const int MOD=1e9+7;

ll a[1005];
int main()
{	
	int n,m;
	scanf("%d%d",&n,&m);
	a[1]=1;
	for(int i=2;i<=n;i++)
	{
		a[i]=a[i-1]*2%MOD+2;
	}
	while(m--)
	{
		int a1=0,a2=0;ll ans=0;
		scanf("%d%d",&a1,&a2);
		for(int i=a1;i<=a2;i++)
		{
			ans+=a[i];
			ans%=MOD;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
