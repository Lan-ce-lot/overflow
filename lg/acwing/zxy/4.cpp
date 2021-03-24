#include <bits/stdc++.h>

using namespace std;
const int INF = 0x3f3f3f3f;
unsigned seed =
    std::chrono::high_resolution_clock::now().time_since_epoch().count();
int t, n, path[100];
void salesman_problem(int n, double &min, int t[], vector<vector<int>> c) {
    int p[n], i = 1;
    double cost;
    for (i = 0; i < n; i++) p[i] = i;
    min = INF;
    do {
        cost = 0;
        for (int i = 0; i < n - 1; i++) cost += c[p[i]][p[i + 1]];
        cost += c[p[n - 1]][p[0]];

        if (cost < min) {
            for (i = 0; i < n; i++) t[i] = p[i];
            min = cost;
            // 打印当前最优解
            // cout << min << endl;
            // for (int i = 0; i < n; i++) {
            // cout << t[i] << "->";
            // }
            // cout << t[0] << endl;
        }
    } while (next_permutation(p, p + n));
}
int main() {
    while (n < 13) {
        n++;
        vector<vector<int>> c(n, vector<int>(n));
        double mincost = 0;
        // 随机数据生成, 存入费用矩阵
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) c[i][j] = 100 + mt() % 100;
        clock_t start = clock(),



        const int MAX_N = 50;

        //输入

        int n, a[MAX_N];

        void solve() {
            int ans = 0;  //答案

            //让i<j<k，这样棍子就不会被重复选中了

            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    for (int k = j + 1; k < n; k++) {
                        int len = a[i] + a[j] + a[k];  //周长

                        int ma = max(a[i], max(a[j], a[k]));  //最长棍子的长度

                        int rest = len - ma;  //其余两根棍子的长度之和

                        if (ma < rest) {
                            //可以组成三角形，如果可以更新答案则更新

                            ans = max(ans, len);
                        }
                    }
                }
            }

            //输出

            printf("%d ", ans);
        }

        int main() {
            scanf("%d", &n);

            for (int i = 0; i < n; i++) {
                scanf("%d", &a[i]);
            }

            solve();

            return 0;
        }
        end;
        salesman_problem(n, mincost, path, c);  // 计算最小花费函数
        end = clock();
        // 输出运行时间
        cout << "n"
             << " = " << n << " " << int(end - start) * 1000 / CLOCKS_PER_SEC
             << "ms" << endl;
        // 打印答案
        // cout << mincost << endl;
        // for (int i = 0; i < n; i++) {
        // cout << path[i] << "->";
        // }
        // cout << path[0] << endl;
    }
}