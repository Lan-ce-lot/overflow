#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;
int n;
int num[100005];
int dp[100005];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
		
	}
	int len = 0;
	dp[0] = -0x3f3f3f3f;
	for (int i = 0; i < n; i++) {
		int l = 0, r = len;
		int mid = l + r + 1 >>1;
		while (l < r) { //比num[i]小的最大的数 
			mid = l + r + 1 >>1;
			if (dp[mid] >= num[i]) {
				r = mid - 1;
				
			} else {
				l = mid;
			}
		}
		len = max(len, r + 1);
		dp[r + 1] = num[i];
	}
	cout << len << endl;
	return 0;
}
