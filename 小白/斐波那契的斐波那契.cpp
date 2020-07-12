#include<stdio.h>
 
int main()
{
    int i,n;
     
    long long ans,a,b,t;
    scanf("%d",&n);
    a=0;b=1;
    ans=0;
    for (i=1;i<=n;++i)
    {
        t=(a+b)%10000000007;
        a=b;
        b=t;
        ans=(ans+t)%10000000007;
    }
    printf("%lld",ans);
    return 0;
}

