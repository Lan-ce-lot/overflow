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
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
int main()
{
	int n,op,a,b,c,d;
	scanf("%d",&n);
	while(n--)
	{
		int fm,fz;
		scanf("%d%d%d%d%d",&op,&a,&b,&c,&d);
		fm=b*d;
		if(op)
		{
			fz=a*d+c*b;
			fz*fm>=0?printf("%d/%d\n",abs(fz/gcd(fm,fz)),abs(fm/gcd(fm,fz))):printf("-%d/%d\n",abs(fz/gcd(fm,fz)),abs(fm/gcd(fm,fz)));
		}
		else
		{
			fz=a*d-b*c;
			fz*fm>=0?printf("%d/%d\n",abs(fz/gcd(fm,fz)),abs(fm/gcd(fm,fz))):printf("-%d/%d\n",abs(fz/gcd(fm,fz)),abs(fm/gcd(fm,fz)));
		}
		
	}
	return 0;
}
