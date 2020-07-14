#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
typedef long long ll;
using namespace std;
const int MAXN = 1e6 + 5;
int t, n, a[1005];


int main() {
	string str1, str2;
	while (cin >> str1 >> str2) {
		if (str1.size() > str2.size()) {
			str1 += str1;
			int tem = str2.size();
			for (int i = str2.size(); i < str1.size(); i++) {
				str2 += str2[i - tem];
			}
		}
		else if (str1.size() < str2.size()){
			str2 += str2;
			int tem = str1.size();
			for (int i = str1.size(); i < str2.size(); i++) {
				str1 += str1[i - tem];
			}
		}
//		cout << str1 << ' ' << str2 << endl;
		if (str1 > str2) puts(">");
		else if (str1 == str2) puts("=");
		else puts("<");
	}

		
//			if (str1.size() > str2.size()) {
//		for (int i = str2.size(); i < str1.size(); i++) {
//			str2 += str2[i - str2.size()];
//		}
//	} else {
//		for (int i = str1.size(); i < str2.size(); i++) {
//			str1 += str1[i - str1.size()];
//		}
//	}
//	if (str1 > str2) cout << ">" <<endl;
//	else if (str1 == str2) cout << '=' << endl;
//	else cout << '<' << endl;
//	}

    return 0;
}
