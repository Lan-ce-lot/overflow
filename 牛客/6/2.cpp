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
	ll n,m,d,x;double t1,t2,t3;
	scanf("%lld%lld%lld%lld",&n,&m,&d,&x);
	//t*n+(t-1)*t*d/2-m>=0;
	if(d==0)
	{
		t1=(double)m/n;
		printf("%lld\n",t1>(ll)t1?(ll)t1+1:(ll)t1);
		return 0;
	}
	double a=(double)d/2,b=n-(double)d/2,c=-m;
	t1=(-b+sqrt(b*b-4*a*c))/2/a;
	t2=(-b-sqrt(b*b-4*a*c))/2/a;
	t3=(ll)t1;
	if(t1>(ll)t1)
	{
		printf("%lld\n",(ll)t1+1);
	}
	else
	{
		printf("%lld\n",(ll)t1);
	}
//	system("pause");
	return 0;
}
