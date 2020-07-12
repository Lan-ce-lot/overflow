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
const int maxn=200005;
double x[maxn],y[maxn];
ll read(){
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int line[4]={1,1,1,1};//1/3,1,-1,0
double a[maxn];
int main()
{
	int n,ans=0,ansl=0,count1=0,count13=0,count_1=0,count0=0,count=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x[i]>>y[i];
		
	}
	int z=0;
	for(int i=0;i<n;i++)//1/3,1,-1,0
	{
		for(int j=0;j<n;j++)
		{
			if(i!=j)
			{
				if(x[i]!=x[j])
				{
					a[z++]=((y[i]-y[j])/(x[i]-x[j]));
					
				}
				else
				{
					a[z++]=INF;
				}
			}	
			
		}
		
	}
	sort(a,a+z);
	
    cout<<unique(a,a+z)-a<<endl;
    return 0;
}
