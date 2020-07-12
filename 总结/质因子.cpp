#include<stdio.h>
int main()
{
    long long a[100],num,i,n;
    while(~scanf("%I64d",&n))
    {
        num=0;
        for(i=2; i*i<=n; i++)
        {
            if(n%i==0)
                a[num++]=i;
            while(n%i==0)
                n/=i;
        }
        if(n>1)
            a[num++]=n;
        for(i=0; i<num; i++)
            printf("%I64d ",a[i]);
        printf("\n");
    }
 //15259 28661
    return 0;
}
