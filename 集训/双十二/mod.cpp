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
#define INF 0x3f3f3f3f
int main()
{
	ll n,s,a[10000],sum=0;
	scanf("%lld%lld",&n,&s);
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
		sum+=a[i];
		
	 } 
	 ll minl=*min_element(a,a+n);
	 if(sum<s)
	 	printf("-1\n");
	else
		printf("%lld\n",min(minl,(sum-s)/n));
	return 0;
}
