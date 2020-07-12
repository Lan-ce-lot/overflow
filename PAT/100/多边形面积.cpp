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
struct coordinate
{
	double x,y;
}a[100];
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		if(n==0)break;
		double s=0.0;
		for(int i=0;i<n;i++)
			scanf("%lf%lf",&a[i].x,&a[i].y);
			
		for(int i=1;i<n-1;i++)
		{
			
			s=s+(a[0].x*a[i].y+a[i].x*a[i+1].y+a[i+1].x*a[0].y-a[0].x*a[i+1].y-a[i].x*a[0].y-a[i+1].x*a[i].y);
		}	
//			
		printf("%.1lf\n",s/2);
			
	 } 
	return 0;
}
