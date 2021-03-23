#include <bits/stdc++.h>

using namespace std;
int m[13]{0, 31, 28, 31, 30, 31,30, 31, 31, 30, 31, 30, 31}, ans;
int y_1, m1, d1, y2, m2, d2, all1 = 0, all2 = 0;
bool check(string s) {
    m[2] = 28;
    int yy = stoi(s.substr(0, 4)), my = stoi(s.substr(4, 2)), dy = stoi(s.substr(6, 2));
    if ((yy % 4 == 0 && (yy % 100)) || yy % 400 == 0) m[2]++;
    if (my < 1 || my > 12) {
        return 0;
    }
    if (dy < 1 || dy > m[my]) {
        return 0;
    }
    if (y_1 == yy) {
        if (m1 > my) return 0;
        if (m2 == my && dy < d1) return 0;
    }
    if (y2 == yy) {
        if (m2 < my) return 0;
        if (m2 == my && dy > d2) return 0;
    }
    return 1;
}
int main () {
    string s1, s2;
    
    cin >> s1 >> s2;
    y_1 = stoi(s1.substr(0, 4)), m1 = stoi(s1.substr(4, 2)), d1 = stoi(s1.substr(6, 2));
    y2 = stoi(s2.substr(0, 4)), m2 = stoi(s2.substr(4, 2)), d2 = stoi(s2.substr(6, 2));
    // 只要，枚举年
    for (int i = y_1; i <= y2; i++) {
        string r = to_string(i);
        string tem = r;
        reverse(r.begin(), r.end());
        tem += r;
        ans += check(tem);
        // if (check(tem)) cout << tem << endl;
    }
    cout << ans << endl;
}