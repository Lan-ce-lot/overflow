#include <iostream>
#include<algorithm>
using namespace std;
#define ll long long 
ll gcd(ll a,ll b)
{
	return b?gcd(b,a%b):a;
}
int main()
{
    ll n=1;
    int a=45;
    for(int i=1;i<=a;i++)
    {
    	if(i!=43)n=n/gcd(n,i)*i;
	}
	printf("%lld",n);
    return 0;
}
