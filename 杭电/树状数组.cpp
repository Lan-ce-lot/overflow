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
const int maxn=100005 * 4;
class TA
{
private:
    int e[maxn];
    int len = maxn;
    int lowbit(int k)
    {
        return k & (-k);
    }
public:
    void add(int x,int v)													//单点更新
    {
        while(x <= len)
            e[x] += v,x += lowbit(x);
    }
    void init(int* getin,int _len)											//初始化
    {
        len = _len;
        for(int i = 1; i <= len; i ++)
            add(i,*(getin + i - 1));
    }
    void init_0()
    {
        len = maxn,memset(e, 0, sizeof(e));
    }
    int getsum(int x)														//询问
    {
        int sum = 0;
        while(x > 0)
            sum += e[x],x -= lowbit(x);
        return sum;
    }
    void range_add(int l, int r, int x)  //给区间[l, r]加上x
    {
        add(l, x), add(r + 1, -x);
    }
    int range_ask(int l, int r)  //区间求和
    {
        return getsum(r) - getsum(l - 1);
    }
} ta;

int a[maxn],n,m;//区间查询，单点修改
int main()
{
    while (~scanf("%d",&n))
    {
        int ans = 0, sum = 0;
        ta.init_0();
        for (int i = 1;i <= n; i++)
        {
            scanf("%d", &a[i]);
            ans += ta.range_ask(a[i] + 1, n);
            ta.add(a[i] + 1, 1);
        }

        sum = ans;
        for (int i = 1; i <= n - 1; i++)
        {
            sum = sum - 2 * a[i] + n - 1;
            ans = min(ans , sum);
        }
        printf("%d\n", ans);
    }
    return 0;
}
