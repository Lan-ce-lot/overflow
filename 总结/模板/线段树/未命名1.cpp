#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
const double eps = 1e-6;
const double pi = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
#define ll long long
#define CL(a,b) memset(a,b,sizeof(a))
#define MAXN 800010
 
struct node
{
    int a,b,r;
}t[MAXN];
int n,m,ans;
 
void build(int x, int y, int num)
{
    t[num].a = x;
    t[num].b = y;
    t[num].r = 0;
    if(x == y) return ;
    int mid = (x+y)/2;
    build(x, mid, num*2);
    build(mid+1, y, num*2+1);
}
 
void update(int x, int y, int num)
{
    if (t[num].a == t[num].b && t[num].b == x)
    {
        t[num].r = y;
        return ;
    }
    int mid = (t[num].a+t[num].b)/2;
    if(x > mid) update(x, y, num*2+1);
    else update(x, y, num*2);
    t[num].r = max(t[num*2].r, t[num*2+1].r);
}
 
void query(int x, int y, int num)
{
     if(t[num].a == x && t[num].b == y)
     {
         ans = max(ans, t[num].r);
         return ;
     }
     int mid = (t[num].a+t[num].b)/2;
     if(x >= mid+1) query(x, y, num*2+1);
     else if(y <= mid) query(x, y, num*2);
     else
     {
         query(x, mid, num*2);
         query(mid+1, y, num*2+1);
     }
}
 
int main()
{
	
    char ch;
    int x,y,k;
    while(~scanf("%d%d",&n,&m))
    {
        build(1, n, 1);
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&k);
            update(i, k, 1);
        }
 
        while(m--)
        {
            getchar();
            scanf("%c%d%d",&ch,&x,&y);
            if(ch == 'U')
            {
                update(x, y, 1);
            }
            else if(ch == 'Q')
            {
                ans = -99999;
                query(x, y, 1);
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}
