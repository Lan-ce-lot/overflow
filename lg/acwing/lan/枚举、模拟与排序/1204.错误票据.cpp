#include<bits/stdc++.h>

using namespace std;
map<int, int> M;
int n, a, l = 0x3f3f3f3f, r = -1, a1, a2;
int main() {
    cin >> n;
    while (cin >> a) {
        M[a]++;
        l = min(l, a), r = max(r, a);
    }
    for (int i = l; i <= r; i++) {
        if (!M[i]) {
            a1 = i;
        }
        if (M[i] == 2) a2 = i;
    }
    cout << a1 << ' ' << a2 <<endl;
}