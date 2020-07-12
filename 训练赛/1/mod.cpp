#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int a[51];
	for(long long int i = 1; i < 16;i++)
	{
		a[i] = 1;
		for(long long int j = 1; j <= i;j++)
		{
			a[i] = a[i]*i;
		}
	}
	
	
	long long int n;
	while(~scanf("%lld",&n))
	{
		int ans = 0;
		for(int i = 1; i < 16;i++)
		{
			if(n >= a[i])
			ans++;
			if(n < a[i])
			break;
		}
		printf("%d\n",ans);
		
	}
	return 0;
}
