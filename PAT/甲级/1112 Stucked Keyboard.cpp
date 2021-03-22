/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description:
 ************************************************************************/
#include <bits/stdc++.h>
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
string str;
int a[maxn], ind = 0;
map<char, int> vis, flag;
string anss;

void solve()
{
	n = read();
	cin >> str;
	string ans = "";
	string tmp;
	int con = 1;
	for (int i = 0; i < str.size() - 1; i++) {
		if (str[i] != str[i + 1]) {
			tmp += str[i];
			a[ind++] = con;
			con = 1;
		} else {
			con++;		
		}
	}
	
	if (str[str.size() - 1] == str[str.size() - 2]) {
		a[ind++] = con; tmp += str[str.size() - 1];
	} else {
		tmp += str[str.size() - 1];
		a[ind++] = 1;
	}
//	debug(tmp);
	
	for (int i = 0; i < ind; i++) {
//		cout << a[i] << ' ';
		if (a[i] % n) {
			vis[tmp[i]] = 1;
		}
	}
	for (int i = 0; i < ind; i++) {
		if (!vis[tmp[i]]) {
			if (!flag[tmp[i]]) {
				anss += tmp[i];
				flag[tmp[i]] = 1;
			} 
		}
	}
	cout << anss << endl;
	for (int i = 0; i < ind; i++) {
		if (!vis[tmp[i]]) {
			for (int j = 0; j < a[i] / n; j++) {
				cout << tmp[i];
			}
		} else {
			for (int j = 0; j < a[i]; j++) {
				cout << tmp[i];
			}
		}
	}
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

