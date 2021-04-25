#include<iostream>
using namespace std;
int t, n;

int M[]{0, 0, 0, 2, 12, 72, 504, 3588, 30224, 282120};
int main() {
	while (cin >> n)
		cout << M[n] << endl; 
}
