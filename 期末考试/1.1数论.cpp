#include<stdio.h>
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==1){printf("0\n");continue;}
      __int64 s,num;
      s=n*n*n;
      num=(s-4)*8+(s-5)*(n-2)*12+(s-6)*(n-2)*(n-2)*6+(s-7)*(n-2)*(n-2)*(n-2);
      num/=2;
      printf("%d\n",num);
    }
return 0;
} 
