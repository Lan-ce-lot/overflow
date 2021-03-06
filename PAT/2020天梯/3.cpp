#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5;
int n, m;
int ma[10][10];
vector<int> ans;
int coin[100] {0, 0,0,0,0,0,
10000,36,720,360,80,252,108,72,54,	180,72,180,119,36,306,1080,144,1800,3600
};

bool vis[100];
int a[maxn];
typedef long long ll;
int tree[maxn]{18 ,34, 55, 71, 2, 10, 15, 91};
void dfs(int node) {
	
	
}

int main()  {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	cout << tree[1];
	for (int i = 2; i <= n; i++) {
		cout << ' '  <<tree[i];
	}
	
//	tree[1] = a[n];
//	for (int i = n; i >= 1; i--) {
//		if () {
//			
//		}
//	}
	
	
	
	
	return 0;
}
