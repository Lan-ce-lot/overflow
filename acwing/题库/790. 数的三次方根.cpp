#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
double n;
const double ESP = 1e-9;
int main() {
	// 0-n
	cin >> n;
	int flag = 0;
	if (n < 0.0) {
		flag = 1;
	}
	n = fabs(n);
//	cout << n <<endl;
	double l = 0, r = n;
	while (r - l > ESP) {
		double mid = (l + r) / 2.0;
		if (mid * mid * mid < n) {
			l = mid;
		} else {
			r = mid;
		}
	}
	printf("%.6f\n", l * (flag ? -1 : 1) );
	
	return 0;
}
