#include <bits/stdc++.h>

using namespace std;

int n, m;
char c;
char ans[1005][1005];
int main() {
    cin >> n >> c;
    m = (n * 10 / 2 + 5)  / 10;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << c;
        }
        puts("");
    }
    return 0;
}
