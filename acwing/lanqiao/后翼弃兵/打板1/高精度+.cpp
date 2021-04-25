#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> V;

V add(V A, V B) {
	int f = 0;
	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());
	V C;
	if (A.size() < B.size()) swap(A, B);
	for (int i = 0; i < A.size(); i++) {
		if (i < B.size()) {
			C.push_back((A[i] + B[i] + f) % 10);
			f = (A[i] + B[i] + f) / 10;
		} else {
			C.push_back((A[i] + f) % 10);
			f = (A[i] + f) / 10;
		}
	}
	if (f) {
		C.push_back(f);
	}
	reverse(C.begin(), C.end());
	return C;
}
string s1, s2;
V turn (string s) {
	V A;
	for (int i = 0; i < s.size(); i++) A.push_back(s[i] - '0');
	return A;
}
void print(V A) {
	for (int i = 0; i < A.size(); i++) cout << A[i];
	puts("");
}
int main() {
	cin >> s1 >> s2;
	V A = turn(s1), B = turn(s2);
	print(add(A, B));
	return 0;
}
