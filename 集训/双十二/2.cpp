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
	int n,sum=0;
	scanf("%d",&n);
	int a[10000];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		sum+=a[i]*(i)*4;
	}
	printf("%d\n",sum);
	


	return 0;

}
