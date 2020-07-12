#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
#include<algorithm> 
using namespace std;
typedef long long ll;
#define PI 3.1415927
#define M(a) memset(a,0,sizeof(a))
const int INF=0x3f3f3f3f;
int power(int p,int k)
{
	int ans=1,t=1;
	while(k)
	{
		if(t==1)t=p;else t=t*t;
		if(k%2==1)ans=ans*t;
		k>>=1;
	}
	return ans;
}
int main()
{
	int n,m,x;
	scanf("%d%d",&n,&m);
	x=power(2,n);
	if(n>26)printf("%d",m);
	else
	printf("%d\n",m%x);
	return 0;
}
