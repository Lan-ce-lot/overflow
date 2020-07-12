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
	int ha,li;
	scanf("%d%d",&ha,&li);
	for(int i=1;i<=2*ha+1;i++)
	{
		for(int j=1;j<=2*li+1;j++)
		{
			if(i&1)
			{
				j&1?printf("+"):printf("-");
				j==2*li+1?printf("\n"):i;
			}
				
			else
			{
				j&1?printf("|"):printf("*");
				j==2*li+1?printf("\n"):i;
			}
		}	
	}
	return 0;
}
