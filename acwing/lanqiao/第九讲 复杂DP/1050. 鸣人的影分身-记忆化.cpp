#include <bits/stdc++.h>
using namespace std;
int t, n, m, f[1005][1005];
int dp(int n, int m) {
	if (~f[n][m]) return f[n][m];
	if (!n) return f[n][m] = 1;
	if (!m) return f[n][m] = 0;
	if (m > n) return f[n][m] = dp(n, n);
	return f[n][m] = dp(n, m - 1) + dp(n - m, m);//������С�ڵ���ƻ���� -> �������ۣ� ������Ϊ�գ�û������Ϊ��
//������Ϊ�յ�ʱ��������һ������Ϊ�գ�f(x,y-1);û������Ϊ�ռ�����ÿ�����Ӷ���һ��,f(x-y,y)   
}
void solve()
{
	cin >> t;
	while (t--) {
		memset(f, -1, sizeof f);
		cin >> n >> m;
		cout << dp(n, m) << endl;
	}
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

