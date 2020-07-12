#include <bits/stdc++.h>
using namespace std;
long long g[100000000];
int main()
{
    long long a,b,i,cnt=0;
    cin>>a>>b;
    for(i=1;i<=sqrt(a);i++)
    {
        if(a%i==0&&b%i==0) g[cnt++]=i;
        if(a%i==0&&b%(a/i)==0&&i!=a/i) g[cnt++]=a/i;
    }
    sort(g,g+cnt);
    for(i=0;i<cnt;i++) cout<<g[i]<<" ";
    cout<<endl;
    return 0;
}
