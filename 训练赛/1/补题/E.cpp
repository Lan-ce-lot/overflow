/*Ç°ºó×º²¹Ìâ*/
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define ll long long
const int MAX = 110;
const int INF=0x3f3f3f3f;
int nat[MAX],firstA[MAX],lastA[MAX],firstO[MAX],lastO[MAX],firstX[MAX],lastX[MAX],n,m;

int main()
{
    while(~scanf("%d%d",&n,&m))
	{
		
		for(int i=0;i<n;i++)
    		
    		scanf("%d",&nat[i]);
    		
		firstA[0]=nat[0],lastA[n-1]=nat[n-1],firstO[0]=nat[0],lastO[n-1]=nat[n-1],firstX[0]=nat[0],lastX[n-1]=nat[n-1];
		for(int i=1;i<n;i++)
		{
			firstA[i]=firstA[i-1]&nat[i];
    		firstO[i]=firstO[i-1]|nat[i];
    		firstX[i]=firstX[i-1]^nat[i];
		}
		
		for(int i=n-2;i>0;i--)
		{
			
			lastA[i]=lastA[i+1]&nat[i]; 
			lastO[i]=lastO[i+1]|nat[i];
			lastX[i]=lastX[i+1]^nat[i];
			
		}
		
		for(int i=0;i<n;i++)
		{
			int b;
			scanf("%d",&b);
			b--;
			if(b==0)
			{
				printf("%d %d %d\n",lastA[1],lastO[1],lastX[1]);
			}
			else if(b==n-1)
			{
				printf("%d %d %d\n",firstA[n-2],firstO[n-2],firstX[n-2]);
			}
			else
			{
				printf("%d %d %d\n",firstA[b-1]&lastA[b+1],firstO[b-1]|lastO[b+1],firstX[b-1]^lastX[b+1]);
			}
		}
		
	}

    return 0;
}

