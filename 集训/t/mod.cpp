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
	int n,k,t=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		if(240-k-5*(1+i)*i/2<0)
		{
			t=i-1;
			break;
		}
		t=i;
		
	}	
	printf("%d",t);
		


	return 0;

}
