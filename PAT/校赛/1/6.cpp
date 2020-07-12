#include<bits/stdc++.h> 
using namespace std;
const int INF=0x3f3f3f3f;
#define N 1000000
#define PI 3.1415927
#define M(a) memset(a,0,sizeof(a))
typedef long long ll;
int cave[200005];
int main()
{
	int n,a,b,a1,b1;
	cin>>n>>a>>b;
	a1=a,b1=b;
	for(int i=0;i<n;i++)
	{
		cin>>cave[i];	
	}
	for(int i=0;i<n;i++)
	{
	//	cout<<a<<b<<endl;
		if(cave[i])
		{
			if(a>0)
			{
				if(b<b1)
				{
					a--;
					b++;
				}
				else if(b>0)
				{
					b--;
				}
				else if(b=0)
				{
					a--;
				}
			}
			else
			{
				b--;		
			}
		}
		else
		{
			if(b>0)
			{
				b--;
			}
			else
			{
				a--;
			}
		}
		if(a==0&&b==0)
		{
			cout<<i+1<<endl;
			return 0;
		}
	}
	return 0;
}
