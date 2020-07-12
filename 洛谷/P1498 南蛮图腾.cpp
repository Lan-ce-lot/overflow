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
ll n, k, a[maxn] = {1};
/*
 /\
/__\
*/
int main()
{
    cin >> n;
    for (int i = 0; i < 1 << n; i++)
    {
        for (int j = 1; j < (1 << n) - i; j++)
            cout << " ";
        for (int j = i; j >= 0; j--)
            a[j] ^= a[j - 1];
        if (!(i % 2))
            for (int j = 0; j <= i; j++)
                cout << (a[j] ? "/\\" : "  ");
        else
            for (int j = 0; j <= i; j += 2)
                cout << (a[j] ? "/__\\" : "    ");
            cout << endl;
    }
    return 0;
}

