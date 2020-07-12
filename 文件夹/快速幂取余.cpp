#include<stdio.h>
int main()
{
    int m,n,s,i;
    while(scanf("%d%d",&m,&n)!=EOF)//积的取余=取余的积的取余 
    {
        if(m==0&&n==0)
            break;
        s=m;
        for(i=1;i<n;i++)
            s=(s*m)%1000;
        printf("%d\n",s);
    }
    return 0;
}

