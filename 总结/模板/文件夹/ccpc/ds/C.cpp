#include<bits/stdc++.h>
using namespace std;

const int N=101000;
int n,_,__;
int cnt[N],req[N],a[N];
bool solve() {
	for (int i=0;i<n;i++) {
		if (a[i]<=n) cnt[a[i]]++;
	}
	int cc=1;
	for (int i=0;i<=n;i++) {
		cc-=cnt[i];
		cc*=2;
		if (cc>n) return 0;
		if (cc<0) break;
	}
	if (cc>0) return 0;
	cc=1;
	for (int i=0;i<=n;i++) req[i]=0;
	for (int i=1;i<=n;i++) {
		if (cnt[i]>=cc) {
			req[i]=cc;
			cc=0;
			break;
		}
		req[i]=cnt[i];
		cc-=cnt[i];
		cc*=2;
		if(cc>n) return 0;
	}
	if (cc!=0) return 0;
	puts("YES");
	for (int i=0;i<n;i++) {
		if (a[i]<=n&&req[a[i]]>0) putchar('1'),--req[a[i]];
		else putchar('0');
	}
	puts("");
	return 1;
}
int main() {
	for (scanf("%d",&_);_;_--) {
		scanf("%d",&n);
		printf("Case %d: ",++__);
		for (int i=0;i<=n;i++) {
			cnt[i]=0;
		}
		for (int i=0;i<n;i++) {
			scanf("%d",a+i);
		}
		if (!solve()) {
			puts("NO");
		}
	}
}
