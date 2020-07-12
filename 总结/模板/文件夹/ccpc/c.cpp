#include<bits/stdc++.h>
#define N 500010
using namespace std;
struct PP { int val, id; };
bool operator < (PP a, PP b) { return a.val < b.val;}
priority_queue<PP> q;
int a[N][2], b[N];
int n;

void dfs(int ta)
{
	if (ta <= n)
	{
		b[ta] = 1;
		return;
	}
	dfs(a[ta][0]); dfs(a[ta][1]);
}
	

int main()
{
	int tt;
	scanf("%d", &tt);
	for (int ttt=1; ttt<=tt; ttt++)
	{
		scanf("%d", &n);
		while (!q.empty())
			q.pop();
		for (int i=1; i<=n; i++)
		{
			int x;
			scanf("%d", &x);
			q.push((PP){x,i});
		}
		int cnt = n;
		int ta = -1, tb = -1;
		while (!q.empty())
		{
			PP x = q.top(); q.pop();
			//printf("%d : val %d topval %d\n", x.id, x.val, q.top().val);
			if (x.val == 1)
			{
				if (ta == -1)
					ta = x.id;
				else
				{
					tb = x.id;
					break;
				}
				continue;
			}
			if (!q.empty() && q.top().val == x.val)
			{
				PP y = q.top(); q.pop();
				cnt++;
				a[cnt][0] = x.id;
				a[cnt][1] = y.id;
				q.push((PP){x.val-1, cnt});
			}
		}
		printf("Case %d: ", ttt);
		if (ta == -1 || tb == -1)
		{
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		for (int i=1; i<=n; i++)
			b[i] = 0;
		dfs(ta); 
		for (int i=1; i<=n; i++)
			printf("%d", b[i]);
		printf("\n");
	}
	return 0;
}

















