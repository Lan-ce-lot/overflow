#include <iostream>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
int A[1005];
double A_[1005];
int B[1005];
double B_[1005];
int n1, n2;
int main() {
	cin >> n1;
	map<int, double> M; // 指数 系数
	map<int, double>::iterator it;
	for (int i = 0; i < n1; i++) {
		cin >> A[i] >> A_[i];
		
	}
//	cout << 1111;
	cin >> n2;
	for (int i = 0; i < n2; i++) {
		cin >> B[i] >> B_[i];
	}
	
	
	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < n2; j++) {
			M[A[i] + B[j]] += A_[i] * B_[j];
		}
	}
	
	for (it = M.begin(); it != M.end(); it++) {
		if (it->second == 0.0 || it->second == -0.0) {
			M.erase(it);
		}
	}
//	reverse(M.begin(), M.end());
	cout << M.size();
	for (map<int, double>::reverse_iterator r = M.rbegin(); r != M.rend(); r++) {
//		cout << ' ' << r->first << ' ' << r->second;
		printf(" %d %.1f", r->first, r->second);
	}
	puts("");
	return 0;
}

