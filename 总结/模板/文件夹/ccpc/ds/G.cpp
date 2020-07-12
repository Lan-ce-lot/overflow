#include<bits/stdc++.h>
using namespace std;

typedef double db;

db r;
int _,__;
bool valid(int a,int b,db r) {
	if (a<0||a>=b) return 0;
	db c=1.*a/b;
	if (fabs(c-r)>=5e-8) return 0;
	int d=__gcd(a,b);
	a/=d; b/=d;
	vector<int> ret;
	while (1) {
		if (a==b) {
			break;
		} else {
			if (a>b) {
				ret.push_back(0);
				a-=b;
			} else {
				ret.push_back(1);
				b-=a;
			}
		}
	}
	if (ret.size()<=9990) {
		int n=ret.size();
		reverse(ret.begin(),ret.end());
		printf("%d %d\n",n+1,n);
		printf("%d 0 1\n",ret[0]);
		for (int i=1;i<n;i++) {
			printf("%d %d %d\n",ret[i],i+1,i+n);
		}
		return 1;
	}
	return 0;
}
void solve(db r) {
	int b=1;
	while (1) {
		int a=(int)(r*b);
		for (int da=-2;da<=2;da++) {
			if (valid(a+da,b,r)) {
				return;
			}
		}
		++b;
	}
}
int main() {
	for (scanf("%d",&_);_;_--) {
		scanf("%lf",&r);
		printf("Case %d:\n",++__);
		solve(r);
	}
}
