#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	
	string st, en;
	cin >> st >> en;
	
	int ind_s = -1;
	int ind_e = -1;
	int ans = 0;
	for (int i = 0; i < st.size(); i++) {
		if (st[i] != en[i]) {
			if (ind_s != -1) {
				ans += i - ind_s;	
				ind_s = -1;
			} else {
				ind_s = i;
			}
		} 
		
		
	}
	cout << ans << endl;
	return 0;
}
