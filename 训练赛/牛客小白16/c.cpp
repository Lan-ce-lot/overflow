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
#define PI 3.1415926535898
#define M(a) memset(a,0,sizeof(a))
const int INF=0x3f3f3f3f;
int main()

{
	double n,ans=0;
	cin>>n;
	
	ans=n/PI;
	ans*=ans;
	ans*=PI;
	ans/=2.0;
	printf("%.3lf\n",ans);
//printf("%.3lf\n",ans);
	return 0;

}
