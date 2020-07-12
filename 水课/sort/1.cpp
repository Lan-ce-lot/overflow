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
int a[300];
int main()
{
	int n,k,sum=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n,greater<int >());
	scanf("%d",&k);
	for(int i=0;i<k;i++)
		sum+=a[i];
		printf("%.2lf",1.0*sum/k);
//	system("pause");
	return 0;

}
