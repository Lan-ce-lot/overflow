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
bool cmp(V A, V B) {
	if (A.size() != B.size()) {
		return A.size() < B.size();
	} else {
		for (int i = 0; i < A.size(); i++) {
			if (A[i] != B[i]) {
				return A[i] < B[i];
			}
		}
	}
	return 0;
}
V sub(V A, V B) {
	int f = 0;
	V C;
	if (cmp(A, B)) {
		swap(A, B);
		f = 1;
	}
	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());
	for (int i = 0, t = 0; i < A.size(); i++) {
		t = A[i] - t;
		if (i < B.size())
			t -= B[i];	
		C.push_back((t + 10) % 10);
		if (t < 0)
			t = 1;
		else
			t = 0;
	}
	
	while (C.size() > 1 && C.back() == 0) C.pop_back();
	reverse(C.begin(), C.end());
	if (f) cout << '-';
	for (int i = 0; i < C.size(); i++) cout << C[i];
	puts("");	
	return C;
}

V mul(V A, V B) {
	V C(4500, 0);
	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());
	for (int i = 0; i < A.size(); i++) {
		for (int j = 0; j < B.size(); j++) {
			C[j + i] += A[i] * B[j];
		}
	}
	for (int i = 0; i < A.size() + B.size() - 1; i++) {
		if (C[i] > 9) {
			C[i + 1] += C[i] / 10;
			C[i] %= 10;
		}
	}
	while (C.back() == 0 && C.size() > 1) C.pop_back();
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
	print(mul(A, B));
	return 0;
}
