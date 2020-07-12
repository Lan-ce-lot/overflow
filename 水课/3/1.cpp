#include <iostream>
using namespace std;
int Pow(int x, int y) {
    int res = 1;
    for (int i = 0; i < y; i++) {
        res *= x;
    }
    return res;
}
char ans[100];
int len;
void build(int n, int pos) {
    if (pos == len) {
        ans[pos] = '\0';
        return;
    }
    int cnt = 0, l = len - pos;
    for (int i = 0; i < 26; i++) {
        if (cnt + Pow(26, l - 1) >= n) {
            ans[pos] = 'A' + i;
            build(n/26, pos + 1);
            break;
        } else {
            cnt += Pow(26, l - 1);
        }
    }
}
int main() {
    int n;
    while (cin >> n) {
        int cnt = 0;
        for (len = 1; len < 100; len++) {
            if (cnt + Pow(26, len) >= n) {
                break;
            } else {
                cnt += Pow(26, len);
            }
        }
        build(n - cnt, 0);
        cout << ans << endl;
    }
    return 0;
}
