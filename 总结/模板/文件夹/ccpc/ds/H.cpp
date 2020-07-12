#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int N=401000;
int n,_,__,m;
int sum[N],p[N],len[N];
int a11[N],a21[N],a22[N],a31[N];
#define lc (i<<1)
#define rc (lc|1)
void build(int i,int l,int r) {
	sum[i]=0;p[i]=(r-l+1)*10;len[i]=r-l+1;
	a11[i]=1;
	a21[i]=0;
	a22[i]=1;
	a31[i]=0;
	if (l==r) return;
	int mid=(l+r)>>1;
	build(lc,l,mid);
	build(rc,mid+1,r);
}
void update(int i) {
	sum[i]=(sum[lc]+sum[rc])%mod;
	p[i]=(p[lc]+p[rc])%mod;
}
void make(int i,int b11,int b21,int b22,int b31) {
	sum[i]=(1LL*sum[i]*b11+1LL*p[i]*b21+1LL*len[i]*b31)%mod;
	p[i]=1LL*p[i]*b22%mod;
	a11[i]=(1LL*a11[i]*b11)%mod;
	a21[i]=(1LL*a21[i]*b11+1LL*a22[i]*b21)%mod;
	a31[i]=(1LL*a31[i]*b11+b31)%mod;
	a22[i]=1LL*a22[i]*b22%mod;
//printf("%d\n",sum[i]);
}
void pushdown(int i) {
	make(lc,a11[i],a21[i],a22[i],a31[i]);
	make(rc,a11[i],a21[i],a22[i],a31[i]);
	a11[i]=1;
	a21[i]=0;
	a22[i]=1;
	a31[i]=0;
}
void modify(int i,int l,int r,int L,int R,int d) {
	if (L<=l&&r<=R) make(i,10,d,100,d);
	else {
		int mid=(l+r)>>1;
		pushdown(i);
		if (L<=mid) modify(lc,l,mid,L,R,d);
		if (mid<R) modify(rc,mid+1,r,L,R,d);
		update(i);
	}	
}
int query(int i,int l,int r,int L,int R) {
	if (L<=l&&r<=R) return sum[i];
	else {
		int mid=(l+r)>>1,ans=0;
		pushdown(i);
		if (L<=mid) ans=query(lc,l,mid,L,R);
		if (mid<R) (ans+=query(rc,mid+1,r,L,R))%=mod;
		return ans;
	}
}
char str[100];
void solve() {
	scanf("%d%d",&n,&m);
	build(1,1,n);
	int l,r,d;
	while (m--)  {
		scanf("%s",str);
		if (str[0]=='w') {
			scanf("%d%d%d",&l,&r,&d);
			modify(1,1,n,l,r,d);
		} else {
			scanf("%d%d",&l,&r);
			printf("%d\n",query(1,1,n,l,r));
		}
	}
}
int main() {
//freopen("H.in","r",stdin);
//freopen("H.out","w",stdout);
	for (scanf("%d",&_);_;_--) {
		printf("Case %d:\n",++__);
		solve();
	}
}
