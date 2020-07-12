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
bool cmp(int a,int b)
{
	return a%3!=b%3?a%3<b%3:a<b;
}
int n,a[1000];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++)
		i==n-1?printf("%d\n",a[i]):printf("%d ",a[i]);

	return 0;

}
