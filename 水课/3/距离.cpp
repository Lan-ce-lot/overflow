#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<algorithm> 
#include<vector> 
using namespace std;
typedef long long ll;
#define PI 3.1415927
#define M(a) memset(a,0,sizeof(a))
const int INF=0x3f3f3f3f;
int main()

{
	ll n,a,b,x1,x2,yl,y2;
	scanf("%lld%lld%lld",&n,&a,&b);
	(a/n)&1&&a%n!=0?x1=a%n,yl=a/n:x1=n-a%n+1,yl=a/n;
	(b/n)&1&&b%n!=0?x2=b%n,y2=b/n:x2=n-b%n+1,y2=b/n;
	cout<<abs(x1-x2)+abs(yl-y2)<<endl;
	return 0;
}
