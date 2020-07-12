#include<bits/stdc++.h> 

using namespace std;
const int INF=0x3f3f3f3f;
#define N 1000000
#define PI 3.1415927
#define M(a) memset(a,0,sizeof(a))
typedef long long ll; 
ll a[1000005];
int main()
{
	ll n,sum=0,ans=-1;
	set<int> q;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		q.insert(a[i]);	
	}
	
	set<int> ::iterator it=q.begin();
	for(int i=0;i<q.size();i++)
	{
		for(int j=0;it!=q.end();it++,j++)
		{
			i!=j?sum|=*it:i;
		}
		i++;
		ans=max(ans,sum);
	}
	cout<<ans<<endl;
	
	return 0;
}
