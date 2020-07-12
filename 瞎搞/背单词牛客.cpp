#include<iostream>
#include<cstdio>
#include<cstring>
#define LL long long
#define M ((LL)1e9+7)
 
using namespace std;
 
int i,m,n,j,k,ans,t,f[110],sum,a,b;
 
int main()
{
    scanf("%d",&t);
    for(;t;t--)
    {
        scanf("%d%d%d",&n,&a,&b); k=0;
        memset(f,0,sizeof(f));
        f[a+1]=21;f[a]=5; sum=5+21;
        for(int i=1;i<n;i++)
        {
            k=f[a]; m=f[a+1];
            for(int j=1;j<=a-1;j++)
            {
                k=(k+f[j])%M;
                f[j]=f[j+1]*5ll%M;
            }
            for(int j=a+b;j>=a+2;j--)
            {
                m=(m+f[j])%M;
                f[j]=f[j-1]*21ll%M;
            }
            f[a+1]=k*21ll%M; f[a]=m*5ll%M;
            for(int i=1;i<=a+b;i++) sum=((LL)sum+f[i])%M;
        }
        printf("%d\n",sum);
    }
}
