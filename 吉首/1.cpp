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
char c[100000];
int main()
{
	int a,b;
	while(~scanf("%d%d",&a,&b))
	{
		int d=(a+b),t;
		if(a+b>=1000)
		{
			for(int i=1;d!=0;i++)
			{
				c[i]=d%10,d/=10;
				t=i;
			}
			for(int i=t;i>0;i--)
			{
				i%3==0&&i!=t?printf(",%d",c[i]):printf("%d",c[i]);
				if(i==1)printf("\n");
			}
		}
		else
		printf("%d\n",a+b);
	 } 
//	system("pause");
	return 0;

}
