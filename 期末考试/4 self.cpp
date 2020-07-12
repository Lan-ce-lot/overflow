#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;
int c[1010]={0},dp[1010]={0};
bool cmp(int a,int b)
{
	return a>b;
 } 
int main(){
    int n;
    while(~scanf("%d",&n)&&n)
	{
		int num,mo,an=0;
		scanf("%d",&num);
       for(int i=0;i<num;i++)
       		scanf("%d",&c[i]);
       	scanf("%d",&mo);
	   if(n<5)
	   {
	   		printf("%d\n",num);
	   		continue;
	   }
	   sort(c,c+num,cmp);
	   for(int i=0;i<n;i++)
	   {
			if(mo-c[i]>=5)
			{
				an+=c[i];
				mo-=c[i];	
			  }  	
	  }       
	  printf("%d\n",mo-c[0]);
    }
    return 0;
}
