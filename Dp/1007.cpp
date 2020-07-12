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
int a[1002]={0},b[1002]={0},c[1002];
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		if(n==0)
			return 0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			c[i]=b[i];
		}
			
		int sb=0,sum=0;
		for(int i=n-1;i>=0;i--)
		{
			int ab=a[i];
			int t=ab;
			for(int j=1;j<=i;j++)
			{
				
				if(ab>a[i-j]&&b[i]!=1)
				{
					c[i-j]+=t;
					b[i-j]=1;
					ab=a[i-j];
					t=c[i-j];
					cout<<c[i-j]<<endl;
				}
			
			}		cout<<'.';
		}
		sum=*max_element(c,c+n);
			printf("%d\n",sum);
	}
	return 0;
}
