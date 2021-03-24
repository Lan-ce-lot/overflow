#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;

float ans[5];
float a,b,c,d;
int n=0;

float f(float x)
{
    return ((a*x+b)*x+c)*x+d;
}

void solve(float l,float r)
{
    if(f(l)*f(r)>0&&(((r-l)<1)||n>=2))
        return;
    float mid=(l+r)/2;

    if(f(mid)<=1e-4 && f(mid)>=-1e-4)
    {
        ans[n++]=mid;
        return;
    }

    solve(l,mid),solve(mid,r);
}

int main()
{
    a = 1;
    cin>>b>>c>>d;
    b = -b, c = -c, d = -d;
    solve(-100,100);
    printf("%.2lf %.2lf %.2lf",ans[0],ans[1],ans[2]);
    return 0;
}