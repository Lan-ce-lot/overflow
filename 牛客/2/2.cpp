#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<algorithm> 
using namespace std;
typedef long long ll;
#define PI 3.1415927
#define M(a) memset(a,0,sizeof(a))
const int INF=0x3f3f3f3f;
struct zz{
	int f,k;
}a[100005];
bool cmp(zz a,zz b)
{
	return a.k<b.k;
}
int main()
{
	int n,sum=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i].f);
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i].k);
	}
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++)
	{
		if(a[i].f>a[i].k-sum-i*2)
		{
			puts("NO");
			return 0;	
		}
		sum+=a[i].f;
	}
	puts("YES");
	return 0;
}
