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
int a[300005];
int sum[300005];
int main()

{
	int n,m,ans=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum[i]=a[i]+sum[i-1];
	 } 
	for(int r=1;r<=n;r++)
	{
		for(int l=1;l<=r;l++)
		{
			sum[r]-sum[l-1]<m?ans++:l;
		}
	}
	printf("%d\n",ans);
	
	
	

//	system("pause");
	return 0;

}
