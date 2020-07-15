#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int t, n, a[1005];

int mex() {
    int vis2[1005];
    memset(vis2, 0, sizeof vis2);

    for (int i = 0; i < n; i++) {
        vis2[a[i]] ++;
    }
    for (int i = 0; i <= n; i++) {
        if (vis2[i] == 0) return i;
    }
    return n;
}


int main() {
    // cout << "Helloword" << endl;
    // cout << "good night" << endl;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }

        vector<int> ans;

        while (n > 0) {
            int me = mex();
            if (me == n) {
                a[n - 1] = n;
                ans.push_back(n - 1);
                n--;
            } else {
                a[me] = me;
                ans.push_back(me);
            }
        }
        cout << ans.size() << endl;
        for (auto i : ans) {
            cout << i + 1 << ' ';
        }
        puts("");
    }
    return 0;
}