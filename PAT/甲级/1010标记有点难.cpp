#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>

//https://blog.csdn.net/CV_Jason/article/details/80993283
typedef long long ll;
using namespace std;
map<int, char> M1;
map<char, int> M2;
ll dec(string str, int rad) {
	ll ans = 0, tem = 1;
	for (int i = str.size() - 1; i >= 0; i--) {
		
		ans += M2[str[i]] * tem;
		tem *= rad;
	}
	return ans;
}

int main() {
	string N1, N2, ans;
	int rad, num_N1, num_N2;

	for (int i = 0; i <= 9; i++) {
		M1[i] = i + '0';
		M2['0' + i] = i;
	}
	for (int i = 10; i <= 35; i++) {
		M1[i] = i + 'a';
		M2[i + 'a'] = i;
	}
	
	int tag = 1;
	
	while (cin >> N1 >> N2 >> tag >> rad) {
//		cout << N1 << N2 << tag << rad << endl;
		if (tag = 1) {
			num_N1 = dec(N1, rad);
//			cout << dec(N2, 2);
//			cout << num_N1 << endl;
			for (int i = 2; i <= 35; i++) {
				if (num_N1 == dec(N2, i)) {
					cout << i << endl;
					break;
				}
				if (i == 35) {
					puts("Impossible");
				}
			}
		} else {
			num_N2 = dec(N2, rad);
			
			for (int i = 2; i <= 35; i++) {
				if (num_N2 == dec(N1, i)) {
					cout << i << endl;
					break;
				}
				if (i == 35) {
					puts("Impossible");
				}
			}			
			
		}
	}
	
	
	return 0;
} 
