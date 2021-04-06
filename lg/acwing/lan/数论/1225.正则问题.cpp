#include <bits/stdc++.h>

using namespace std;
int k;
string s;

int dfs() {
    int r = 0;
    while (k < s.size())
        if (s[k] == '(')
            k++, r += dfs(), k++;
        else if (s[k] == '|')
            k++, r = max(r, dfs());
        else if (s[k] == ')')
            break;
        else
            r++, k++;
    return r;
}
int main() {
    cin >> s;
    cout << dfs() << endl;
}
