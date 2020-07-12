#include<bits/stdc++.h>
using namespace std;

int read() {
	int x=0;char c;
	while ((c=getchar())<'0'||'9'<c);
	while ('0'<=c&&c<='9') x=x*10+c-'0',c=getchar();
	return x;
}

const int N=1010000;
int _,__,n,rad[N],ss[N];
int main() {
	for (_=read();_;_--) {
		n=read();
		printf("Case %d: ",++__);
		for (int i=0;i<n;i++) rad[i]=read();
		for (int i=0;i<n;i++) ss[i]=0;
		for (int i=0;i<n;i++) {
			int l=i,r=i+rad[i];
			while (l+1<r) {
				int md=(l+r)>>1;
				if (md-rad[md]+1<=2*i-md) l=md; else r=md;
			}
			// [i+1...l]
			ss[l+1]--;
			ss[i+1]++;
			if (rad[i]==1) continue;
			l=i,r=i+rad[i]-1;
			while (l+1<r) {
				int md=(l+r)>>1;
				if (md-rad[md]+1<=2*i-md-1) l=md; else r=md;
			}
			ss[l+1]--;
			ss[i+1]++;
		}
		for (int i=1;i<n;i++) {
			ss[i]+=ss[i-1];
		}
		int ans=0;
		for (int i=0;i<n;i++) ans^=ss[i];
		printf("%d\n",ans);		
	}
}
