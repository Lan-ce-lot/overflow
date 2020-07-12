#include<bits/stdc++.h>
using namespace std;
double f(double a,double b)
{
	return (a+b)/2.0;
}
double a[100005];
int main()
{
	int n;
	double t;
	scanf("%d%lf",&n,&t);
	for(int i=0;i<n;i++)
	{
		scanf("%lf",&a[i]);
	}
	sort(a,a+n);
	for(int i=0;i<n;i++)
	{
		a[i]>t?t=f(t,a[i]):i;
	}
	printf("%.3lf\n",t);
	return 0;
}
