#include<iostream>
#include<cmath> 
#include<algorithm>
using namespace std;
typedef long long ll;
const int N = 4e5 + 5;

int T, n, p, a[N], b[N];
ll x[N];
int check(int x)
{
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int mn = min(a[i], b[i]), mx = max(a[i], b[i]);
		if (x < mn)	return 0;
		if (mx > x)
			ans += x * p / 100.0 <= mn;
		else 
			ans += x * p / 100.0 <= mx;
	}
	return ans;
}
int main()
{
	scanf("%d", &T);
	for (int t = 1; t <= T; t++)
	{
		int mn = 0, ans = 1;
		scanf("%d%d", &n, &p);
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d", &a[i], &b[i]);
			x[i * 2] = a[i];
			x [i * 2 + 1] = b[i];
			mn = max(mn, min(a[i], b[i]));
		} 
		sort(x, x + n * 2, greater<ll>());
		int len = unique(x, x + n * 2) - x;
		int op = lower_bound(x, x + len, mn, greater<ll>() ) - x;
		int l = 0, r = op;
        ans = max(check(x[l]), check(x[r]));
		while (l < r - 3)
		{
			int lmid = l + (r - l) / 3, rmid = l + (r - l) * 2 / 3;         
			if (check(x[lmid]) >= check(x[rmid]))
				r = rmid;
			else
				l = lmid + 1;
		}
		for (int i = 0; i < 3; i++)
			ans = max(ans, check(x[l + i]));
		printf("Case #%d: %d\n", t, ans);
	} 
}


