#include<bits/stdc++.h>
using namespace std;
int f[1000000],g[1000000];
int main(){
    for(int i=1;i<=1000000;i++)
    {
        for(int j=1;j<=1000000/i;j++)
        f[i*j]++;
    }
    for(int i=1;i<=1000000;i++)
    {
        if(g[f[i]]==0)g[f[i]]=i;
    }
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int a;
        cin>>a;
        if(g[a]==0)cout<<-1<<endl;
        else cout<<g[a]<<endl;
    }
    return 0;
}
