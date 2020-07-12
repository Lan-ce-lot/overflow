#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;
int n ;
char G[20][20];
bool col[1005], line[1005], _line[1005];
void dfs(int st) {
	if (st == n) {
		for (int i = 0; i < n; i++) {
			puts(G[i]);
		}
		puts("");
		return ;
	}
	
	for (int i = 0; i < n; i++) {
		if (!col[i] && !line[st + i] && !_line[n - st + i]) {
			G[st][i] = 'Q';
			col[i] = line[st + i] = _line[n - st + i] = 1;
			dfs(st + 1);
			col[i] = line[st + i] = _line[n - st + i] = 0;
			G[st][i] = '.';
		}
	}
}


int main () {
	cin >> n;
//	memset(G, '.', sizeof G);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			G[i][j] = '.';
		}
	}
	dfs(0);
	
	
	
	return 0;
	
}
