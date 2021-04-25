#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 5;
int n, tot;
struct node {
    int id, num;
    double mon;
    bool operator < (node & W) {
        if (mon == W.mon) {
            if (num == W.num) return id < W.id;
            else return num > W.num;
        }
        return mon > W.mon;
    }
} N[maxn];
set<int> S;
/*
如果收入金额有并列，
则按抢到红包的个数递减输出；
如果还有并列，则按个人编号递增输出

*/
int main() {
    cin >> n;
    memset(N, 0, sizeof N);
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        N[i].id = i;
        for (int j = 0; j < k; j++) {
            int n1, p;
            cin >> n1 >> p;
            // 
            N[i].mon -= p;
            // N[n1].id = n1;
            N[n1].mon += p;
            N[n1].num ++;
            S.insert(n1);
        }
    }
    sort(N + 1, N + n + 1);
    for (int i = 1; i <= n; i++) {
        // cout << N[i].id << ' ' << N[i].mon / 100 << endl;
        printf("%d %.2lf\n",N[i].id,  N[i].mon / 100);
    }
    return 0;
}
