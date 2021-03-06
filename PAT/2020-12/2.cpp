#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
ll n;
ll f[maxn];

string s, p;
int str[maxn];
//vector<int> str;
int dep[maxn];
string tree[1005];
vector<int> G[maxn];
int fa[maxn];
int qqq; 
void findf(int now) {
	if (now == 0) {
		printf("%04d->", now);
		return;
	}
	findf(fa[now]);
	if (now == qqq) {
		printf("%04d", now);
	} else {
		printf("%04d->", now);
	}
	 
}
set<int> S;
int main() {
	cin >> n;
	char c;
	c = getchar();
	for (int i = 0; i < n; i++) {
		string tem;
		int res = 0;
		getline(cin, tem);
//		cout << tem;
//		len = 1;
		dep[i] = tem.size() - 4;
		for (int i = 0; i < tem.size(); i++) {
			if (tem[i] != ' ') {
				res *= 10;
				res += tem[i] - '0';
			}	
		}
		str[i] = res;
		S.insert(res);
//		cout << str[i] << i << endl;;
	} 
	int fff = str[0];
	for (int i = 1; i < n; i++) {
		
		if (dep[i] > dep[i - 1]) {
			fa[str[i]] = fff;
			fff = str[i];
//			G[i].push_back();
		} else if (dep[i] == dep[i - 1]) {
			fa[str[i]] = fa[fff];
			fff = str[i];
		}
		if (dep[i] < dep[i - 1]) {
			int ret = dep[i - 1] - dep[i];
			for (int j = 0; j <= ret; j++) {
				fff = fa[fff];
			}
			fa[str[i]] = fff;
			fff = str[i];
		}
//		cout << fa[str[i]] << ' ' <<  str[i] << endl;
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
//		int a;
		cin >> qqq;
		
		if (S.count(qqq)) {
			findf(qqq);
		} else {
			printf("Error: %04d is not found.", qqq);
		}
		puts("");
	}
	
	return 0;
} 
