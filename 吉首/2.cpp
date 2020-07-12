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
		int b=a,c=0;
		for(int i=1;c<=b;c++,i++,b--)
		{
			printf("%d. %d+%d=\n",i,c,b);
		}
	}
	

//	system("pause");
	return 0;

}
