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
	int n,a[100000],ans1=0,ans2=0,max1;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<n;i++)
	{
		if(a[i]>500000)
		{
		 	ans2=1000000-a[i];
		 	max1=a[i-1];
			break; 
		}
	}
	ans2==0?ans1=*max_element(a,a+n)-1:ans1=max1-1;
	printf("%d\n",max(ans1,ans2));
	return 0;
}
