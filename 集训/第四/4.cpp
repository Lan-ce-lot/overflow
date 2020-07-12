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
	int a[7],i=0,sum=0,ans=0,flag=0;
	for(int i=0;i<6;i++)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
	 } 
	 if (sum % 2 != 0)
	{
		printf("NO\n");
		return 0;
	}
for (int i = 0; i < 4; ++i)
{
	for (int j = i + 1; j < 5; ++j)
	{
		for (int k = j + 1; k < 6; ++k)
		{
			if ((a[i] + a[j] + a[k]) == (sum / 2))
			{
				flag = 1;
				break;
			}
		}
	}
}
	flag?printf("YES\n"):printf("NO\n");

	return 0;

}
