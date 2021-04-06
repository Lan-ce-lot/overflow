#include <bits/stdc++.h>

using namespace std;
int n, s, a[500005];
double l[500005], ans, ave, cave;
int main() {
    cin >> n >> s;
    for (int i = 1; i <= n; i++) cin >> l[i];
    sort(l + 1, l + n + 1);
    cave = ave = s * 1.0 / n;
    for (int i = 1; i <= n; i++)
        if (l[i] <= cave) {
            s -= l[i];
            ans += (ave - l[i]) * (ave - l[i]);
            cave = s * 1.0 / (n - i);
        } else
            ans += (cave - ave) * (cave - ave);
    printf("%.4lf\n", sqrt(ans / n));
}