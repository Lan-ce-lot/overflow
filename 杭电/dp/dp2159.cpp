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
const int maxn=205;

int n,m,k,s,dp[maxn][maxn];
int v[maxn], w[maxn];

int main()
{
    while (~scanf("%d%d%d%d", &n, &m, &k, &s))  //n经验  m忍耐 k种类 s数量
    {
        int flag = 1;

        for (int i = 1;i <= k;i++)
        {
            scanf("%d%d", &v[i], &w[i]);        //vj,wr
        }
        memset(dp, 0, sizeof(dp));
        for (int i = 1;i <= m;i++)
        {                                       //m
            for (int j = 1;j <= k;j++)           //k
                for (int z = 1;z <= s;z++)       //s
                    if (w[j] <= i)
                        dp[i][z] = max(dp[i][z], dp[i - w[j]][z - 1] + v[j]);
            if (dp[i][s] >= n)
            {
                printf("%d\n",m - i);
                flag = 0;
                break;
            }
        }
        if (flag)
            printf("-1\n");//最大忍耐度，恰好升级
    }
    return 0;
}

