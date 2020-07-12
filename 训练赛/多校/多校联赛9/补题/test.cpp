#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

struct line
{
    int x, y;
    char oper;
    bool operator <(const line &A) const
    {
        return x < A.x;
    }
} Line[N];

int x[N], y[N];
int sum[N << 2], lazy[N << 2];

void pushDown(int rt)
{
    if(!lazy[rt]) return ;
    sum[rt << 1] += lazy[rt];
    sum[rt << 1 | 1] += lazy[rt];
    lazy[rt << 1] += lazy[rt];
    lazy[rt << 1 | 1] += lazy[rt];
    lazy[rt] = 0;
}

void update(int L, int R, int l, int r, int rt)
{
    if(L <= l && r <= R)
    {
        lazy[rt] += 1;
        sum[rt] += 1;
        return ;
    }
    int m = (l + r) >> 1;
    pushDown(rt);
    if(L <= m) update(L, R, l, m, rt << 1);
    if(m <  R) update(L, R, m + 1, r, rt << 1 | 1);
}

int query(int L, int l, int r, int rt)
{
    if(l == r)
        return sum[rt];
    int m = (l + r) >> 1, ans = 0;
    pushDown(rt);
    if(L <= m) ans += query(L, l, m, rt << 1);
    else        ans += query(L, m + 1, r, rt << 1 | 1);
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T, n, m, M;
    long long ans = 0;
    cin >> T;
    while(T--)
    {
        ans = 0;
        cin >> n >> m >> M;
        memset(sum, 0, sizeof sum);
        memset(lazy, 0, sizeof lazy);
        for(int i = 1; i <= M; ++i)
        {
            cin >> Line[i].x >> Line[i].y >> Line[i].oper;
            x[i] = Line[i].x, y[i] = Line[i].y;
        }
        sort(y + 1, y + M + 1);
        int posy = unique(y + 1, y + M + 1) - y - 1;
        sort(Line + 1, Line + M + 1);
        for(int i = 1; i <= M; ++i)
        {
            int t = lower_bound(y + 1, y + posy + 1, Line[i].y) - y;
            if(Line[i].oper == 'U')
            {
                update(t, posy, 1, posy, 1);
            }
            else if(Line[i].oper == 'D')
            {
                update(1, t, 1, posy, 1);
            }
            else if(Line[i].oper == 'L')
            {
                ans += query(t, 1, posy, 1);
            }
        }
        memset(sum, 0, sizeof sum);
        memset(lazy, 0, sizeof lazy);
        for(int i = M; i >= 1; --i)
        {
            int t = lower_bound(y + 1, y + posy + 1, Line[i].y) - y;
            if(Line[i].oper == 'U')
            {
                update(t, posy, 1, posy, 1);
            }
            else if(Line[i].oper == 'D')
            {
                update(1, t, 1, posy, 1);
            }
            else if(Line[i].oper == 'R')
            {
                ans += query(t, 1, posy, 1);
            }
        }
        cout << ans + 1 << endl;
    }
    return 0;
}
