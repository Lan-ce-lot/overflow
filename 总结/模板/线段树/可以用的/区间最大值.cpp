#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;


typedef long long ll;

const int maxn = 1e5 + 5;
const int INF = 1e9;
ll a[maxn];
struct node
{
    ll Max;
    ll Min;
}A[maxn << 2];

void pushup(int i)
{
    A[i].Max = max(A[i << 1].Max, A[i << 1 | 1].Max);
    A[i].Min = min(A[i << 1].Min, A[i << 1 | 1].Min);
}

void build(int u, int l, int r)
{
    if (l == r)
    {
        A[u].Max = A[u].Min = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * u, l, mid);
    build(2 * u + 1, mid + 1, r);
    pushup(u);
}

void update(int u, int l, int r, int x, ll k)
{
    if (l == r)
    {
        A[u].Max = k;
        return;
    }
    int mid = (l + r) / 2;
    if (x <= mid)
        update(u << 1, l, mid, x, k);
    else
        update(u << 1 | 1, mid + 1, r, x, k);
    pushup(u);
}

ll query_max(int u, int sl, int sr, int l, int r)
{
    if (l <= sl && sr <= r)
        return A[u].Max;
    ll ans = 0;
    int mid = (sl + sr) / 2;
    if (l <= mid)
        ans = max(ans, query_max(u << 1, sl, mid, l, r));
    if (r > mid)
        ans = max(ans, query_max(u << 1 | 1, mid + 1, sr, l, r));
    return ans;
}

ll query_min(int u, int sl, int sr, int l, int r)
{
    if (l <= sl && sr <= r)
        return A[u].Min;
    ll ans = INF;
    int mid = (sl + sr) / 2;
    if (l <= mid)
        ans = min(ans, query_min(u << 1, sl, mid, l, r));
    if (r > mid)
        ans = min(ans, query_min(u << 1 | 1, mid + 1, sr, l, r));
    return ans;
}

int n, m, l, r;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    build(1, 1, n);
    while (m--)
    {
        scanf("%d%d", &l, &r);
        printf("%d\n", query_max(1, 1, n, l, r) - query_min(1, 1, n, l, r));
    }
    return 0;
}

