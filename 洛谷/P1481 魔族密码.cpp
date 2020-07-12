/*************************************************************************
 > FileName:
 > Author:      huangchangsheng
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description:
 ************************************************************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <cmath>
#include <sstream>
using namespace std;
typedef long long ll;
const double pi = acos(-1.0);
const int eps = 1e-10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;                             //int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 10005;
int a[maxn], dp[maxn], ans, n;
string str[2005];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> str[i];
        dp[i] = 1;
        for (int j = i - 1; j >= 1; j--)
        {
            string str1 = str[i], str2 = str[j];
            if (str1.substr(0, (int)str2.size()) == str2)
            {
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }

        ans = max(dp[i], ans);
    }
    cout << ans;
    return 0;
}
