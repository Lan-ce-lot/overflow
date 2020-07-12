#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
string s;
int n = 0;
bool vis[1005];

void dfs(int st, string str) {
	if (st == n) {
		cout << str << endl;
		return ;
	}
	
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			vis[i] = 1;
			dfs(st + 1, str.size() ? str + ' ' + char(i + '0') : str + char(i + '0'));
			vis[i] = 0;
		}
	}
	
	
}


int main() {
	
	cin >> n;
	dfs(0, "");
	return 0;
}

