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
	int n,an;
	while(~scanf("%d",&n))
	{
		if(n==1)
		{
			printf("0\n");continue;
		}
		/*else if(n==2)
		{
			printf("16\n");continue;
		}*/
		an=(n-2)*(n-2)*(n-2)*(n*n*n-7)+(n*n*n-6)*(n-2)*(n-2)*6+(n*n*n-4)*8+12*(n-2)*(n*n*n-5);
		printf("%d\n",an/2);
	 } 
	return 0;
}
