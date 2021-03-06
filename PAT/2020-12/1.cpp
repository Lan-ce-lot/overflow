#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
ll n;
ll f[maxn];
/*
39
63245986
*/

string s, p;
int pos[maxn];
int to[maxn];
vector<int> star, endd;

bool check(string str) {
	int index = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == p[index]) {
			index++;
		}
	}
//	cout << index << endl;
	if (index == p.size()) {
		return 1;
	}
	return 0;
}

int main() {
	while (cin >> s >> p) {
//		string ans = "";
		int len = 0x3f3f3f3f;
		int st = 0, tem = 0;
		string ans = "", ss = "";
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == p[0]) {
				star.push_back(i);
			}
			if (s[i] == p[p.size()- 1] ) {
				endd.push_back(i);
			}
		}
//		int end_i = ;
		int end_i = 0;
		for (int i = 0; i < star.size(); i++) {
			int ks = star[i];
			for (int j = end_i; j < endd.size(); j++) {
				int js = endd[j];
				if (js >= ks) {
					string tem = s.substr(ks, js - ks + 1);
//					cout << tem << endl;
					if (check(tem) && tem.size() < len) {
						ans = tem;
						len = ans.size();
						end_i = j;
						break;
					}
//					cout << tem << endl;
				}

			}
		}
		cout << ans << endl;
	}
	return 0;
} 
