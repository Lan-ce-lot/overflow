#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
https://www.acwing.com/solution/content/955/
推公式
转换成几何意义的距离
我们希望Xi的绝对值之和尽量小，即|X1| + |X1-C1| + |X1-C2| + ……+
|X1-Cn-1|要尽量小。注意到|X1-Ci|的几何意义是数轴上的点X1到Ci的距离，所以问题变成了：
给定数轴上的n个点，找出一个到他们的距离之和尽量小的点，而这个点就是这些数中的中位数
*/
ll n, a[1000005], ave, c[1000005], dis[1000005], ans, m;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], ave += a[i];
    ave /= n;
    for (int i = 1; i <= n; i++) c[i] = a[i] + c[i - 1] - ave;
    sort(c + 1, c + n + 1);
    m = n & 1 ? c[n / 2] : c[n / 2] + c[n / 2 + 1] >> 1;
    for (int i = 1; i <= n; i++) ans += abs(m - c[i]);
    cout << ans << endl;
}