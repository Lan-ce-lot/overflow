#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAX = 1e6+10;
int a[MAX];
int x,w;
int main()
{
	int t,n,S;
	cin>>t;
	while(t--)
	{
		cin>>n>>S;
		int ans=n+1,l=0,r=0,sum=0;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		for(;;)
		{
			while(r<n&&sum<S)
			{
				sum+=a[r++];
			}
				
			if(sum<S)
			{
				break;
			}
			ans=min(ans,r-l);
			sum-=a[l++];
		}
		if(ans>n)
			ans=0;
		cout<<ans<<endl;
		
	}
	return 0;
}
