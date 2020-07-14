//#include<iostream>
//#include<cstring>
//#include<cstdio>
//#include<algorithm>
//#include<vector>
//#include<string>
//typedef long long ll;
//using namespace std;
//const int MAXN = 1e6 + 5;
//int t, n, m, k, a[5005][5001][15];
//ll lcm(int a, int b) {
//    return a / __gcd(a, b) * b;
//}
////int n, m, k;
//int main() {
//	ll ans = 0;
//	cin >> n >> m >> k;
//	ll tem1 = 0, tem = 0, tem2 = 0, tem3 = 0, tem4 = 0;
//	for (int i = 1; i <= n - k + 1; i++) {
//		for (int j = 1; j <= m - k + 1; j++) {
//			tem = max(lcm(i + k - 1, j + k - 1), lcm(i + k - 2, j + k - 2));
//			if (k > 1) {
//				tem1 = max(lcm(i + k - 2, j + k - 1), lcm(i + k - 1, j + k - 2));
//			}
//			if (k > 2) {
//				tem2 = max(lcm(i + k - 3, j + k - 1), lcm(i + k - 1, j + k - 3));
//				tem3 = max(lcm(i + k - 3, j + k - 2), lcm(i + k - 2, j + k - 3));
//			}
//			if (k > 3) {
//				tem4 = max(lcm(i + k - 4, j + k - 1), lcm(i + k - 1, j + k - 4));
//			}
////			cout << max(max(tem, tem1), tem2) << endl;
//			ans += max(max(tem, max(tem1, tem4)), max(tem2, max(tem3, 1ll * lcm(i + k - 3, j + k - 3))));
////			cout << max(lcm(i + k - 1, j + k - 1), max(lcm(i + k - 2, j + k - 1), max(lcm(i + k - 1, j + k - 2), lcm(i + k - 2, j + k - 2)))) << endl;
////			ans += max(lcm(i + k - 1, j + k - 1), max(lcm(i + k - 2, j + k - 1), max(lcm(i + k - 1, j + k - 2), lcm(i + k - 2, j + k - 2))));
//
//		}
//	}
//	cout << ans << endl;
//    return 0;
//}
#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<set>
#include<queue>
#include<algorithm>
#define ls (k << 1)
#define rs (ls | 1)
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 200005;
int dis[N], ans[N][2], num, n;
struct node{
    int to, nxt;
}e[N << 1];
int head[N], tot = 1;
void add(int u, int v)
{
    e[tot].to = v, e[tot].nxt = head[u], head[u] = tot++;
}
void dfs(int x, int fa)
{
    queue<int> q;
    for (int i = head[x]; i; i = e[i].nxt)
    {
        int v = e[i].to;
        if (v == fa)
            continue;
        dfs(v, x);
        q.push(v);
    }
    if (q.size() & 1)
    {
        dis[x] = dis[q.front()];
        q.pop();
    }
    while (!q.empty())
    {
        int x1 = q.front();
        q.pop();
        int x2 = q.front();
        q.pop();
        ans[num][0] = dis[x1], ans[num][1] = dis[x2];
        num++;
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
    }
    for (int i = 1; i <= n; i++) dis[i] = i;
    dfs(1, -1);
    if (dis[1] != 1)
    {
        ans[num][0] = 1, ans[num][1] = dis[1];
        num++;
    }
    printf("%d\n", num);
    for (int i = 0; i < num; i++)
    {
        printf("%d %d\n", ans[i][0], ans[i][1]);
    }
}
