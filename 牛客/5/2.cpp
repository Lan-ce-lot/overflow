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
	int l1,l2,n;
	double x,y,r,ans,ans_,s;
	scanf("%d%d%d",&l1,&l2,&n);
	ans=l1+l2,ans_=((l1-l2)<=0?l2-l1:l1-l2);
	while(n--)
	{
		scanf("%lf%lf",&x,&y);
		r=x*x+y*y;
		r=sqrt(r);
		if(r<=ans&&r>=ans_)
			puts("0.00000000");
		else
			printf("%.8lf\n",min(abs(r-ans_),abs(ans-r)));
	}
	return 0;
}
