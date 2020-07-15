#include <iostream>
#include <cstdio>
#include <cstring>
// 2147483647 
// 9223372036854775807 19 

 
using namespace std;
const int mod = 1000000007;

int a[100005];


int main() {
	int n, ans = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {	
		int maxn = -1e8, imax = 0;
		int minn = 1e8, imin = 0;
		for (int j = i; j < n; j++) {
			if (a[j] > maxn) maxn = a[j];
			if (a[j] < minn) minn = a[j];
			if (j - i == maxn - minn) ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
