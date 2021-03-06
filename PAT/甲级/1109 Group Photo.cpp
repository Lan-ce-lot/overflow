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
int t, n, k;
struct node {
	string name;
	int h;
	bool operator < (const node &W) const{
		if (h != W.h) {
			return h < W.h;
		} else {
			return name > W.name;
		}
	} 
}N[maxn];
string str[20005], ans[20005];
void solve()
{
	n = read(), k = read();
	for (int i = 0; i < n; i++) {
		cin >> N[i].name >> N[i].h; 
	}
	sort(N, N + n);
//	for (int i = 0; i < n; i++) {
//		cout << N[i].name << ' ' << N[i].h << endl; 
//	} 
	int num = n / k, last = n / k +  n % k;
	
	// m / 2 + 1 
	int cen = num / 2, cen_l = last / 2; 
	for (int i = 0; i < k - 1; i++) {
		for (int j = 0; j < num; j++) {
			int l = cen - 1, r = cen + 1;
			if (j == 0) {
				str[cen] = N[(i + 1) * num - j - 1].name;
//				cout << str[i][cen]  <<endl;
			}
			else if (j & 1) {
				str[l--] = N[(i + 1) * num - j - 1].name;
//				cout << N[(i + 1) * num - j - 1].name  <<endl;
			} else {
				str[r++] = N[(i + 1) * num - j - 1].name;
//				cout << N[(i + 1) * num - j - 1].name  <<endl;
			}
		}
		for (int j = 0; j < num; j++) {
			ans[i] += str[j]; 
			if (j == num - 1) ans[i] += "\n";
			else ans[i] += " ";
		}
	}int l = cen_l - 1, r = cen_l + 1;
	for (int i = 0; i < last; i++) {
		
		if (i == 0) {
			str[cen_l] = N[(k - 1) * num + last - i - 1].name;
//			cout << N[(k - 1) * num + last - i - 1].name  <<endl;
		}
		else if (i & 1) {
			str[l--] = N[(k - 1) * num + last - i - 1].name;
//				cout << N[(k - 1) * num + last - i - 1].name <<  l + 1  <<endl;
		} else {
			str[r++] = N[(k - 1) * num + last - i - 1].name;
//				cout << N[(k - 1) * num + last - i - 1].name << r - 1  <<endl;
		}
	}
	for (int i = 0; i < last; i++) {
		cout << str[i];
		if (i == last - 1) {
			cout << endl;
		} else {
			cout << ' ';
		}
	}
	for (int i = k - 2; i >= 0; i--) {
		cout << ans[i];
	} 
} 

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

