#include <bits/stdc++.h>

using namespace std;
map<char, bool> M;
string a, b, c;
int main() {
    getline(cin, a);
    getline(cin, b);
    for (int i = 0; i < b.size(); i++) {
        M[b[i]] = 1;
    }
    for (int i = 0; i < a.size(); i++) {
        if (M[a[i]] == 0) c += a[i];
    }
    cout << c << endl;
    return 0;
}