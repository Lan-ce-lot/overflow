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
const int maxn=500005;
class TA
{
	private:
		int e[maxn];
		int len;
		int lowbit(int k)
		{
			return k & (-k);
		}
	public:
		void add(int x,int v)													//区间更新
		{
			while(x <= len)
			{
				e[x] += v;
				x += lowbit(x);
			}
		}
		void init(int* getin,int _len)											//初始化
		{
			
			len = _len;
			for(int i = 1;i <= len;i ++)
			{
				e[i] = 0;
				add(i,*(getin + i - 1));
			 }
		}
		ll getsum(int x)														//询问
		{
			ll sum = 0;
			while(x > 0)
			{
				sum += e[x];
				x -= lowbit(x);
			}
			return sum;
		}

};

TA ta;
int n,t,m,b[maxn];
int main()
{
	
	while(~scanf("%d",&n))
	{
		if(n == 0)return 0;	
		ta.init(b,n);
		for(int i = 0;i < n;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			ta.add(a,1);
			ta.add(b + 1,-1);
			
		}
		for(int i=1;i<=n;i++)
		{
			if(i==n)
			{
				cout<<ta.getsum(i)<<endl;
			}
			else
			{
				cout<<ta.getsum(i)<<' ';
			}
		}
		
	}
    return 0;
}
