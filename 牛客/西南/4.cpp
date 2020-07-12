#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<algorithm> 
using namespace std;
int main()
{
	int n,a[5005];
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		if(a[a[a[i]]]==i)
		{
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}
