#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;

int n, m, flag = -1;
struct node {
	string id;
	int con[4], best, rank[4]; 
}N[2005];

bool cmp(node a, node b) {
	return a.con[flag] > b.con[flag];
}
map<string, int> MM;
int main() {
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) { 
		cin >> N[i].id >> N[i].con[1] >> N[i].con[2] >> N[i].con[3];
//		cout << (N[i].c + N[i].m + N[i].e) / 3 << endl;
		N[i].con[0] = (N[i].con[3] + N[i].con[1] + N[i].con[2]) / 3;
		
	}
	
	for (flag = 0; flag < 4; flag++) {
		sort(N, N + n, cmp);
		N[0].rank[flag] = 1;
		for (int i = 1; i < n; i++) {
			N[i].rank[flag] = i + 1;
			if (N[i].con[flag] == N[i - 1].con[flag]) {
				N[i].rank[flag] = N[i - 1].rank[flag];
			}
		}
	}
	
	for (int i = 0; i < n; i++) {int temp = 0x3f3f3f3f, ind = 0;
		MM[N[i].id] = i;
		for (int j = 0; j < 4; j++) {
			if (N[i].rank[j] < temp) {
				temp = N[i].rank[j];
				N[i].best = j;
			}
		}
	}
	
	string str;
	map<int, char> M;
	M[0] = 'A';
	M[1] = 'C';
	M[2] = 'M';
	M[3] = 'E';
	for (int i = 0; i < m; i++) {
		cin >> str;
		if (MM.count(str)) {
			int j = MM[str];
			if (N[j].id == str) {
				cout << N[j].rank[N[j].best] << ' ' << M[N[j].best] << endl;
			}
		}else {
			puts("N/A");
		}

	}

	return 0;
}

