#include<bits/stdc++.h>
using namespace std;
#define maxn 110
typedef long long ll;
ll a[maxn];
ll n, num1 = 0, num2 = 0, num3 = 0;
ll check()
{
    bool flag;
    ll ret = 0;
    for(int p = 1; p <= n; p++)
    {
        flag = false;
        ll res = 1000000000;
        for(int i = 0; i <= num1; i++)
        {
            for(int j = 0; j <= num2; j++)
            {
                for(int k = 0; k <= num3; k++)
                {
                    ll ans = i * 10 + j * 20 + k * 50;
                    if(ans > a[p])
                        continue;
                    if((a[p] - ans) % 100 == 0)
                    {
                        flag = true;
                        res = min(res, (a[p] - ans) / 100);
                    }
                }
            }
        }
        if(flag)
            ret = max(ret, res);
        else
            break;
    }
    if(!flag)
        return -1;
    return ret;
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%lld", &n);
        for(int i = 1; i <= n; i++)
            scanf("%lld", &a[i]);
        ll num = 100000000000;
        bool flag = false;
        for(int i = 0; i <= 1; i++)
        {
            for(int j = 0; j <= 3; j++)
            {
                for(int k = 0; k <= 1; k++)
                {
                    num1 = i;
                    num2 = j;
                    num3 = k;
                    if(check() == -1)
                        continue;
                    else
                    {
                        flag = true;
                        num = min(num, num1 + num2 + num3 + check());
                    }
                }
            }
        }
        if(flag)
            printf("%lld\n", num);
        else
            printf("-1\n");
    }
    return 0;
}
