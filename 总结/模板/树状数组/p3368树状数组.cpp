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
int a[maxn],n,t,m,b[maxn];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++)
    {
        scanf("%d",&a[i]);
    }
    b[1] = a[1];
    for(int i = 2;i <= n;i++)
    {
        b[i] = a[i] - a[i - 1];
    }
    ta.init(b + 1,n);
    while(m--)
    {
        int idenx,x,y,k;
        scanf("%d",&idenx);
        if(idenx == 1)
        {
            scanf("%d%d%d",&x,&y,&k);
            ta.add(x,k);
            ta.add(y + 1,-k);
        }
        else
        {
            scanf("%d",&x);
            printf("%lld\n",ta.getsum(x));
        }
    }
    return 0;
}
