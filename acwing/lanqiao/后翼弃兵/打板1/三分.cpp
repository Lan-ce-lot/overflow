#include <iostream>


using namespace std;


const int N = 1e5 + 2;
int n;
double l, r;
double a[N];

double f(double x) {
	double res = 0.;
	for (int i = 1; i <= n; i++) {
		res += a[i];
		res *= x;
	}
	res += a[n + 1];
	return res;
}

int main() {
	
	cin >> n;
	cin >> l >> r;
	for (int i = 1; i <= n + 1; i++) cin >> a[i];

	while (r - 1e-7 > l) {
		double ml = (l + r) / 2, mr = (ml + r) / 2;
		if (f(ml) < f(mr))
			l = ml;
		else
			r = mr;
	}
	printf("%.5lf", l);
	return 0;
}
