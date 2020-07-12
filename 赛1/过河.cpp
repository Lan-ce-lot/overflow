#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;

int test;
int n;
int a[1100]={0};
int main()
{
    cin>>test;
    while(test--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        long long int num=0;
        if(n==1)
        {
            cout<<a[0]<<endl;continue;
        }
        if(n==2)
        {
            cout<<a[1]<<endl;continue;
        }
        if(n==3)
        {
            for(int i=n-1;i>0;i--)
            {
                num=num+a[i]+a[0];
            }
            num=num-a[0];
            cout<<num<<endl;
            continue;
        }
        int x=2*a[1]-a[0];
        int i;
        for(i=n-2;i>=2;i=i-2)
        {
            if(a[i]<x)break;
            num=num+a[i+1]+a[0]+2*a[1];
        }
        i++;
        for(;i>=1;i--)
        {
            num=num+a[i]+a[0];
        }
        num=num-a[0];
        cout<<num<<endl;    
    }
}

