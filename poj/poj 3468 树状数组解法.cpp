//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//#include<queue>
//#include<stack>
//#include<vector>
//#include<map>
//#include<set>
//#include<bitset>
//#include<string>
//#include<cmath>
//#include<sstream>
//using namespace std;
//typedef long long ll;
//const double pi=acos(-1.0);
//const int eps=1e-10;
//const int mod=1e9+7;
//const int INF=0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
//const int maxn=1e5 + 5;
//
//ll c1[maxn];
//ll c2[maxn];
//ll sum[maxn];
//ll n,q;
//ll a[maxn];
//int lowbit(int x)
//{
//    return x & -x;
//}
//
//void add(ll a[], int x, int k)
//{
//    while (x <= n)
//    {
//        a[x] += k;
//        x += lowbit(x);
//    }
//}
//
//ll getsum(ll a[],int x)
//{
//    ll sum = 0;
//    while (x > 0)
//    {
//        sum += a[x];
//        x -= lowbit(x);
//    }
//    return sum;
//}
//
//ll query(int s)
//{
//    return s * getsum(c1, s) - getsum(c2, s);
//}
//
//int main()
//{
//    scanf("%lld%lld", &n, &q);
//    ll temp = 0;
//    for (int i = 1; i <= n; i++)
//    {
//        scanf("%lld", &a[i]);
//        add(c1, i, a[i] - temp);
//        add(c2, i, (i - 1) * (a[i] - temp));
//        temp = a[i];
//    }
//    while (q--)
//    {
//        char c;
//        ll ans = 0, x, y, v;
//        getchar();
//        c = getchar();
//        if (c == 'Q')
//        {
//            scanf("%lld%lld", &x, &y);
//            printf("%lld\n", query(y) - query(x - 1));
//        }
//        else
//        {
//            scanf("%lld%lld%lld", &x, &y, &v);
//            add(c1, x, v);
//            add(c1, y + 1, -v);
//            add(c2, x, (x - 1) * v);
//            add(c2, y + 1, -v * y);
//        }
//    }
//    return 0;
//}


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
const int maxn=1e5 + 5;

ll c1[maxn];
ll c2[maxn];
ll sum[maxn];
ll n,q;
ll a[maxn];
int lowbit(int x)
{
    return x & -x;
}

void add(ll a[], int x, int k)
{
    while (x <= n)
    {
        a[x] += k;
        x += lowbit(x);
    }
}

ll getsum(ll a[],int x)
{
    ll sum = 0;
    while (x > 0)
    {
        sum += a[x];
        x -= lowbit(x);
    }
    return sum;
}

ll query(int s)
{
    return s * getsum(c1, s) - getsum(c2, s);
}

int main()
{
    scanf("%lld%lld", &n, &q);
    ll temp = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        sum[i] = sum[i - 1] + a[i];
    }

    while (q--)
    {
        char c;
        ll ans = 0;
        int x, y, v;
        getchar();
        c = getchar();

        if (c == 'Q')
        {
            scanf("%d%d", &x, &y);
            ans = sum[y] - sum[x - 1];
            ans += (y + 1) * getsum(c1, y) - getsum(c2, y);
            ans -= (x * getsum(c1, x - 1) - getsum(c2, x - 1));
            printf("%lld\n", ans);
        }
        else
        {
            scanf("%d%d%d", &x, &y, &v);
            add(c1, x, v);
            add(c1, y + 1, -v);
            add(c2, x, x * v);
            add(c2, y + 1, -v * (y + 1));
        }
    }
    return 0;
}
