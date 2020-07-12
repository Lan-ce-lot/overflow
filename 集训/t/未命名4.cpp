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
	int a[27],t,v=0;
	char b[1001];
	scanf("%s",b);
	scanf("%d",&t);
	int l=strlen(b);
	for(int i=0;i<26;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<l;i++)
		v+=(i+1)*a[b[i]-'a'];
	sort(a,a+26);
	for(int i=l+1;i<=l+t;i++)
		v+=i*a[25];
	printf("%d\n",v);
	return 0;
}
