#include<bits/stdc++.h>
using namespace std;
#define MAX 1000006
int num[MAX];
struct node
{
	int left,right; 
}n[4*MAX];
void build(int p, int l, int r)
{
    if(l == r)
    {
        n[p].left = num[l];
        n[p].right = num[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    n[p].left = max(n[p << 1].left, n[(p << 1) + 1].left);
    n[p].right = min(n[p << 1].right, n[p << 1 | 1].right);
}

void change(int p, int l, int r, int x, int num)
{
    if(l == r)
    {
        n[p].left = num;
        n[p].right = num;
        return;
    }
    int mid = (l + r) >> 1;
    if(x <= mid) change(p << 1, l, mid, x, num);
    else change(p << 1 | 1, mid + 1, r, x, num);
    n[p].left = max(n[p << 1].left, n[p << 1 | 1].left);
    n[p].right = min(n[p << 1].right, n[p << 1 | 1].right);
}

int Find(int p, int l, int r, int x, int y)//find max
{
    if(x <= l && y >= r)
    {
        return n[p].left;
    }
    int mid = (l + r) >> 1;
    if(y <= mid) return Find(p << 1, l, mid, x, y);
    if(x > mid) return Find(p << 1 | 1, mid + 1, r, x, y);
    return (max(Find(p << 1, l, mid, x, mid), Find(p << 1 | 1, mid + 1, r, mid + 1, y)));
}

int Find2(int p, int l, int r, int x, int y)//find min
{
    if(x <= l && y >= r)
    {
        return n[p].right;
    }
    int mid = (l + r) >> 1;
    if(y <= mid) return Find2(p << 1, l, mid, x, y);
    if(x > mid) return Find2(p << 1 | 1, mid + 1, r, x, y);
    return (min(Find2(p << 1, l, mid, x, mid), Find2(p << 1 | 1, mid + 1, r, mid + 1, y)));
}

int main()
{
    int N, M, a, b;
    int s;
    while(scanf("%d%d", &N, &M) != EOF)
    {
        for(int i = 1; i <= N; i++) scanf("%d", &num[i]);
        build(1, 1, N);
        while(M--)
        {
            scanf("%d%d%d", &s, &a, &b);
            if(s == 0)
            {
                printf("%d\n", (Find(1, 1, N, a, b) + Find2(1, 1, N, a, b)) / 2);
            }
            else change(1, 1, N, a, b);
        }
    }
    return 0;
}
