#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
int t, n;
ll a[maxn];

int main () {
	
	a[1] = 1, a[2] = 2, a[3] = 3;
	for (int i = 4; i < 55; i++) {
		a[i] = a[i - 1] + a[i - 3];
	}
	while (~scanf("%d", &t)) {
		// 4
		// 1 1
		// 2 2
		// 3 3
		// 4 4
		// 5 6
		// 6 9
		// 7 13
		if (t == 0) {
			return 0;
		}
		cout << a[t] << endl;
		
	}
	return 0;
}
