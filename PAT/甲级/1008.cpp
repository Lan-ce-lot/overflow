#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n, a[20005];
int main() {
	while (cin >> n) {
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int temp = 0;
		int ans = 0;
		for (int i = 0; i< n; i++) {
			if (a[i] > temp) {
				ans += (a[i] - temp) * 6 + 5;
				
			} else {
				ans += (temp - a[i]) * 4 + 5;
			}temp = a[i];
		}
		cout << ans << endl;
	}
	
} 
