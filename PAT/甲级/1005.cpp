#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <unordered_map>
typedef long long ll;
using namespace std;
 
 int main() {
 	string n;
 	
 	map<int, string> M;
	M[0] = "zero";
	M[1] = "one";
	M[2] = "two";
	M[3] = "three";
	M[4] = "four";
	M[5] = "five";
	M[6] = "six";
	M[7] = "seven";
	M[8] = "eight";
	M[9] = "nine";
 	while (cin >> n) {
 		ll sum = 0;
 		for (int i = 0; i < n.size(); i++) {
 			sum += (n[i] - '0');
		 }
		stack<int> S;
		if (sum == 0){
			cout << M[0] << endl;
			continue;
		}
 		while (sum) {
 			S.push(sum % 10);
 			sum /= 10;
		 }
		int con = 0;
		while (!S.empty()) {
			if (con != 0) cout << ' ';
			cout << M[S.top()];
			S.pop();
			con++;
		}
 		puts("");
 		
	 }
 }

