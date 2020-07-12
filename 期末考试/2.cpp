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
	int n,a;
	while(scanf("%d",&n)&&n)
	{
		int max1=-100;
		while(n--)
		{
			scanf("%d",&a);
			max1=max(a,max1);
		}
		printf("%d\n",max1);
		
	}
	


	return 0;

}
