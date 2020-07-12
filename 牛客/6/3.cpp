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
struct s{
	int ai,bi;
}b[1000005];
bool cmp(s a,s b)
{
	return a.bi>b.bi;
}
int main()
{
	int n,m,ans=0,sum=0,ans1=0;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d",&b[i].ai);sum+=b[i].ai;
	}
	for(int i=0;i<m;i++)
	{
		scanf("%d",&b[i].bi);ans1+=(b[i].ai*b[i].bi);
	}
	sort(b,b+m,cmp);
	if(sum<=n)
	{
		
		printf("%d\n",ans1);
		return 0;
	}
	for(int i=0,t=0;i<m;i++)	
	{
		for(int j=0;j<b[i].ai;j++,t++)
		{
			ans+=b[i].bi;
			if(t+1>=n)
			{
				cout<<ans<<endl;
				return 0;
			}
		}	
	}

//	system("pause");
	return 0;

}
