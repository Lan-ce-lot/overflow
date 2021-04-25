#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m;
int pil[3][70];
void gao(int a[], int b[], int c[])
{
	long long mid = (1LL << (n - 1));
	if (n == 0)
		return;
	if (m >= mid)
	{
		c[++c[0]] = n--;
		m -= mid;
		gao(b, a, c);
	}
	else
		a[++a[0]] = n--, gao(a, c, b);
}
void Print()
{
	int i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 1; j <= pil[i][0]; j++)
			cout << pil[i][j] << '-';
		if (i != 2)
			cout << "0-";
	}
}
int main()
{
	while (cin >> n >> m, n, m)
	{
		pil[0][0] = pil[1][0] = pil[2][0] = 0;
		gao(pil[0], pil[1], pil[2]);
		Print();
		puts("");
	}
}
