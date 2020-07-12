#include<bits/stdc++.h>
using namespace std;
int _,__,n;
int main() {
	for (scanf("%d",&_);_;_--) {
		printf("Case %d: ",++__);
		scanf("%d",&n);
		int m=sqrt(n)-0.1;
		while ((m+1)*(m+1)<=n) ++m;
		puts(m%2?"odd":"even");
	}
}
