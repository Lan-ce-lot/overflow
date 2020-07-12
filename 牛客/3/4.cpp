#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll l,r;
ll m(ll x)
{
    ll ans=0,t=0,s=1,f=0;
    while(x)
    {
        ll k=x%10;
        if(k<6)
        	ans+=f*k;
        else if(k==6)
        	ans=f*k+t+1;
        else
        	ans+=(k-1)*f+s;
        f=9*f+s;
        t+=k*s;
        s*=10;
        x/=10;cout<<endl<<f<<endl<<t<<endl<<s<<endl<<ans<<endl;
    }
    
    return ans;
}
int main()
{
    scanf("%lld%lld",&l,&r);
    printf("\n%lld\n",m(r)-m(l-1));
}
