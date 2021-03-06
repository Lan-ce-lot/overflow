#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5;
int n;
int a[maxn], dao[maxn];
vector<int> V;
int main()  {
//	T_T
//  ^_^
//	cin >> n;
	for (int i = 1; i <= 6; i++) {
		cin >> a[i];
	}
	int maxx = 0, flag_ty = 0, minn = 0x3f3f3f3f;
	for (int i = 1; i <= 4; i++) {
		maxx = max(maxx, a[i]);
		minn = min(minn, a[i]);
		if (a[i] < a[5]) {
			flag_ty++;
			V.push_back(a[i]);
		}
		
	}
	int minn_i = min_element(a + 1, a + 4 + 1) - a;
	int maxx_i = max_element(a + 1, a + 4 + 1) - a;
//	cout << maxx_i << minn_i << endl;
	if (flag_ty == 0 && maxx - minn <= a[6]) {
		puts("Normal");
	} else if (flag_ty == 0 && maxx - minn > a[6]){
		printf("Warning: please check #%d!\n", minn_i);
	} else if (flag_ty == 1) {
		printf("Warning: please check #%d!\n", minn_i);
	} else {
		puts("Warning: please check all the tires!");
	}
	return 0;
}
