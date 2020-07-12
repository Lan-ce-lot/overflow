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
    int len = maxn;
    int lowbit(int k)
    {
        return k & (-k);
    }
public:
    void add(int x,int v)													//�������
    {
        while(x <= len)
            e[x] += v,x += lowbit(x);
    }
    void init(int* getin,int _len)											//��ʼ��
    {
        len = _len;
        for(int i = 1; i <= len; i ++)
            add(i,*(getin + i - 1));
    }
    void init_0()
    {
        len = maxn,memset(e, 0, sizeof(e));
    }
    int getsum(int x)														//ѯ��
    {
        int sum = 0;
        while(x > 0)
            sum += e[x],x -= lowbit(x);
        return sum;
    }
    void range_add(int l, int r, int x)  //������[l, r]����x
    {
        add(l, x), add(r + 1, -x);
    }
    int range_ask(int l, int r)  //�������
    {
        return getsum(r) - getsum(l - 1);
    }
} ta;

int a[maxn],n,m;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n; i ++)
    {

        scanf("%d",&a[i]);

    }
    ta.init(a + 1,n);
    for(int i = 1; i <= m; i ++)
    {
        int ope,a,b;
        scanf("%d%d%d",&ope,&a,&b);
        if(ope == 1)
        {
            ta.add(a,b);
        }
        else
        {
            cout<<ta.getsum(b)-ta.getsum(a-1)<<endl;
        }
    }
    return 0;
}
