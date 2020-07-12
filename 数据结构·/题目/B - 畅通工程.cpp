#include <cstdio>
using namespace std;
 
const int maxn = 3e4 + 5;
int pre[maxn];
 
int find(int x)
{
    return pre[x] == x ? x : find(pre[x]);
}
 
void join(int x, int y)
{
	x = find(x);
	y = find(y);
	if(x!=y)pre[y] = x;	
}
 
int main()
{
    int n, m, ans, i, j, k, fir, get;
    while(scanf("%d%d", &n, &m),n)
    {
        ans = 0;
        for(i = 1; i <= n; i++)
        {
            pre[i] = i;
        }
        for(i = 1; i <= m; i++)
        {
           scanf("%d%d", &k, &fir);
           join(k, fir);
        }
        for(i = 1; i <= n; i++)
        {
            if(find(i) == i)
                ans++;
        }
        printf("%d\n", ans-1);
    }
    return 0;
}
