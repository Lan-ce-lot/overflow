#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
//sacnf("%lf") printf("%f")
ll read()
{
    ll x = 0,f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
	{
		if (ch == '-')
		f = -1;
		ch = getchar();
	}
    while (ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
    return x * f;
}
int t, n;
int h1, m1, s1;
int h2, m2, s2;
int G[100][100];
int dp[100][100];
void solve()
{
	n = read(); 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			G[i][j] = read();
			if (G[i][j] == -1) {
				G[i][j] = INF;
			}
		} 
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++){
			if (i == 0 && j == 0) {
//				continue;
				dp[i][j] += G[i][j];
			} else if (i == 0 && j != 0) {
				dp[i][j] = G[i][j] + dp[i][j - 1];
			} else if (i != 0 && j == 0) {
				dp[i][j] = G[i][j] + dp[i - 1][j];
			}
			else {
				dp[i][j] += G[i][j] +  min(dp[i][j - 1], dp[i - 1][j]);
			}
			
		}
	}
	if (dp[n - 1][n - 1] > 1000000) {
		puts("Sorry");
	} else {
		printf("%d\n", dp[n - 1][n - 1]);
	}
	
	
//	t = read();
//	while (t--) {
//		n = read();
//		printf("%d\n", n % 2 == 0 ? (n / 2) - 1 : (n / 2));
//	}
//	n = read();
//	int max1 = -0x3f3f3f3f, flag = 0;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			G[i][j] = read();
//			
////			if (max1 >= G[i][j]) {
////				flag = 1;
////			}
////			max1 = G[i][j];
//		}
//	}
//	
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			if (i != 0 && j != 0) {
//				if (G[i][j] <= G[i - 1][j] || G[i][j] <= G[i][j - 1]) {
//					flag = 1;
//					break;
//				}
//			} else if (i == 0 && j == 0) {
//				continue;
//			} else if (i == 0 && j != 0) {
//				if (G[i][j] <= G[i][j - 1]) {
//					flag = 1;
//					break;
//				}
//			} else if (i != 0 && j == 0) {
//				if (G[i][j] <= G[i - 1][j]) {
//					flag = 1;
//					break;
//				}
//			}
//		}
//	}
//	if (flag) {
//		puts("NO");
//	} else {
//		puts("YES");
//	}
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

