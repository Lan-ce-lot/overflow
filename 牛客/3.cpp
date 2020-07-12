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
ll lowbit(ll x)
{
	return x&-x;
}
int main()
{
	int a=1;
	while(a++)
	printf("%lld\t",lowbit(a));
//	system("pause");
	return 0;

}
