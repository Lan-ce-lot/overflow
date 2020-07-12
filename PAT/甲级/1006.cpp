#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

int n;
struct node {
	string ID;
	int s;
	int e;
}a[1005];



int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].ID;
		string s;
		int aa, bb, cc;
		cin >> s;
		aa = (s[0] - '0') * 10 + (s[1] - '0');
		bb = (s[2] - '0') * 10 + (s[3] - '0');
		cc = (s[4] - '0') * 10 + (s[5] - '0');
		a[i].s = aa * 3600 + bb * 60 + cc;
		cin >> s;
		aa = (s[0] - '0') * 10 + (s[1] - '0');
		bb = (s[2] - '0') * 10 + (s[3] - '0');
		cc = (s[4] - '0') * 10 + (s[5] - '0');
		a[i].e = aa * 3600 + bb * 60 + cc;
	}
	int min_s = 100000000, min_ind = 0, max_e = -1, max_ind = 0;
	for (int i = 0; i < n; i++) {
		if (a[i].s < min_s) {
			min_s = a[i].s;
			min_ind = i;
		}
		if (a[i].e > max_e) {
			max_e = a[i].e;
			max_ind = i;
		}
	}
	cout << a[min_ind].ID << ' ' << a[max_ind].ID << endl;
	
} 
