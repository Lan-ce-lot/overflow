#include <iostream>
#include <cstring>

using namespace std;

int main() {
	int t, n;
	cin >> t;
	
	n = t * 4 + 5;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != 0 && i != n - 1 && (i % 2 == 0) && i == j)
				cout << '$';
			else if (i != 0 && i != n - 1 && (i % 2 == 0) && i == n - 1 - j)
				cout << '$';
				
			else if ((i % 2 == 0) && i < n / 2 && j >= i + 2 && j < n - i - 2) {
				cout << '$';
			}
			else if ((i % 2 == 0) && i >= n / 2 && j >= n - (i - 1) && j <= i - 2) {
				cout << '$';
			}
			
			else if (j % 2 == 0 && j < n / 2 && i >= j + 2 && i < n - j - 2) {
				cout << '$';
			}
			else if (j % 2 == 0 && j >= n / 2 && i >= n - (j - 1) && i <= j - 2) {
				cout << '$';
			}
			//
			else if (i % 2 && j == i + 1 && i < n / 2 && j < n / 2) {
				cout << '$';
			}
			else if (j % 2 && i == j + 1 && i < n / 2 && j < n / 2) {
				cout << '$';
			}
			else if (i % 2 && n - j - 1 == i + 1 && i < n / 2 && j >= n / 2) {
				cout << '$';
			}
			else if (j % 2 && n - i + 1 == j + 1 && i < n / 2 && j >= n / 2) {
				cout << '$';
			}
			else if (i % 2 && j == n - i && i >= n / 2 && j < n / 2) {
				cout << '$';
			}
			else if (j % 2 && i == n - j - 2 && i >= n / 2 && j < n / 2) {
				cout << '$';
			}
			else if (i % 2 && n - i == n - j - 1 && i >= n / 2 && j >= n / 2) {
				cout << '$';
			}
			else if (j % 2 && n - j == n - i - 1 && i >= n / 2 && j >= n / 2) {
				cout << '$';
			}
			//
			else {
				cout << '.';
			}
		}
		puts("");
	}
	
	return 0;
}
// 1 5 9 13

// 9 13 17
//..$$$$$..
//..$...$..
//$$$.$.$$$
//$...$...$
//$.$$$$$.$
//$...$...$
//$$$.$.$$$
//..$...$..
//..$$$$$..

//..$$$$$$$$$$$$$..
//..$...........$..
//$$$.$$$$$$$$$.$$$
//$...$.......$...$
//$.$$$.$$$$$.$$$.$
//$.$...$...$...$.$
//$.$.$$$.$.$$$.$.$
//$.$.$...$...$.$.$
//$.$.$.$$$$$.$.$.$
//$.$.$...$...$.$.$
//$.$.$$$.$.$$$.$.$
//$.$...$...$...$.$
//$.$$$.$$$$$.$$$.$
//$...$.......$...$
//$$$.$$$$$$$$$.$$$
//..$...........$..
//..$$$$$$$$$$$$$..
