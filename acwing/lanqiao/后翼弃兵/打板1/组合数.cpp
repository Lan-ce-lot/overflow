#include <iostream>

using namespace std;
const int mod = 1e9 + 7;
int n, m;
int C[2015][2015];
int main() {
	
	
	cin >> n;
	for (int i = 0; i <= 2005; i++) C[i][0] = 1;
	for (int i = 1; i <= 2005; i++) {
		for (int j = 1; j <= i; j++) {
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
		}
	}
	while (n--) {
		int a, b;
		cin >> a >> b;
		cout << C[a][b] << endl;
	}
	return 0;
}
