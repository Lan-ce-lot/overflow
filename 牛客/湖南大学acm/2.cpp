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
	int t;
	ll a,b,c,d;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
		if(a==2305843009213693952&&b==2305843009213693952&&c==2305843009213693952&&d==2305843009213693952)
		{
			printf("9223372036854775808\n");
		}
		else if(a==-2305843009213693952&&b==-2305843009213693952&&c==-2305843009213693952&&d==-2305843009213693952)
		{
			printf("-9223372036854775808\n");
		}
		else 
		{
			printf("%lld",a+b+c+d);
		}
	}
	
	return 0;

}
