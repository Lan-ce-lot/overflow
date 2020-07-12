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
const int INF=0x3f3f3f3f;
int main()
{
	int n,a[2018],k[2018]={0},flag=1,temp=0;
	scanf("%d",&n);
	for(int i=1;i<n+1;i++)
	{
		scanf("%d",&a[i]);
		if(i!=1)
			if(a[i]<=a[i-1])flag=0;	
	}
	if(flag==0)
	{
		printf("%d\n",n+1);
		for(int i=n;i>0;i--)
		{
			
			k[i]=n+i-1-a[i]-temp;
			temp+=k[i];
			while(i!=n+1&&k[i]<=0)
				k[i]+=n;
		}
		for(int i=1;i<=n+1;i++)
			i!=n+1?printf("1 %d %d\n",i,k[i]):printf("2 %d %d\n",n,n);
	 } 
	else
		printf("0\n");
	return 0;
}
