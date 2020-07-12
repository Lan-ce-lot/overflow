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
	int n,t,t1,st,b[150]={0},z=0,a[150];
	scanf("%d",&n);
	for(int j=0;j<n;j++)
	{
		
		if(j==0)
		{
			scanf("%d",&t1);
			for(int i=0;i<t1;i++)
				scanf("%d",&a[i]);
		}
		else
		{
			scanf("%d",&t);
			for(int i=0;i<t;i++)
			{
				scanf("%d",&st);
				for(int l=0;l<t1;l++)
				{
					if(a[l]==st)
					{
						b[st]++;
					}			
				}	
			}	
		}
	}
	for(int i=0;i<102;i++)
		b[i]==n-1?printf("%d ",i):i;
	return 0;
}
