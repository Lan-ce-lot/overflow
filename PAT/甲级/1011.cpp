#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

vector<double> a[3];

int main() {
	double aa, bb, cc;
	double ans[3], sum = 1;
	for (int i = 0; i < 3; i++) {
		cin >> aa >> bb >> cc;
		a[i].push_back(aa);
		a[i].push_back(bb);
		a[i].push_back(cc);
	}
	for (int i = 0; i < 3; i++) {
	
		aa = a[i][0];
		bb = a[i][1];
		cc = a[i][2];		
		if (aa > bb) {
			if (aa > cc) {
				ans[i] = aa;cout << "W ";
			} else {
				ans[i] = cc;cout << "L ";
			}
		} else {
			if (bb > cc) {
				ans[i] = bb;cout << "T ";
			} else {
				ans[i] = cc;cout << "L ";
			}
		}
			
	}
	for (int i = 0; i < 3; i++) {
		sum *=ans[i];
		
	}
	sum  = (sum * 0.65 - 1) * 2;
	printf("%.2f\n", sum);
	return 0;
} 
