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
int a[1000],n,b1=0,b2=0,b3=0,b4=0,b5=0,b6=0;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==100)
			b1++;
		else if(a[i]>=90&&a[i]<=99)b2++;
		else if(a[i]>=80&&a[i]<=89)b3++;
		else if(a[i]>=70&&a[i]<=79)b4++;
		else if(a[i]>=60&&a[i]<=69)b5++;
		else b6++;
	}
	sort(a,a+n,greater<int>());
	for(int i=0;i<n;i++)
		printf("%d\n",a[i]);
	printf("%d %d %d %d %d %d\n",b1,b2,b3,b4,b5,b6);


	return 0;

}
