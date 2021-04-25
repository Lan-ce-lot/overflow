#include <bits/stdc++.h>

using namespace std;

const double eps=1e-6;

struct node {
	double x,y;
} a[510];

struct cir {
	double x,y,r;
};

double dis(node a,node b) {
	double dx=a.x-b.x;
	double dy=a.y-b.y;
	return sqrt(dx*dx+dy*dy);
}

cir get(node p1,node p2,node p3) {
	double a=p1.x-p2.x;
	double b=p1.y-p2.y;
	double c=p1.x-p3.x;
	double d=p1.y-p3.y;
	double e=((p1.x*p1.x-p2.x*p2.x)-(p2.y*p2.y-p1.y*p1.y))/2;
	double f=((p1.x*p1.x-p3.x*p3.x)-(p3.y*p3.y-p1.y*p1.y))/2;
	double x0=(b*f-d*e)/(b*c-a*d);
	double y0=(c*e-a*f)/(b*c-a*d);
	double r=dis(p1, {x0,y0});
	return {x0,y0,r};
}

int n;

int main() {
	while(cin>>n,n) {
		for(int i=0; i<n; i++) cin>>a[i].x>>a[i].y;
		cir ans= {a[0].x,a[0].y,0};
		for(int i=0; i<n; i++) {
			if(dis(a[i], {ans.x,ans.y})>ans.r+eps) {
				ans= {a[i].x,a[i].y,0};
				for(int j=0; j<i; j++) {
					double d=dis(a[j], {ans.x,ans.y});
					if(d>ans.r+eps) {
						ans= {(a[i].x+a[j].x)/2,(a[i].y+a[j].y)/2,dis(a[i],a[j])/2};
						for(int k=0; k<j; k++) {
							if(dis(a[k], {ans.x,ans.y})>ans.r+eps) {
								ans=get(a[i],a[j],a[k]);
							}
						}
					}
				}
			}
		}
		printf("%d %d %d\n",int(ans.x*100),int(ans.y*100),int(ans.r*100));
	}
}
