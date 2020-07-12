#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>


using namespace std;
int n, m, ans = 0x3f3f3f3f;
int maze[1005][1005];
vector<int> room[1005];
void dfs(int st, int ro) {
	if (ro >= ans) return ;
	if (st > n) {
//		cout << ro << endl;
		ans = min(ans, ro);
		return;
	}
//	cout << st <<endl;
	for (int i = 1; i <= ro; i++) {// 房间编号从1开始 
		int flag = 0;
		for (int j = 0; j < room[i].size(); j++) {
			if (maze[st][room[i][j]]) {
				flag = 1;
				break;
//				room[i].push_back(st);
//				dfs(st + 1, ro);
//				room[i].pop_back();
			}
		}
		
		if (flag == 0) {
			room[i].push_back(st);
			dfs(st + 1, ro);
			room[i].pop_back();
		}
	}
	room[ro + 1].push_back(st);
	dfs(st + 1, ro + 1);
	room[ro +1].pop_back();
}


int main() {
	cin >> n >> m;
	
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >>b ;
		maze[a][b] = maze[b][a] = 1;
	}
	
	dfs(1, 0);
	
	cout << ans << endl;
	return 0;
}
 
