#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
// y m d
// m d y
// d m y

int yyyy(int n) {return n % 400 == 0 || ((n % 4) == 0 && n % 100);}
struct node {
	int y, m, d, num;
}N[3];


set<string> S;
int main() {
	string a, b, c, tem;
	cin >> tem;
	a = tem.substr(0, 2);
	b = tem.substr(3, 2);
	c = tem.substr(6, 2);
	int ia, ib, ic;
	ia = (a[0] - '0') * 10 + (a[1] - '0');
	ib = (b[0] - '0') * 10 + (b[1] - '0');
	ic = (c[0] - '0') * 10 + (c[1] - '0');
	int mon[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	int con = 0;
	string s1, s2, s3;
	// 1 y m d
	if (ib <= 12 && ib >= 1&& ic <= 31 && ic >= 1) {
		if (yyyy(ia >= 60 ? ia + 1900 : ia + 2000)) {
			mon[2] = 29;
		}
		if (ic <= mon[ib]) {
			int temp = (ia >= 60 ? ia + 1900 : ia + 2000) * 365 + ib * 30 + ic;
			N[con++] = {ia >= 60 ? ia + 1900 : ia + 2000, ib, ic, temp};
		}
		mon[2] = 28;
	}
	
	 
	// 2 // m d y
	if (ia <= 12 && ia >= 1&& ib <= 31 && ib >= 1) {
		if (yyyy(ic >= 60 ? ic + 1900 : ic + 2000)) {
			mon[2] = 29;
		}
		if (ib <= mon[ia]) {
			int temp = (ic >= 60 ? ic + 1900 : ic + 2000) * 365 + ia * 30 + ib;
			N[con++] = {ic >= 60 ? ic + 1900 : ic + 2000, ia, ib, temp};
		}
		mon[2] = 28	;	
	}
	
	// 3 d m y

	if (ia <= 31 && ia >= 1 && ib <= 12 && ib >= 1) {
		if (yyyy(ic >= 60 ? ic + 1900 : ic + 2000)) {
			mon[2] = 29;
		}
		if (ia <= mon[ib]) {
			int temp = (ic >= 60 ? ic + 1900 : ic + 2000) * 365 + ib * 30 + ia;
			N[con++] = {ic >= 60 ? ic + 1900 : ic + 2000, ib, ia, temp};
		}
		mon[2] = 28	;		
	}
	
	for (int i = 0; i < con; i++) {
		string str;
		char c[10];
		sprintf(c, "%d-%02d-%02d\n", N[i].y, N[i].m, N[i].d);
		S.insert(str = c);
	}
	for (set<string>::iterator it = S.begin(); it != S.end(); it++) {
		cout << *it;
	}
		
	return 0;
} 

