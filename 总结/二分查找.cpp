#include<stdio.h>
#include<math.h>
#include<stdio.h>
#include<math.h>
long long m,s,a1,d,x;
int chax(long long n)
{
    if((d*n*n+(2*a1-d)*n)>=2*s)return 1;
    else return 0;
}
int main()
{  
    long long left,right,mid;
    scanf("%lld%lld%lld%lld",&a1,&s,&d,&x);
    left=1;right=x;
    while(left<right)
    {
        mid=(left+right)/2;
        if(chax(mid))right=mid;
        else left=mid+1;
    }
    if(a1>=s)printf("1");
    else printf("%lld",left);
}
