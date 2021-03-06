#include<bits/stdc++.h>
//#define x first 
//
//#define y second 
using namespace std;
typedef long long ll;
const int maxn = 1e3 + 5;
ll n, m, k;
ll f[maxn];

string s, p;
int re[maxn], pr[maxn];
vector<string> V;
vector<pair<vector<int>, int> > T;
void change(string str) {
	vector<int> left;
	int right;
	for (int i = 0; i < str.size() - 2; i++) {
		if (str[i] == ' ') {
			continue;
		}
		int tem = (str[i] - '0') * 10 + str[i + 1] - '0';
		left.push_back(tem);
	}
	right = (str[str.size() - 2] - '0') * 10 + str[str.size() - 1] - '0';
	T.push_back({left, right});
//	return 
//	right = ();
}
set<int> S1, S2;
bool vis[maxn];
bool check[maxn];
int flag = 0;
vector<int> ans;
set<int> to_ans; 
void dfs(int cnt) {
	if (cnt >= m) {
		flag = 1;
		
		for (auto it : ans) {
			to_ans.insert(it);
		}
		return;
//		return 1;
	}
	int ff = 0;
	for (int i = 0; i < T.size(); i++) {
		if (T[i].second == pr[cnt]) {
			for (int j = 0; j < T[i].first.size(); j++) {
				if (vis[j] == 1) {
					ff = 1;
					for (int k = 0; k < T[i].first.size(); k++) {
						vis[k] = 0;
					}
					break;
				}
				vis[j] = 1;
			}
			if (ff = 1) continue;
//			check[i] = 1;
			ans.push_back(i);
			dfs(cnt+1);
			ans.pop_back();
//			check[i] = 0;
			for (int j = 0; j < T[i].first.size(); j++) {
				vis[j] = 0;
			}
		}
	}
//	return dfs(cnt + 1);
	
}

void print(pair<vector<int>, int> T) {
	for (int i = 0; i < T.first.size(); i++) {
		printf("%d\n", i == 0 || i == T.first.size() - 1 ? " + " : " ");
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> re[i];S1.insert(re[i]);
	}
	cin >> m;
	for (int j = 0; j < m; j++) {
		cin >> pr[j];S2.insert(pr[j]);
		vector<int> left;
		left.push_back(pr[j]);
		int right = pr[j];
		T.push_back({left, right});
	}
	cin >> k;
	char c = getchar();
	for (int i = 0; i < k; i++) {
		string tem;
		getline(cin, tem);
//		cout << tem << endl;
		change(tem);
	}
	int flag = 1;
	for (auto it : S2) {
		if (S1.count(it) == 0) {
			flag = 0;
		}
	}
	if (flag == 1) {
		for (int i = 0; i < m; i++) {
			printf("%02d -> %02d\n", pr[i], pr[i]);
		}	
	} else {
		dfs(0);
		int index = 0;
		while (index < m) {
			for (int i = 0; i < T.size(); i++) {
				if (to_ans.count(i) && T[i].second == pr[index]) {
					index++;
					print(T[i]);
				}
			}

		}
	}
	return 0;
} 
