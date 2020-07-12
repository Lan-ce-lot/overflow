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
int a[30][20],sum=0,b[30][20];
int main()

{
	int t,n;
	while(~scanf("%d%d",&t,&n))
	{
		M(a),M(b);
		cout<<'v';
		for(int i=0;i<t;i++)
            for(int j=0;j<n;j++)
				 scanf("%d",&a[i][j]);
				
		for(int i=t-1;i>=1;i--)
		{
			for(int j=0;j<n;j++)
			{
				b[i-1][j]=INF;
				for(int z=0;z<n;z++)
				{
					b[i-1][j]=min(b[i-1][j],abs(a[i-1][j]-a[i][z])+b[i][z]);
				}            
			}
		}
		int ans;
		ans=*min_element(b[0],b[0]+n);
		printf("%d\n",ans);
	}
	return 0;
}
