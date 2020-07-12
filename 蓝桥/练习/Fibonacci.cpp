#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
using namespace std;
const int mod = 10007;
const int maxn = 1e6 + 5;
const double pi = acos(-1);

typedef long long ll;


int p[maxn];

set<int> M;
void Init()
{
	for (int i = 0; i < maxn; i++)
	{
		p[i] = i;
	}
	
}

int Find(int x)
{
	return x == p[x] ? x : (p[x] = Find(p[x]));
}

void Union(int x, int y)
{
	x = Find(x);
	y = Find(y);
	if (x == y)
		return;
	p[x] = y;
}
int n, m, q;

int main()
{
	Init();
	cin >> n;
	cin >> q;
	for (int i = 1; i <= q; i++)
	{
		int a, b;
		cin >> a >> b;
		Union(a, b);
	}
	
	int ans = 0;
	
	for (int i = 1; i <= n; i++)
	{
		if (p[i] == i)
		ans++;
	}
	cout << n - ans << endl;
} 
