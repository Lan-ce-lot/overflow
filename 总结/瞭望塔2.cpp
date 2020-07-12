#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<algorithm> 
#include<stack> 
using namespace std;
typedef long long ll;
#define PI 3.1415927
#define M(a) memset(a,0,sizeof(a))
const int INF=0x3f3f3f3f;
int n,b,ans[1000001],a[1000001];
stack<int> s;
int main()
{
	scanf("%d",&n);
	for(int i=0,j=0;i<n;i++,j++)
	{
		scanf("%d",&a[i]);
	}
	s.push(0);
	for(int i=1;i<n;i++)
	{
		if(a[s.top()]>a[i])
		{
			s.push(i);
		}
		else
		{
			while(!s.empty()&&a[s.top()]<=a[i])
			{
				ans[s.top()]=i-s.top();
				s.pop();
			}			
			s.push(i);
		}
	}
	while(!s.empty())
	{
		ans[s.top()]=n-1-s.top();
		s.pop();
	}
	for(int i=0;i<n;i++)
	{
		i==n-1?puts("0"):printf("%d ",ans[i]);
	}
	return 0;
}
