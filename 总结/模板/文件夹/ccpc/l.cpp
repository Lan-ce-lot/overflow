#include<bits/stdc++.h>
using namespace std;

const int N=50+2,M=5000+5;
typedef long long ll;
int f[N][M][2];
ll g[N][M][2];
vector<int> succ[N];
int a[N],b[N];
int m;
void dfs(int u,int ftr){
    for(auto i=succ[u].begin();i!=succ[u].end();++i)
        if(*i==ftr){
            succ[u].erase(i);
            break;
        }
    for(int v:succ[u])dfs(v,u);

    
}
int main(){
    int T;
    scanf("%d",&T);
    for(int cs=1;cs<=T;++cs){
        int n;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;++i)scanf("%d%d",a+i,b+i);
        
        for(int i=1;i<=n;++i)succ[i].clear();
        for(int i=n;--i;){
            int u,v;
            scanf("%d%d",&u,&v);
            succ[u].push_back(v),succ[v].push_back(u);
        }

        memset(g,0,sizeof(g));
        memset(f,0,sizeof(f));
        dfs(1,0);
        
        printf("Case %d:\n",cs);
        for(int i=1;i<=n;++i)printf("%lld%c",g[1][i][0]+g[1][i][1], " \n"[i==n]);
    }
}
