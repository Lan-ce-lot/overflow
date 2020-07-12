// luogu-judger-enable-o2
#define _CRT_SBCURE_NO_DEPRECATE
#include<bits/stdc++.h>

using namespace std;

const int maxx = 1e5 + 6;
const int INF = 0x7fffffff;
int n, m, p;
int a[maxx];

struct node
{
    long long sum;
    long long lazyadd, lazymul;
} A[maxx << 2];

void build(int u, int l, int r) //建树
{
    A[u].lazymul = 1;
    A[u].lazyadd = 0;
    if(l == r)
        A[u].sum = a[l];
    else
    {
        int mid = (l + r) / 2;
        build(2 * u, l, mid);
        build(2 * u + 1, mid + 1, r);
        A[u].sum = A[2 * u].sum + A[2 * u + 1].sum;
    }
    A[u].sum %= p;
    return ;
}

void pushdown(int u, int l, int r) //把u节点的lazy标签向下分发
{
    int mid = (l + r) / 2;
    //儿子的值=此刻儿子的值*爸爸的乘法lazytag+儿子的区间长度*爸爸的加法lazytag
    A[u * 2].sum = (A[u * 2].sum * A[u].lazymul + A[u].lazyadd * (mid - l + 1)) % p;
    A[u * 2 + 1].sum = (A[u * 2 + 1].sum * A[u].lazymul + A[u].lazyadd * (r - mid)) % p; //r-(m+1)+1=r-m
    //维护的lazytag
    A[u * 2].lazymul = (A[u * 2].lazymul * A[u].lazymul) % p;
    A[u * 2 + 1].lazymul = (A[u * 2 + 1].lazymul * A[u].lazymul) % p;
    A[u * 2].lazyadd = (A[u * 2].lazyadd * A[u].lazymul + A[u].lazyadd) % p;
    A[u * 2 + 1].lazyadd = (A[u * 2 + 1].lazyadd * A[u].lazymul + A[u].lazyadd) % p;
    //把父节点的lazytag初始化
    A[u].lazymul = 1;
    A[u].lazyadd = 0;
    return ;
}



void mul(int u, int sl, int sr, int l, int r, long long k) //对节点u进行乘法更新，点u的左右范围是sl-sr，所需要更新的范围是l-r，乘k
{
    if(l > sr || r < sl)
        return ;
    if(l <= sl && r >= sr)
    {
        A[u].sum *= k;
        A[u].lazymul *= k;
        A[u].lazyadd *= k;
        A[u].sum %= p;
        A[u].lazymul %= p;
        A[u].lazyadd %= p;;
        return ;
    }
    pushdown(u, sl, sr);
    int mid = (sl + sr) / 2;
    mul(2 * u, sl, mid, l, r, k);
    mul(2 * u + 1, mid + 1, sr, l, r, k);
    A[u].sum = (A[2 * u].sum + A[2 * u + 1].sum) % p;
    return ;
}

void add(int u, int sl, int sr, int l, int r, long long k) //对节点u进行加法更新，点u的左右范围是sl-sr，所需要更新的范围是l-r，+k
{
    if(l > sr || r < sl)
        return ;
    if(l <= sl && r >= sr)
    {
        A[u].sum += k * (sr - sl + 1);
        A[u].lazyadd += k;
        A[u].sum %= p;
        A[u].lazyadd %= p;
        return ;
    }
    pushdown(u, sl, sr);
    int mid = (sl + sr) / 2;
    add(2 * u, sl, mid, l, r, k);
    add(2 * u + 1, mid + 1, sr, l, r, k);
    A[u].sum = (A[2 * u].sum + A[2 * u + 1].sum) % p;
    return ;
}

long long query(int u, int sl, int sr, int l, int r)
{
    if(l > sr || r < sl)
        return 0;
    if(l <= sl && r >= sr)
        return A[u].sum;
    pushdown(u, sl, sr);
    int mid = (sl + sr) / 2;
    return (query(2 * u, sl, mid, l, r) + query(2 * u + 1, mid + 1, sr, l, r)) % p;
}


int main ()
{
    std::ios::sync_with_stdio(false);
    cin >> n >> m >> p;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    build(1, 1, n);
    while(m--)
    {
        int x, y, z;
        long long k;
        cin >> z;
        if(z == 1)
        {
            cin >> x >> y >> k;
            mul(1, 1, n, x, y, k);
        }
        else if(z == 2)
        {
            cin >> x >> y >> k;
            add(1, 1, n, x, y, k);
        }
        else
        {
            cin >> x >> y;
            cout << query(1, 1, n, x, y) << endl;
        }
    }
    return 0;
}
//5 5 100000000
//1 5 4 2 3
//2 2 4 2
//3 3 3
//2 1 5 -1
//2 3 5 7
//3 4 4
