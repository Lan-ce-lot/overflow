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
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int s,h;
		scanf("%d%d",&s,&h);
		ll x=pow(2,s-h);
		printf("%lld\n",x);
	}
	
	


	return 0;

}
