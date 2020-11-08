
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#define int long long
using namespace std;
const int mod = 1000000007;
int t, dis[1000005][3], n, a, b, x;
int find(int x)
{
    return x == dis[x][0] ? x : (dis[x][0] = find(dis[x][0]));
}
void uni(int x, int y)
{
    int xx = find(x);
    int yy = find(y);
    if (xx != yy)
    {
        dis[xx][0] = yy;
        dis[yy][1] += dis[xx][1];
        dis[yy][2] += dis[xx][2];
    }
}
signed main()
{
    scanf("%lld", &t);
    while (t--)
    {
        int s1 = 0, s2 = 0;
        int ans = 0;
        memset(dis, 0, sizeof(dis));
        scanf("%lld", &n);
        for (int i = 1; i <= n; i++)
        {
            dis[i][0] = i; 
            scanf("%lld", &x);
            dis[i][x]++;
            if (x == 1)
                s1++;
            else
                s2++;
        }
        if (s2 >= 3)
            ans = s2 * (s2 - 1) * (s2 - 2) / 6 % mod;
        if (s2 >= 2)
            ans = (ans + s2 * (s2 - 1) / 2 % mod * s1) % mod;
        for (int i = 0; i < n - 1; i++)
        {
            printf("%lld\n", ans);
            scanf("%lld%lld", &a, &b);
            a = find(a);
            b = find(b);
            ans -= dis[a][2] * dis[b][2] % mod * (s2 - dis[a][2] - dis[b][2]) % mod;
            ans = (ans % mod + mod) % mod;
            ans -= dis[a][2] * dis[b][2] % mod * (s1 - dis[a][1] - dis[b][1]) % mod;
            ans = (ans % mod + mod) % mod;
            ans -= dis[a][2] * dis[b][1] % mod * (s2 - dis[a][2] - dis[b][2]) % mod;
            ans = (ans % mod + mod) % mod;
            ans -= dis[a][1] * dis[b][2] % mod * (s2 - dis[a][2] - dis[b][2]) % mod;
            ans = (ans % mod + mod) % mod;
            uni(a, b);
        }
        printf("%lld\n", ans);
    }
}
