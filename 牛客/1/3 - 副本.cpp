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
int a[100005],dp[100005] ,n;
int main()
{
	scanf("%d",&n);
    scanf("%d",&a[1]);
    dp[1]=a[1];
    for(int i=2;i<=n;i++)
    {
    	scanf("%d",&a[i]);
    	for(int j=1;j<i;j++)
    	{
    		
		}
	}
	

//	system("pause");
	return 0;

}
