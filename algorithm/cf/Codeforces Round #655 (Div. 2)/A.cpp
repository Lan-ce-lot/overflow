#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;

int n, m, t;

int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			if (i != 0) {
				cout << ' ';
			}
			cout << 1;
		}
		puts("");
	} 
	
	return 0;
} 
