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
int a[1001];
char b[400][400],zz;
int main()
{
	memset(b,' ',sizeof(b));
	a[0]=1;
	for(int i=1;i<1001;i++)
		a[i]=a[i-1]+4*i+2;
		
	int n,t;
	scanf("%d %c",&n,&zz);
	if(n==1)
	{
		printf("%c\n0",zz);return 0;
	}	
	for(int i=0;i<n;i++)
		if(a[i]>n)
		{
			t=i-1;break;
		}
	 for(int i=0;i<2*t+1;i++)
	 	for(int j=min(2*t-i,i);j<max(2*t+1-i,i+1);j++)
	 		b[i][j]=zz;
	 		
	 for(int i=0;i<2*t+1;i++)
	 	for(int j=0;j<2*t+1;j++)
	 	{
	 		if(j<=2*t-i||j<=i)
	 		{
	 			printf("%c",b[i][j]);
			 }
			 j==2*t?printf("\n"):i;
		 }		
	printf("%d",n-a[t]);
	return 0;
}
