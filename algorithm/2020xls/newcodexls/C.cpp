#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int t, n, m;

int node[1005];
int d[1005];
//int G[105][105];
vector<int> G[105];
vector<int> del;
int vis[105];
int tr[105][105]; 
int ff = 0;

int get(int no) {
	int res = 0; 
	for (int i = 0; i < G[no].size(); i++) {
		int tem = G[no][i];
		if (tr[no][tem] == 0) {
			res++;
		}
	}
	return res;
}

void dfs(int no, int cen) {
	cout << no << "," << cen << ' ' << get(no) << endl;
	if (ff == 1) return ;
	if (cen >= n) {
//		puts("Yes");
//		for (int)

		if (d[no] == get(no)) {
//			for (int i = 1; i <= n; i++) {
//				for (int j = 1; j <= n; j++) {
//					if (tr[i][j] == 1) {
//						cout << i << "->" << j << endl;
//					}
//				}
//			}
			ff = 1;
		}
			
		return;
//		return 1;
	}
	int con = 0;
	
//	for (int i = 0; i < G[no].size(); i++) {
//		int tem = G[no][i];
//		if (tr[no][tem]) {
//			res++;
//		}
//	}
	for (int i = 0; i < G[no].size(); i++) {
		int tem = G[no][i];
		
		if (get(no) == d[no] && vis[tem] == 0) {
			vis[tem] = 1;
			cout << "0" << d[no] << ' ' << get(no) << endl;
			dfs(tem, cen + 1);
			vis[tem] = 0;
			
		} else if (tr[tem][no] == 0 && vis[tem] == 0) {
			tr[tem][no] = tr[no][tem] = 1;
//			con++;
			if (get(no) == d[no]) {
				cout << "1" << tem << endl;
//				vis[tem] = 1;
				dfs(no, cen);
//				vis[tem] = 0;
				tr[tem][no] = tr[no][tem] = 0;
//				con--; 
			}
		} 
//		else {
//			cout << "debug" << endl;
//		}
	}
}

string str;
int main() {
//	cin >> n;
//	cin >> str;
	while (cin >> n >> m) {
		ff = 0;
		memset(d, 0, sizeof d);
		memset(G, 0, sizeof G);
		memset(vis, 0, sizeof vis);
		memset(tr, 0, sizeof tr);
		for (auto i : G) {
			i.clear();
		}
//		memset(node, 0, sizeof node);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &d[i]);
		}
		for (int i = 0; i < m ; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
//			G[a][b] = G[b][a] = 1;
			G[a].push_back(b);
			G[b].push_back(a);
//			d[a] -- ;
//			d[b] -- ;
		}
		
		vis[1] = 1;
		dfs(1, 1);
		if (ff == 1) cout << "Yes" << endl;
		else cout << "No" << endl;

	}
    return 0;
}
/*
4 5
2 2 2 2
1 2
1 4
1 3
2 3
3 4

6 7
1 1 2 1 1 2
1 2
2 3
3 4
4 5
5 6
6 1
6 3
*/
