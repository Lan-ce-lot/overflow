#include<bits/stdc++.h>
#define ll long long
#define N 100010
using namespace std;
int a[N], b[N], c[N], d[N];
struct PP { int val, id;};
bool operator < (PP x, PP y)
{
	return x.val == y.val ? x.id < y.id : x.val < y.val;
}

int main()
{
	int tt;
	scanf("%d", &tt);
	for (int ttt = 1; ttt <= tt; ttt++)
	{
		printf("Case %d: ", ttt);
		int n,m;
		scanf("%d%d", &n, &m);
		for (int i=1; i<=n; i++)
			scanf("%d", &a[i]);
		for (int j=1; j<=m; j++)
			scanf("%d", &b[j]);
		for (int i=1; i<=m; i++)
			scanf("%d", &d[i]);
		//judge
		for (int i=1; i<=m; i++)
			c[i] = b[i];
		sort(a+1, a+n+1);
		sort(c+1, c+m+1);
		int cur = 1;
		for (int i=1; i<=n; i++)
		{
			if (c[cur] <= a[i])
			{
				cur++;
				if (cur>m)
					break;
			}
		}
		bool canFace = (cur>m);
		ll sum1 = 0, sum2 = 0;
		if (canFace)
		{
			set<PP> st;
			for (int i=1; i<=n; i++)
				st.insert((PP){a[i],i});
			for (int i=1; i<=m; i++)
				if (d[i])
				{
					PP tar = (PP){b[i], 0};
					st.erase(st.lower_bound(tar));
				}
			for (auto x : st)
				sum1 += x.val;
			for (int i=1; i<=m; i++)
				if (!d[i])
					sum1 -= b[i];
		}
		/*
		priority_queue<int, vector<int>, greater<int> > q;
		for (int i=1; i<=m; i++)
			if (!d[i])
				q.push(b[i]);
		for (int i=1; i<=n; i++)
		{
			if (q.empty())
				break;
			int x=q.top();
			if (a[i] >= x)
			{
				sum2 += a[i]-x;
				q.pop();
				q.push(a[i]);
			}
		}*/
		int cnt = 0;
		for (int i=1; i<=m; i++)
			if (!d[i])
				c[++cnt] = b[i];
		sort(a+1, a+n+1);
		sort(c+1, c+cnt+1);
		int nn = min(n,cnt);
		for (int i=1; i<=nn; i++)
			if (a[n-i+1] >= c[i])
				sum2 += a[n-i+1]-c[i];
			else break;
		printf("%lld\n", max(sum1, sum2));
	}
	return 0;
}
		
		
		

