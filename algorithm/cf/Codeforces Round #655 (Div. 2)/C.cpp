#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int n, m, t, ans = 0;

int a[200000];

int main() {
	cin >> t;
	while (t--) {
		ans = 0;
		int flag = 0, con = 0, index_s = 0, index;
		cin >> n;
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		for (int i = 0; i < n; i++) {
			if (a[i] != i + 1) {
				index_s = i;
				flag = 1;
				break;
			}
		}
		
		for (int i = n - 1; i >= 0; i--) {
			if (a[i] != i + 1) {
				index = i;
				break;
			}
		}
		for (int i = index_s; i <= index; i++) {
			if (a[i] == i + 1) {
				con++;
			}
		}
		if (flag == 0) {
			cout << 0 << endl;
		} else if (con == 0) {
			cout << 1 << endl;
//			cout << index << ' ' << con << endl;
		} else {
			cout << 2 << endl;
		}
//		cout << ans << endl;
	}
	
	return 0;
} 
