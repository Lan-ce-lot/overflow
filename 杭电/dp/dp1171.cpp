#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<map>
#include<set>
#include<bitset>
#include<string>
#include<cmath>
#include<sstream>
using namespace std;
typedef long long ll;
const double pi=acos(-1.0);
const int eps=1e-10;
const int mod=1e9+7;
const int INF=0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn=10000005;
int m[maxn],v[maxn],dp[maxn];

int a[maxn];
int main()
{
    int n,sum_v,sum_m;//v，m 
    while(~scanf("%d",&n) && n >= 0)
    {
    	sum_v = 0,sum_m = 0;
    	int z = 0;
    	for(int i = 0;i < n;i++)
    	{
    		scanf("%d%d",&v[i],&m[i]);
    		sum_v += v[i] * m[i];
    		sum_m += m[i];
    		for(int j = 0;j < m[i];j++)
    		{
    			a[z] = v[i];
    			z++;
			}
		}
		memset(dp,0,sizeof(dp));
    	for(int i = 0;i < sum_m;i++)
    	{
    		for(int j = sum_v / 2;j >= a[i];j--)
    		{
    			dp[j] = max(dp[j],dp[j - a[i]] + a[i]);
			}
		}
		printf("%d %d\n",max(dp[sum_v / 2],sum_v - dp[sum_v / 2]),min(dp[sum_v / 2],sum_v - dp[sum_v / 2]));
	} 
    return 0;
}
//#include<stdio.h>
//#include<iostream>
//#include<string.h>
//using namespace std;
//int V,N,weight[10002],v[10002];
//long int f[100002];
//int OnePack()  //0-1背包的主要思想
//{
//    memset(f,0,sizeof(f));
//    for(int i=0;i<N;i++)
//    {
//        for(int j=V;j>=weight[i];j--)
//            f[j]=max(f[j],f[j-weight[i]]+v[i]);
//    }
//    return f[V];
//}
//int main()
//{
//    int t,a,b,x,y,z;
//    while(scanf("%d",&t)&&t>0)
//    {
//        N=V=0;  //每次背包的N和V都要更新
//        int i=0;
//        while(t--)
//        {
//            scanf("%d%d",&a,&b);
//            N+=b;
//            V+=a*b;
//            while(b--)
//            {
//                v[i]=a;  //记录每件物品的价值
//                weight[i]=a;  //记录每件物品的重量
//                i++;
//            }
//        }
//        z=V; 
//        V/=2;
//        x=max(OnePack(),z-OnePack());  //最大的设施价值放前面
//        y=min(OnePack(),z-OnePack());
//        cout<<x<<" "<<y<<endl;
//    }
//    return 0;
//}
 
