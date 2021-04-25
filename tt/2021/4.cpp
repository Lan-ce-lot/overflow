#include<bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 5;

int n, m, t, a[maxn], k;

int main() {
	string str;
	cin >> str;
	
	if (str.size() == 6) {
		cout << str.substr(0, 4) << '-' << str.substr(4, 2) << endl;
	} else  {
		int y = stoi(str.substr(0, 2));
		if (y < 22) {
			cout << "20" << str.substr(0,2) << '-' << str.substr(2, 2) << endl;
		} else {
			cout << "19" << str.substr(0,2) << '-' << str.substr(2, 2) << endl;
		}
	}
	return 0;
}
