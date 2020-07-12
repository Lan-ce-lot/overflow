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
int a[1000005],b[1000005],c[1000005];
int main()

{
	int n,ans=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		
	}
	if(n==1)
	{
		puts("0");
		return 0;
	}
	sort(a,a+n);
	for(int i=0,j=0;i<n;i+=2,j++)
	{
		b[j]=a[i];
	}
	c[0]=a[0];
	for(int i=1,j=1;i<n;i+=2,j++)
	{
		c[j]=a[i];
	}
	for(int i=0;i<n/2-1;i++)
	{
		ans=max(abs(c[i+1]-c[i]),ans);
		ans=max(abs(b[i+1]-b[i]),ans);
	}
	ans=max(ans,a[n-1]-a[n-2]);
	cout<<ans<<endl;
	return 0;

}
