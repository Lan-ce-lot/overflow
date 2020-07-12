#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
int maze[3][3];
int a[10];
//int maze[8][3][3];
int maze1[8][3][3] = 
{
	4, 9, 2, 
	3, 5, 7, 
	8, 1, 6,
	
	8, 3, 4,
	1, 5, 9,
	6, 7, 2,
	
	6, 1, 8,
	7, 5, 3, 
	2, 9, 4,
	
	2, 7, 6,
	9, 5, 1,
	4, 3, 8,
	
	2, 9, 4,
	7, 5, 3,
	6, 1, 8,
	
	6, 7, 2,
	1, 5, 9,
	8, 3, 4,
	
	8, 1, 6,
	3, 5, 7,
	4, 8, 2,
	
	4, 3, 8,
	8, 5, 1,
	2, 7, 6
};
int main() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> maze[i][j];
		}
	}
	
	int ans = 0;
	int s = 0;
	for (int i = 0; i < 8; i++) {
		int flag = 0;
		
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				if (maze[j][k]) {
					if (maze[j][k] != maze1[i][j][k]) {
						flag = 1;
						break;
					}
				}
				if (j == 2 && k == 2) ans++, s = i;	
			}
			if (flag) break;
		}
	}
//	cout << 111 << endl;
	if (ans == 1) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (j != 0) cout << ' ';
				cout << maze1[s][i][j];
			}
			puts("");
		}
	}else {
		puts("Too Many");
	}
	return 0;
} 
