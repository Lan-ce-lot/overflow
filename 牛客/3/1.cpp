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
struct s{
	int sj,p;
}a[100005];
bool cmp(s a,s b){
	return (double)a.p/(double)a.sj>(double)b.p/(double)b.sj;
}
int main()
{
	ll t;
	ll sum=0,ans=0;
	scanf("%lld",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%lld%lld",&a[i].sj,&a[i].p);
		sum+=a[i].p;
	}
	sort(a,a+t,cmp);
	for(int i=0;i<t-1;i++)
	{
		sum-=a[i].p;
		ans+=(sum*a[i].sj);
	}
	printf("%lld\n",ans);
	return 0;
}
