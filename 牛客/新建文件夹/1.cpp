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
	ll n,h,h1,max1=0;
	scanf("%lld%lld",&n,&h);
	while(n--)
	{
		scanf("%lld",&h1);
		max1=max(h1,max1);
	}
	printf("%lld",max1-h<0?0:max1-h);	

//	system("pause");
	return 0;

}
