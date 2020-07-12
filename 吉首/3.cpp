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
	int a;
	while(~scanf("%d",&a))
	{
		int sit,b[10000];
		scanf("%d",&sit);
		for(int i=0;i<a;i++)scanf("%d",&b[i]);
		for(int i=sit-1;;i++)
		{
			if(i==a)i=0;
			if(b[i])i;
			else
			{
				printf("%d\n",i+1);
				break;
			}
		}
		
	}
	

//	system("pause");
	return 0;

}
