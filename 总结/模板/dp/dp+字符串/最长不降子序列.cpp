//From - Milky Way

#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;

int d[100], c[100], a[100], len = 1;

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i)
    {
        scanf("%d", &a[i]);
    }

    d[1] = a[1], c[1] = 1;
    for (int i = 2; i <= n; ++ i)
    {
        if (d[len] <= a[i])
        {
            d[++ len] = a[i], c[i] = len;
        }
        else
        {
            int j = upper_bound(d + 1, d + len + 1, a[i]) - d;
            d[j] = a[i], c[i] = j;
        }
    }

    stack<int> sta;
    for (int i = n, j = len; i >= 1; -- i)
    {
        if (c[i] == j)
        {
            sta.push(a[i]);
            --j;
        }
        if (j == 0) break;
    }

    printf("%d\n", len);
    while (!sta.empty())
    {
        printf("%d ", sta.top());
        sta.pop();
    }

    return 0;
}

//最长不下降之输出子序列 - NlogN
