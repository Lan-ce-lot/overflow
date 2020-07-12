#include<bits/stdc++.h>

using namespace std;
int k;
double a, b;
map<int, double> M;
int main() {
	map<int, double>::iterator it; 
	cin >> k;
	
	for (int i = 0; i < k; i++ ){
		cin >> a;
		cin >> b;
		M[a] += b;
	}
	
	cin >> k; 
	for (int i = 0; i < k; i++) {
		cin >> a;
		cin >> b;
		M[a] += b;
		
	}
	for (it = M.begin(); it != M.end(); it++) {
		if (it->second == 0) {
			M.erase(it);
		}
	}
	cout << M.size() << ' ';
	if (M.size() > 1) {
		for (it = M.end(), it--;; it--) {
		
			if (it == M.begin()) {
				cout << it->first << ' ' << it->second;break;
			}
			cout << it->first << ' ' << setiosflags(ios::fixed)<<setprecision(1) << it->second << ' ';
		}
	}
	else {
		cout << M.begin()->first << ' ' << setiosflags(ios::fixed)<<setprecision(1) << M.begin()->second;
	}
	
	
	cout << endl;
	return 0; 
}
