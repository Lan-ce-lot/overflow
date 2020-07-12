#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;
int c[1010],dp[1010];
int main(){
    int n;
    while(~scanf("%d",&n))
	{
        if(n==0)    break;
        memset(dp,0,sizeof(dp));
        int i,j;
        for(i=0;i<n;i++)
            scanf("%d",&c[i]);
        sort(c,c+n);
        int cost;
        scanf("%d",&cost);
        if(cost>=5){
            for(i=0;i<n-1;i++)      
                for(j=cost-5;j>=c[i];j--)
                    dp[j]=max(dp[j],dp[j-c[i]]+c[i]);
            printf("%d\n",cost-dp[cost-5]-c[n-1]);
        }
        else
            printf("%d\n",cost);        
    }
    return 0;
}
