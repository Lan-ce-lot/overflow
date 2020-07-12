#include<iostream>
#include<algorithm> 
using namespace std;
struct moon
{
	double am,pr,av;
};
bool cmp(moon a,moon b)
{
	return a.av>b.av;
}
int main()
{
	moon a[1001];
	int n,x;
	while(~scanf("%d%d",&n,&x))
	{
		double sum1=0,sum2=0;
		int t,flag=0;
		for(int i=0;i<n;i++)
			scanf("%lf",&a[i].am);
		for(int i=0;i<n;i++)
		{
			scanf("%lf",&a[i].pr);
			a[i].av=a[i].pr/a[i].am;
		}	
		sort(a,a+n,cmp);
		for(int i=0;i<n;i++)
		{
			if(a[i].am>=x)
			{
				sum2+=x*a[i].av;
				break;				
			}
			else
				{
					x-=a[i].am;
					sum2+=a[i].pr;
				}
		}
		printf("%.2lf\n",sum2);	
	}
	return 0;
}
