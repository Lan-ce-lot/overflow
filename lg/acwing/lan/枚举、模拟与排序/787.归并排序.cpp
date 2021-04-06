#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, a[N], q[N];

void mer(int l, int r) {
    if (l >= r) return;
    int mid = l + r >> 1;
    mer(l, mid);
    mer(mid + 1, r);

    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r)
        if (a[i] < a[j]) q[k++] = a[i++];
        else q[k++] = a[j++];
    while (i <= mid) q[k++] = a[i++];
    while (j <= r) q[k++] = a[j++];
    for (int i = l, j = 0; i <= r; i++, j++) a[i] = q[j];
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // sort(a, a + n);
    mer(0, n - 1);
    for (int i = 0; i < n; i++) cout << a[i] <<' ';
}