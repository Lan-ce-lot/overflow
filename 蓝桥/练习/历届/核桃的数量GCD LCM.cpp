#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
// lcm = a * b / gcd

//int lcm 
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int tem = a * b / __gcd(a, b);
	cout << tem * c / __gcd(tem, c) << endl;
	
	
//	cout << a * b * c / max(__gcd(a, b) , max( __gcd(a, c), __gcd(b, c)))<< endl;
	return 0;
}
