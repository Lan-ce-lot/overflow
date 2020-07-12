#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<algorithm> 
#include<stack> 
using namespace std;
typedef long long ll;
#define PI 3.1415927
#define M(a) memset(a,0,sizeof(a))
const int INF=0x3f3f3f3f;
int f(int x)
{
	return x==1||x==0?1:x*f(x-1);
}
int main()
{
	int a=10;
	printf("%d",f(a));
 } 
