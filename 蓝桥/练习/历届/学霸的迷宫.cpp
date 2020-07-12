#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;

int n, m;
char maze[1005][1005];
map<int, char> M;
bool vis[1005][1005];
int dir[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};// U,D,L,R
struct node{
	int x, y;
	string str;
	
};


void bfs(int x, int y, string str) {
	queue<node> Q;
	Q.push({x, y, str}); 
	vis[x][y] = 1;
	while (Q.size()) {
		node top = Q.front();
		Q.pop();
		if (top.x == n - 1&& top.y == m - 1) {
//			cout << top.x << top.y << endl;
			cout << top.str.size() << endl;
			cout << top.str << endl;
			return ;
		}
		
		for (int i = 0; i < 4; i++) {
			int xx = top.x + dir[i][0];
			int yy = top.y + dir[i][1];
			if (xx >= 0 && xx < n && yy >= 0 && yy < m && !vis[xx][yy] && maze[xx][yy] == '0') {
				vis[xx][yy] = 1;
//				cout << 1 << endl;
				Q.push({xx, yy, top.str + M[i]});
			}
		}
	}
}



int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> maze[i];
	}
	
	
	M[0] = 'U';
	M[1] = 'D';
	M[2] = 'L';
	M[3] = 'R';
	bfs(0, 0, "");
	
	
	return 0;
}
