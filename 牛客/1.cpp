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
int main()
{
	ll n;
	scanf("%lld",&n);
	while(n--)
	{
		ll t,flag=0;
		scanf("%lld",&t);
		if(t&1||t==2)
		{
			printf("NO\n");
			continue;
		}
		else
		{
			while(t)
			{
				t&1?flag++:t;
				t>>=1;
			}
			if(flag==2||flag==1)printf("YES\n");
			else printf("NO\n");
		}
	}
//	system("pause");
	return 0;

}
