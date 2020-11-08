#include<bits/stdc++.h>
#define maxn 200+5
#define maxm 40000+500
using namespace std;
int Head[maxn],V[maxm],Next[maxm],tot=0;
int In[maxn],Belong[maxn],Dfn[maxn],Low[maxn],Time,cnt,inq[maxn];
stack<int>q;
int N;
void Add(int u,int v){
	V[++tot]=v;
	Next[tot]=Head[u];
	Head[u]=tot;
}
void Tarjan(int u){
	int i,v,tmp;
	Dfn[u]=Low[u]=++Time;
	q.push(u);inq[u]=1;
	for(i=Head[u];i;i=Next[i]){
		v=V[i];
		if(!Dfn[v]){
			Tarjan(v);
			Low[u]=min(Low[u],Low[v]);
		}
		else if(inq[v])Low[u]=min(Low[u],Dfn[v]);
	}
	if(Dfn[u]==Low[u]){
		cnt++;
		do{
			tmp=q.top();q.pop();inq[tmp]=0;
			Belong[tmp]=cnt;
		}while(tmp!=u);
	}
}
int main(){
	int i,u,v,ans=0;
	scanf("%d",&N);
	for(i=1;i<=N;i++)while(scanf("%d",&v)&&v)Add(i,v);
	for(i=1;i<=N;i++)if(!Dfn[i])Tarjan(i);
	for(u=1;u<=N;u++)
		for(i=Head[u];i;i=Next[i])
			if(Belong[u]!=Belong[V[i]]) {
				cout << u << ' ' << i << ' ' << Belong[u] << ' ' << Belong[V[i]] << endl;
				In[Belong[V[i]]]++;
			}
				
//				cout << cnt ;
	for(i=1;i<=cnt;i++)if(!In[i])ans++;
	printf("%d\n",ans);
	return 0;
}
//1 3 3 1
//1 2 3 2
//2 4 3 1
