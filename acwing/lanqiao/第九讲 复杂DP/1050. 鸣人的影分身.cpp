#include <bits/stdc++.h>
using namespace std;
int t, n, m, f[1005][1005];
int dp(int n, int m) {
	if (!n) return 1;
	if (!m) return 0;
	if (m > n) return dp(n, n);
	return dp(n, m - 1) + dp(n - m, m);//������С�ڵ���ƻ���� -> �������ۣ� ������Ϊ�գ�û������Ϊ��
//������Ϊ�յ�ʱ��������һ������Ϊ�գ�f(x,y-1);û������Ϊ�ռ�����ÿ�����Ӷ���һ��,f(x-y,y)   
}
void solve()
{
	cin >> t;
	while (t--) {
		cin >> n >> m;
		cout << dp(n, m) << endl;
		
//		f[0][0] = 1;
//		for (int i = 1; i <= n; i++) {
//			for (int j = 0; j <= m; j++) {
//				
//			}
//		}
	} 
	
	
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

