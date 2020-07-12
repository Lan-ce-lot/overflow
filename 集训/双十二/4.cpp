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
	int n,t,flag=1;
	char a[100][100];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%s",a[i]);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(strcmp(a[i],a[j])==0)
			{
				printf("YES\n");
				flag=0;
				break;
			}	
		}
		if(flag==0)
			continue;
		else
			printf("NO\n");
	}
	return 0;
}
