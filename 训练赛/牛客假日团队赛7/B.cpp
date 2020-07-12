#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<map>
#include<set>
#include<bitset>
#include<string>
#include<cmath>
#include<sstream>
using namespace std;
typedef long long ll;
const double pi=acos(-1.0);
const int eps=1e-10;
const int mod=1e9+7;
const int INF=0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn=5005;
ll read(){
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int a[maxn];
int main()
{
	ll n,sum=0;
	double ans_mean=0,ans_median=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
	
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	sort(a,a+n);
	if(n&1)//ji
	{
		ans_median=a[n/2];
	}
	else
	{
		ans_median=(a[n/2-1]+a[n/2])/2.0;
	}
	ans_mean=sum/(double)n;
    printf("%.6lf\n%.6lf\n",ans_mean,ans_median);
    
    return 0;
}
