#include<iostream>
#include<cstring>
#include<cstdio>
#include<set>
#include <iterator>
using namespace std;

set<int> S;
int e[100005];
int n, a[100005];
int ans[100005];
int lowbit(int x) {
	return x & -x; 
}

void add(int x, int k) {
	for (int i = x; i <= n; i += lowbit(i)) e[i] += k;
}

int sum(int x) {
	int res = 0;
	for (int i = x; i; i -= lowbit(i)) res += e[i];
	return res;
}


int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) S.insert(i);
	for (int i = 2; i <= n; i++) {
		cin >> a[i];
	}
	
	for (int i = n; i; i--) {
		set<int>::iterator it = S.begin();
//		cout << *it << endl;
		advance (it, a[i]);
//		cout << *it << endl;
//		it = S.begin() + 1;
		ans[i] = *it;
		S.erase(it);
		
	}
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << endl;
	}
	return 0;
}
