#include<bits/stdc++.h>
using namespace std;
const int N=60,M=5010;
typedef long long LL;
int n,_,__,m;
int gi() {
	int x=0;char c;
	while ((c=getchar())<'0'||'9'<c);
	while ('0'<=c&&c<='9') x=x*10+c-'0',c=getchar();
	return x;
}
struct DT{ int w; LL s; }ans[M];
DT operator + (const DT &a,const DT &b) {
	if (a.w>b.w) return a;
	if (a.w<b.w) return b;
	return (DT){a.w,a.s+b.s};
}
int a[N],b[N];
LL mi,cur,nxt;int o[N];
int p[N],rk[N],d[N];
vector<int>e[N];

int lim[N];
map<LL,vector<DT>>f,g;
LL get() {
	int i;LL w=0;
	d[0]=0;
	for (i=1;i<=n;i++) rk[p[i]]=i,d[i]=0;
	for (i=1;i<=n;i++) {
		lim[i]=rk[i];
		for (int t:e[i])
			lim[i]=max(lim[i],rk[t]);
		++d[rk[i]],--d[lim[i]];
	}
	for (i=1;i<=n;i++)
		d[i]+=d[i-1],w+=1LL<<d[i];
	return w;
}
void add(DT &a,DT &b) {
	a=a+b;
}
void inc(vector<DT> &a,int m,DT &b) {
	while (a.size()<m+1) {
		a.push_back((DT){0,0});
	}
	add(a[m],b);
}
void solve() {
	int i,T,k,Q,j,u,v;LL s;DT t;
	n=gi(),m=gi();
	//n=50,m=5000;
	for (i=1;i<=n;i++) {
		//a[i]=rand()%200+1,b[i]=1,e[i].clear();
		a[i]=gi(); b[i]=gi(); e[i].clear();
	}
	for (i=1;i<n;i++) {
		u=gi(),v=gi();
		//u=rand()%i+1,v=i+1;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	mi=1LL<<60;
	for (T=10;T;T--) {
		for (i=1;i<=n;i++) p[i]=i;
		random_shuffle(p+1,p+1+n);
		cur=get();
		for (Q=1000;Q;Q--) {
			i=rand()%n+1,j=rand()%n+1;
			swap(p[i],p[j]);
			nxt=get();
//			printf("%lld %lld\n",cur,nxt);
			if (nxt<cur) cur=nxt;
			else swap(p[i],p[j]);
		}
		if (cur<mi) {
			mi=cur;
			for (i=1;i<=n;i++) o[i]=p[i];
		}
	}
	//for (i=1;i<=n;i++) printf("%d ",o[i]);puts("");
	//printf("xx : %lld\n",mi);
	f.clear();
	f[0]=vector<DT>{(DT){0,1}};
	bool can;
	for (i=1;i<=n;i++) p[i]=o[i],rk[o[i]]=i;
	get();
	for (i=1;i<=n;i++) {
//	printf("%d z\n",lim[p[i]]);
		g.clear();
		LL all=0;
		for (j=1;j<=n;j++)
			if (lim[j]>=i) 
				all|=1LL<<j;
		for (auto pr:f) {
//		printf("%lld %d %d %lld\n",pr.first.first,pr.first.second,pr.second.w,pr.second.s);
			s=pr.first&all;
			//printf("%d %d %d\n",i,pr.first,pr.second.size());
			for (k=0;k<pr.second.size();k++) {
				t=pr.second[k];
				if (!t.s) continue;
				//printf("%d %lld %d %d %d\n",i,s,k,pr.second[k].w,pr.second[k].s);
				inc(g[s],k,t);
				can=true;
				for (int z:e[p[i]])
					if (s>>z&1)
						can=false;
				if (can&&k+a[p[i]]<=m) {
					t.w+=b[p[i]];
					inc(g[s|1LL<<p[i]],k+a[p[i]],t);
				}
			}
		}
		//puts("");
		//printf("%d\n",g.size());
		f=g;
	}
	for (i=1;i<=m;i++) ans[i]=(DT){0,0};
	for (auto p:f)
		for (i=1;i<p.second.size();i++)
			add(ans[i],p.second[i]);
	for (i=1;i<=m;i++)
		printf("%lld%c",ans[i].s," \n"[i==m]);
}
int main() {
	for (scanf("%d",&_);_;_--) {
		printf("Case %d:\n",++__);
		solve();
	}
}
