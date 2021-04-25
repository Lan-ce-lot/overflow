#include <bits/stdc++.h>

using namespace std;
int n, f;
string s[105];
int W[19] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
int Z[19] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int M[19] = {1, 0, X, 9, 8, 7, 6, 5, 4, 3, 2};
bool check(string s) {
    for (int i = 0; i < s.size(); i++) {
        if () {

        }
    }
}
int main() {
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    for (int i = 1; i <= n; i++) {
        if (check(s[i])) {
            cout << s[i] << endl;
            f = 1;
        }
    }
    if (!f) puts("All passed");
    return 0;
}
