#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;
int main()
{
    long long n,b,a;
    int sum=0;
    string d;
    scanf("%lld",&n);
    for(int i=0; i<n; i++)
    {
        cin>>d;
        for(int j=0; j<d.size(); j++)
        {
            if(d[0]=='0')
            {
                printf("1");
                if(i<n-1)
                {
                    printf("\n");
                }
            }
            else
            {
                if(d[j]==0||d[j]==4||d[j]==6||d[j]==9)
                {
                    sum=sum+1;
                }
                else if(d[j]==1||d[j]==2||d[j]==3||d[j]==5||d[j]==7)
                {
                    sum=sum+0;
                }
                else
                {
                    sum=sum+2;
                }
            }
        }
        if(d[0]=='0')
        {
            sum=0;
        }
        else
        {
            printf("%d",sum);
            if(i<n-1)
            {
                printf("\n");
            }
            sum=0;
        }
    }
    return 0;
}
