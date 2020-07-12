#include<bits/stdc++.h>
using namespace std;
int _,__,h,m;
char t[100],c1[100],c2[100];
int gao(char *a) {
	if (a[0]=='B') return 8;
	else if (a[0]=='W') return -5;
	else if (a[0]=='L') return 0;
	else if (a[0]=='M') return 3;
}
int main() {
	for (scanf("%d",&_);_;_--) {
		printf("Case %d: ",++__);
		scanf("%d:%d %s",&h,&m,t);
		scanf("%s",c1);
		scanf("%s",c2);
		if (h==12) h=0;
		if (t[0]=='P') h+=12;
		h-=gao(c1);
		h+=gao(c2);
		int d=0;
		if (h<0) d=-1,h+=24;
		else if (h>=24) d=1,h-=24;
		if (d==0) printf("Today");
		else if (d==-1) printf("Yesterday");
		else printf("Tomorrow");
		int ap=0;
		if (h>=12) ap=1,h-=12;
		if (h==0) {
			h=12;
		}
		printf(" %d:%02d",h,m);
		printf(" %cM\n",ap?'P':'A');
	}
}
