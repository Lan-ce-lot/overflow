#include <bits/stdc++.h>

using namespace std;
int a[4];
int main() {
	cin >> a[0] >> a[1] >> a[2];
	sort(a, a + 3);
	cout << a[0] << "->" << a[1] << "->" << a[2] << endl;
	return 0;
} 
