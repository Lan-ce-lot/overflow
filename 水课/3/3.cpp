#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<algorithm> 
#include<vector> 
using namespace std;
typedef long long ll;
#define PI 3.1415927
#define M(a) memset(a,0,sizeof(a))
const int INF=0x3f3f3f3f;
int main()

{
	int n,l,r;
	scanf("%d%d%d",&n,&l,&r);
	int c=abs(l-r);
	int x1=c%n;
	int x2=c/n;
	if((l/n)%2==(r/n)%2)
	{
		printf("%d\n",x2+abs(l%n-r%n));
	}
	else
	{
		printf("%d\n",x2+abs(l%n+r%n-1));
	}
//	system("pause");
	return 0;

}
