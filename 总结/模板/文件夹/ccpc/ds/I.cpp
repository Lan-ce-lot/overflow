#include<bits/stdc++.h>
using namespace std;

const int N=101000;
int n,_,__,m;
int a[N],b[N],c[N];
int x[N],xl,y[N],yl;
long long ans;
bool o[N];
void solve() {
	int i,k;long long s;
	xl=yl=0;
	for (i=1;i<=n;i++)
		scanf("%d",a+i);
	for (i=1;i<=m;i++)
		scanf("%d",b+i);
	for (i=1;i<=m;i++) {
		scanf("%d",c+i);
		if (c[i]) y[++yl]=b[i];
		else x[++xl]=b[i];
	}
	sort(x+1,x+1+xl);
	sort(y+1,y+1+yl);
	sort(a+1,a+1+n);
ans=s=0;
	for (i=1;i<=xl&&i<=n;i++) {
		s+=a[n+1-i]-x[i];		
		ans=max(ans,s);
	}

	s=0;
	for (i=1;i<=n;i++) o[i]=true;
	for (i=k=1;i<=yl;i++) {
		while (1) {
			if (k>n) return;
			if (a[k]<y[i]) k++;
			else break;
		}
		o[k]=false;k++;
	}
	for (i=xl,k=n;i;i--) {
		while (k&&!o[k]) k--;
		if (k&&a[k]>=x[i]) s+=a[k]-x[i];
		else return;
		k--;
	}
	for (;k;k--)
		if (o[k]) s+=a[k];
	ans=max(ans,s);
}
int main() {
	for (scanf("%d",&_);_;_--) {
		scanf("%d%d",&n,&m);
		solve();
		printf("Case %d: ",++__);
		printf("%lld\n",ans);
	}
}
