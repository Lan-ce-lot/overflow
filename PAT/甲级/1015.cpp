#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
int a, b;

string change(int n, int rad) {
	string s;
	while (n) {
		s += n % rad + '0';
		n /= rad;
		
	}
	return s;
}

int update(string s, int rad) {
	int sum = 0;
	int ex = 1;
	for (int i = s.size() - 1; i >= 0; i--) {
		sum += (s[i] - '0') * ex;
		ex *= rad;
	}
	
	return sum;
}

bool isPrime(int a) {
	if (a < 2) return 0;
	for (int i = 2; i * i <= a; i++) {
		if (a % i == 0) return 0;
	}
	return 1;
}


int main() {
	
	while (cin >> a) {
		if (a < 0) return 0;
//		if (a == 0 || a == 1) {
//			puts("No");continue;
//		}
		cin >> b;
		string str;
//		cout << change(a, b) << endl;
		str = change(a, b);
//		cout << update(str, b);
//		reverse(str.begin(), str.end());
		puts(isPrime(a) && isPrime(update(str, b))? "Yes" : "No" );
		
	}
	
	return 0;
} 
