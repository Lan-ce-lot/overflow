#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
#include<stack>
#include<cmath>
#include<vector>
#include<set>
#include<cstdio>
#include<string>
#include<deque>
using namespace std;
typedef unsigned long long ll;
#define eps 1e-8
#define INF 0x3f3f3f3f
#define maxn 5000005
#define base 26
inline int read(){
    int f=1,x=0;char ch;
    do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');
    do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');
    return f*x;
}
struct node{
    int v,next;
}edge[maxn*2];
int n,m,k,t,cnt;
int head[maxn];
ll f[maxn];
char str[maxn];
set<ll>se;
void init(){
    memset(head,-1,sizeof(head));
    cnt=0;
    se.clear();
}
void add(int u,int v){
    edge[++cnt].v=v;
    edge[cnt].next=head[u];
    head[u]=cnt;
}
void dfs(int u,int num,ll value,int pre){//点编号，从根节点到这个点经过的点的个数，到当前点为止的哈希值，pre代表u的父亲
    value=value*base+(ll)str[u];
    bool flag=true;//flag表示现在有没有到根节点
    for(int i=head[u];i!=-1;i=edge[i].next){
        int v=edge[i].v;
        if(v==pre) continue;
        dfs(v,num+1,value,u);
        flag=false;
    }
    if(flag==true){//当前点u是一个叶子节点
        se.insert(value);//将这个点插入set
    }
}
int main()
{
    while(scanf("%d",&n)!=EOF){
        scanf("%s",str+1);
        init();
        int u,v;
        for(int i=0;i<n-1;i++){
            u=read();
            v=read();
            add(u,v);
            add(v,u);
        }
        for (int i = 0; i < n + 10; i++)
        {
            printf("%d %d %d\n", edge[i].v, edge[i].next, head[i]);
        }
        dfs(1,1,0,1);
        printf("%d\n",se.size());
    }
    return 0;
}
