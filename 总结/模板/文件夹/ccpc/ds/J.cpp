#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int N=2010,M=1e6+10;
int n,_,__,m;
int head[M],nxt[N*N];
int deg[N],fre[N],ans,mx;
int cho[N],fi[N],se[N];
typedef pair<int,int> PR;
vector<PR>v[M];
int gi() {
	int x=0;char c;
	while ((c=getchar())<'0'||'9'<c);
	while ('0'<=c&&c<='9') x=x*10+c-'0',c=getchar();
	return x;
}
int solve() {
	int i,x,y,t,p,all;
	scanf("%d%d",&n,&m);
	memset(head,0,sizeof(head));
	for (t=1;t<=n*m;t++) {
		x=gi();
		nxt[t]=head[x],head[x]=t;
	}
	if (m==1) return -1;
	if (m==2&&n%2==1) return -1;
	
	ans=1<<30;
	
	for (i=1;i<=n;i++) cho[i]=0,fi[i]=se[i]=deg[i]=fre[i]=0;
	mx=0;
	for (t=p=1,all=0;t<=1e6;t++) {
		v[t].clear();
		for (i=head[t];i;i=nxt[i]) {
			x=(i-1)/m+1,y=(i-1)%m+1;
			if (!cho[x]) ++all;
			else {
				--deg[cho[x]];
				if (se[x]>=t) --fre[cho[x]],v[se[x]].push_back(make_pair(cho[x],1));
				
				cho[x]=y;
				++fre[y];
				se[x]=fi[x];
				v[se[x]].push_back(make_pair(y,-1));
			}
			fi[x]=t;
			cho[x]=y;
			if (++deg[y]>deg[mx]) mx=y;
		}
		for (;all==n&&(deg[mx]-fre[mx]<=n/2);p++) {
			ans=min(ans,t-p);
			for (PR &pr:v[p])
				fre[pr.first]+=pr.second;
			for (i=head[p];i;i=nxt[i]) {
				x=(i-1)/m+1,y=(i-1)%m+1;
				if (cho[x]==y) cho[x]=0,--deg[y],all--,fi[x]=se[x]=0;
			}
		}
	}
	return ans;
}
int main() {
	//freopen("J.in","r",stdin);
	for (scanf("%d",&_);_;_--) {
		printf("Case %d: ",++__);
		printf("%d\n",solve());
	}
}
