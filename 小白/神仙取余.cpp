#include<stdio.h>
int main()
{
    char s[105];
    int a;
    while(~scanf("%s%d",s,&a))
    {
        int b=0;
        for(int i=0;s[i]!='\0';i++)
            b=(b*10+s[i]-'0')%a;
        printf("%d\n",b);			//(a+b)%c=(a%c+b%c) %c//(a*b)%c=(a%c*b%c)%c
    }
}
