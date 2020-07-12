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
int main()
{
	int n,t=0;
	scanf("%d",&n);
	int a[1000];
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	if(n==1)
		printf("0");
	else
	{
		for(int i=0;i<n-1;i++)
		{
			t+=(a[n-1]-a[i]);
		}
			
		printf("%d",t);
	}
	return 0;

}
