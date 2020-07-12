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
	char a[100];
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s",a);
		if(a[0]='T')t+=4;
		else if(a[0]='C')t+=6;
		else if(a[0]='O')t+=8;
		else if(a[0]='D')t+=12;
		else if(a[0]='L')t+=20;
	}
	printf("%d",t);
	


	return 0;

}
