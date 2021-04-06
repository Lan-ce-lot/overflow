#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
unsigned seed = std::chrono::high_resolution_clock::now()
				 .time_since_epoch().count();
std::mt19937 mt(seed);
int t, n, path[100];

void salesman_problem(int n, double &min, int t[], vector<vector<int>> c) {
	int p[n], i = 1;
	double cost;
	for (i = 0; i < n; i++) p[i] = i;
	
	min = INF;
	do {
		cost = 0;
		for (int i = 0; i < n - 1; i ++) 
			cost += c[p[i]][p[i + 1]];
		cost += c[p[n - 1]][p[0]];
		if (cost < min) {
			for (i = 0; i < n; i++)
				t[i] = p[i];
			min = cost;
			
			// 打印当前最优解 
//			cout << min << endl;
//			for (int i = 0; i < n; i++) {
//				cout << t[i] << "->";
//			}
//			cout << t[0] << endl;
		}
	} while (next_permutation(p, p + n));
	
}

int main() {
	while (n < 13) {
		n++;
		vector<vector<int> > c(n, vector<int> (n));
		double mincost = 0;
		// 随机数据生成, 存入费用矩阵 
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				c[i][j] = 100 + mt() % 100;
				
		clock_t start = clock(), end;
		salesman_problem(n, mincost, path, c); // 计算最小花费函数 
		end = clock();
		// 输出运行时间
		cout << "n" << " = " << n << "  " 
		<< int(end - start) * 1000 / CLOCKS_PER_SEC << "ms" << endl;
		// 打印答案 
//		cout << mincost << endl;
//		for (int i = 0; i < n; i++) {
//			cout << path[i] << "->";
//		}
//		cout << path[0] << endl;
	}
}
