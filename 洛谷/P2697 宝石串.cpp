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
const int maxn = 1005;
int a[maxn], ans = 0 ;
int dp[maxn][maxn];
int pre[maxn], n, m;
string str;
int num[maxn];
int main()
{
    cin >> str;
    
    for (int i = 0; i < str.size(); i++)
    {
        if(str[i] == 'G')
            pre[i + 1] = pre[i] - 1;
        else
            pre[i + 1] = pre[i] + 1;
        num[pre[i + 1] + str.size()] = i +1;
    }

    for (int i = 0; i <= str.size(); i++)
    {
        ans = max(ans, num[pre[i] + str.size()] - i);
    }
    cout << ans << endl;
    return 0;
}

