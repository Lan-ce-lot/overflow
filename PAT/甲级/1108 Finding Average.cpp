/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description:
 ************************************************************************/
//#include <bits/stdc++.h>
//#pragma comment(linker, "/STACK:102400000,102400000")//add_stack
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <vector>
#include <cstdio>
#include <bitset>
#include <string>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const double pi = acos(-1.0);
const double eps = 1e-6;
const int mod = 1e9 + 7;
#define debug(a) cout << "*" << a << "*" << endl
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 1000005;
//sacnf("%lf") printf("%f")
ll read()
{
    ll x = 0,f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
	{
		if (ch == '-')
		f = -1;
		ch = getchar();
	}
    while (ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
    return x * f;
}
int t, n;
string str[1005];
double check(string str) {
	int flag = 1, dot = 0;
	double c = 1;
	if (str[0] =='-') {
		flag = -1;
		str = str.substr(1, str.size() - 1);
	}
	double res = 0;
	for (int i = 0; i < str.size(); i++) {
		if (dot == 1) {
			c *= 10;
		}
		if (str[i] >= '0' && str[i] <= '9') {
			res *= 10;
			res += (str[i] - '0');
		} else if (str[i] == '.' && !dot) {
			dot++;
		} else {
			return INF;
		}
	}
	res = res * flag / 1.0 / c;
	if (res > 1000.0 || res < -1000.0 || c>= 1000) {
		return INF;
	}
	return res;
}
void solve()
{
	n = read();
	for (int i = 0; i < n; i++) {
		cin >> str[i];
	}
	double sum = 0;
	int con = 0;
	for (int i = 0; i < n; i++) {
		double res = check(str[i]);
//		printf("%lf\n", res);
		if (res != INF) {
			con++;
			sum += res * 100;
		} else {
			cout << "ERROR: "<< str[i] << " is not a legal number\n"; 
		}
	}
	if (con > 1) printf("The average of %d numbers is %.2lf\n", con, sum / 100.0 / con);
	else if (con == 1) printf("The average of %d number is %.2lf\n", con, sum / 100.0 / con);
	else puts("The average of 0 numbers is Undefined");
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

