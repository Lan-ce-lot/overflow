#include<bits/stdc++.h>
using namespace std;

typedef long double db;
#define y0 adsfasf
int _,__;
db r,h,x0,y0,z0,vx,vy,vz,a,b,c;

db readd() {
	double x;
	scanf("%lf",&x);
	return (db)x;
}
int main() {
	for (scanf("%d",&_);_;_--) {
		r=readd(); h=readd();
		x0=readd(); y0=readd(); z0=readd();
		vx=readd(); vy=readd(); vz=readd();
		a=h*h*(vx*vx+vy*vy)-r*r*vz*vz;
		b=2*h*h*(x0*vx+y0*vy)+2*r*r*(h-z0)*vz;
		c=h*h*(x0*x0+y0*y0)-r*r*(h-z0)*(h-z0);

		printf("Case %d: ",++__);
		if (fabs(a)<=1e-9) {
			printf("%.10f\n",(double)(c/b));
		} else {
			db delta=max(b*b-4*a*c,(db)0.0);
			db t=1e30;
			//printf("%.10f %.10f %.10f %.10f\n",a,b,c,delta);
			db x=(-b+sqrt(delta))/2/a;
			if (x>0&&(z0+vz*x)<h+1e-9) t=min(t,x);
			x=(-b-sqrt(delta))/2/a;
			if (x>0&&(z0+vz*x)<h+1e-9) t=min(t,x);
			printf("%.10f\n",(double)t);
		}
	}
}
