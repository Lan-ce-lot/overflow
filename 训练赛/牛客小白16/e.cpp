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
int a[1005][2]={0};

int main()
{


		a[0][1]=1;
	int m,n,x,ans;
	cin>>m>>n;
	for(int i=1;i<=m;i++)
		cin>>a[i][0];
	while(n--)
	{
		ans=0;
		cin>>x;
		for(int i=1;i<=m;i++)
		{
			if(a[i][1]==0&&a[i][0]<=x)
				a[i][1]=1;
			else if(a[i-1][1]==1&&a[i][0]>x)
				ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
//		a[0][1]=1;
//	int m,n,x,ans;
//	cin>>m>>n;
//	for(int i=1;i<=m;i++)
//	cin>>a[i][0];
//	while(n--)
//	{
//		ans=0;
//		cin>>x;
//		for(int i=1;i<=m;i++)
//		{
//			if(a[i][1]==0&&a[i][0]<=x)
//			a[i][1]=1;
//			else if(a[i-1][1]==1&&a[i][0]>x)
//			ans++;
//		}
//		cout<<ans<<endl;
//	}
