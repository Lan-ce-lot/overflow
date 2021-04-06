#include <cstring>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
const int MOD = 1e9;
typedef long long ll;
const int N = 310, mod = 1e9;
string str;
int f[N][N];
ll dp(int l, int r) {
    if (l > r) return 0;
    if (l == r) return 1;
    int& ans = f[l][r];
    if (ans != -1) return ans;
    ans = 0;
    if (str[l] == str[r])
        for (int k = l; k < r; k+=2)
            ans = (ans + dp(l, k) * dp(k + 1, r - 1)) % MOD;
    return ans;
}
int main()
{
    cin >> str;
    int n = str.size();
    str = ' ' + str;
    memset(f, -1, sizeof f);
    cout << dp(1, n) << endl;

    return 0;
}