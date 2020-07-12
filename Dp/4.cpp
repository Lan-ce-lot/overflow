# include<stdio.h>
# define MAX 5842
long long num[MAX+1];

long long min(long long a,long long b,long long c,long long d)
{
    long long min1,min2;
    min1=a<b?a:b;
    min2=c<d?c:d;
    if(min1<=min2)
        return min1;
    else 
        return min2;
}

int main()
{
    int i=1,n;
    num[1]=1;
    int p2,p3,p5,p7;
    p2=p3=p5=p7=1;
    while(i<5842)
    {
        num[++i]=min(num[p2]*2,num[p3]*3,num[p5]*5,num[p7]*7);
        if(num[i]==num[p2]*2)
            p2++;
        if(num[i]==num[p3]*3)
            p3++;
        if(num[i]==num[p5]*5)
            p5++;
        if(num[i]==num[p7]*7)
            p7++;
    }
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
            break;
        else
        {
            if(n%10==1&&n%100!=11)
                printf("The %dst humble number is %lld.\n",n,num[n]);
            else if(n%10==2&&n%100!=12)
                printf("The %dnd humble number is %lld.\n",n,num[n]);
            else if(n%10==3&&n%100!=13)
                printf("The %drd humble number is %lld.\n",n,num[n]);
            else
                printf("The %dth humble number is %lld.\n",n,num[n]);
        }
    }
    return 0;
}
