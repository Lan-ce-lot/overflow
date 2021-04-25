#include<bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 5;

int n, m, t, a[maxn], k;
string s[1005];
const int INF = 0x3f3f3f3f;
int main() {
	cin >> n >> m;
	getchar();
	for (int i = 0; i < n; i++) {
		getline(cin, s[i]);
	}
	int index = 0, ff = 0, i = 0;
	for (i = 0; i < n; i++) {
		if (index >= m) {
			break;
		}
		if (s[i].find("qiandao") != string::npos || s[i].find("easy") != string::npos) {
			
		} else {
			
//			cout << s[i] << endl;
			index++;
		}
	}
//	cout << index << endl;
//	cout << i << endl;
	if (i >= n) {
		puts("Wo AK le");
	} else {
		cout << s[i] << endl;
	}
	return 0;
}
