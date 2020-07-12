#include<bits/stdc++.h>
#define ll long long
#define N 2010
using namespace std;
struct PP {int der, id, tar;} p[N];
bool operator < (PP a, PP b) { return a.der < b.der;}
const int mxA = 1000001;
int xx[N], yy[N], col[N], c[N];
int a[N][N];
int n,m;
int getAns()
{
	int sum=0; 
	for (int i=1; i<=n; i++)
		sum+=a[i][col[i]];
	return sum;
}

int solve()
{
	memset(c,0,sizeof(c));
	for (int i=1; i<=n; i++)
	{
		int mx=0;
		for (int j=1; j<=m; j++)
			if (a[i][j] > mx)
				mx = a[i][j], col[i] = j;
		c[col[i]]++;
	}
	int tar=n/2;
	int wa=-1;
	for (int i=1; i<=m; i++)
		if (c[i] > tar)
		{
			wa = i;
			break;
		}
	if (wa == -1)
		return getAns();
		
	int cnt = 0;
	for (int i=1; i<=n; i++)
		if (col[i] == wa)
		{
			int mx = -1, id = -1;
			for (int j=1; j<=m; j++)
				if (j!=c[i] && a[i][j]>mx)
					mx = a[i][j], id = j;
			p[++cnt] = (PP){ a[i][col[i]]-mx, i, id };
		}
	sort(p+1, p+cnt+1);
	for (int i=1; c[wa]>tar; i++)
	{
		c[wa]--;
		c[p[i].tar]++;
		col[p[i].id] = p[i].tar;
	}
	int wa2 = -1;
	for (int i=1; i<=m; i++)
		if (c[i] > tar)
		{
			wa2 = i;
			break;
		}
	if (wa2 == -1)
		return getAns();
	
	int c1 = 0, c2 = 0;
	for (int i=1; i<=n; i++)
		if (col[i] == wa2)
			xx[++c1] = i;
		else
			yy[++c2] = i;
	int base = getAns();
	int der = -2147483648;
	for (int i=1; i<=c1; i++)
		for (int j=1; j<=m; j++)
			if (j!=wa && j!=wa2 && a[xx[i]][j]-a[xx[i]][wa2] > der)
				der = a[xx[i]][j]-a[xx[i]][wa2];
	int ans1 = base+der;
	int der1 = -2147483648, der2 = -2147483648;
	for (int i=1; i<=c1; i++)
		if (a[xx[i]][wa] - a[xx[i]][wa2] > der1)
			der1 = a[xx[i]][wa] - a[xx[i]][wa2];
	for (int i=1; i<=c2; i++)
		for (int j=1; j<=m; j++)
			if (j!=wa && j!=wa2 && a[yy[i]][j]-a[yy[i]][wa] > der2)
				der2 = a[yy[i]][j]-a[yy[i]][wa];
	int ans2 = base+der1+der2;
	return max(ans1, ans2);
}	

int main()
{
	int tt;
	scanf("%d", &tt);
	for (int ttt=1; ttt<=tt; ttt++)
	{
		scanf("%d%d", &n, &m);
		for (int i=1; i<=n; i++)
			for (int j=1; j<=m; j++)
				scanf("%d", &a[i][j]);
		if ((n&1) && m==2)
		{
			printf("-1\n");
			continue;
		}
		int mx = solve();
		printf("mx %d\n", mx);
		for (int i=1; i<=n; i++)
			for (int j=1; j<=m; j++)
				a[i][j] = mxA-a[i][j];
		int mn = solve();
		mn = n*mxA-mn;
		printf("mn %d\n", mn);
		printf("%d\n", mx-mn);
	}
	return 0;
}

