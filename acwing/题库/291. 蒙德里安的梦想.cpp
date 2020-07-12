#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<queue> 

using namespace std;

long long dp[12][8005];
bool vis[8005];

int n, m;
int main() {
//	priority_queue<int, vector<int>, greater<int> > Q;
	while (cin >> n >> m, n || m) {
		
		for (int i = 0; i < 1 << n; i++) {
			vis[i] = 1;
			int con = 0;
			for (int j = 0; j < n; j++)  {
				if (i >> j & 1) {// 当前j位是1的话 
					if (con & 1) vis[i] = 0;
					con = 0;
				} else con++;// con 当前连续0的个数 
				
			}
			if (con & 1) vis[i] = 0;
			
		}memset(dp, 0, sizeof dp);
		dp[0][0] = 1;
		for (int i = 1; i <= m; i++) 
			for (int j = 0; j < 1 << n; j++) 
				for (int k = 0; k < 1 << n; k++)
					if ((j & k) == 0 && vis[j | k])
						dp[i][j] += dp[i - 1][k];
		cout << dp[m][0] << endl;
	}
	return 0;
} 
