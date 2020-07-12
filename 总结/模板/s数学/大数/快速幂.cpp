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
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 1005;

ll mod_pow(ll x, ll n, ll mod)
{
	ll res = 1;
	while (n)
	{
		if (n & 1)//ji
		{
			res *= x % mod;
		}
		x *= x % mod;
		n >>= 1;
	}
	return res;
}

int main()
{
	ll n, m;
	while (cin >> n >> m)
    	cout << mod_pow(n, m ,2000000);
    return 0;
}
