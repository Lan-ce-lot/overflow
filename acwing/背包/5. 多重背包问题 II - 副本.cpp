#include<bits/stdc++.h>
using namespace std;
#define debug(a) cout << "*" << a << "*" << endl
int main()
{
    int N,V,v[1001],w[1001],dp[2001],s[1001];
    int a[25000],b[25000];  //2的12次方大于2000，也就是说一个数最多可以拆成12个，故数组容量乘12
    cin>>N>>V;
    memset(dp,0,sizeof(dp));
    for(int i=0; i<N; i++)
        cin>>v[i]>>w[i]>>s[i];
    int total=0;
    for(int i=0; i<N; i++)
    {
        for(int j=1; j<s[i]; j<<=1) //二进制拆分
        {
            a[total]=j*w[i];//存价值
            b[total++]=j*v[i];//存容量
            s[i]-=j;
        }
        if(s[i])//当s[i]>0;
        {
            a[total]=s[i]*w[i];
            b[total++]=s[i]*v[i];
        }
    }
    for(int i=0; i<total; i++) //01背包
        for(int j=V; j>=b[i]; j--)
        {
            dp[j]=max(dp[j],dp[j-b[i]]+a[i]);
        }

    cout<<dp[V];
    return 0;
}
