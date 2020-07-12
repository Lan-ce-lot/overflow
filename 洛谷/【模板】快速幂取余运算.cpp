/*************************************************************************
 > FileName:
 > Author:      Lance
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
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 1005;

ll b, p, mod;

ll Q_pow(ll b, ll p)
{
    ll ans = 1;
    while (p)
    {
        if (p & 1)
            ans = (ans * b) % mod;
        b = (b * b) % mod;
        p >>= 1;
    }
    return ans % mod;
}



int main()
{
    cin >> b >> p >> mod;
    cout << b << '^' << p <<" mod " << mod << '=' << Q_pow(b, p) << endl;//2^10 mod 9=7
    return 0;
}

