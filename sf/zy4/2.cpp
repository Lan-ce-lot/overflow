#include <bits/stdc++.h>
using namespace std;
int main()
{
    double a = 1,b,c,d;
    cin>>b>>c>>d;b = -b, c = -c, d = -d;
    double j=-100;
    double i=j;
    for(j;j<=100;j+=0.01)
    {
        if(a*i*i*i+b*i*i+c*i+d<0)
        {
            if(a*j*j*j+b*j*j+c*j+d>0)
            {
                printf("%.2lf ",j);
                i=j;
            }
        }
        if(a*i*i*i+b*i*i+c*i+d>0)
        {
            if(a*j*j*j+b*j*j+c*j+d<0)
            {
                printf("%.2lf ",j);
                i=j;
            }
        }
    }
    printf("\n");
    return 0;
}