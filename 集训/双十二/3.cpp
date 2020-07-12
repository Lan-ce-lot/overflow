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
	int n,count=0;
	scanf("%d",&n);
	char a[100000];
		scanf("%s",a);
	for(int i=0;i<n-1;i++)
	{
		if(a[i]=='S'&&a[i+1]=='F')
			count++;
		else if(a[i]=='F'&&a[i+1]=='S')
			count--;
	}
	if(count>0)printf("YES\n");
	else printf("NO\n");
//	printf("%d",count);
	return 0;
}
