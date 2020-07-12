//#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")//add_stack
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <vector>
#include <cstdio>
#include <bitset>
#include <string>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
const double pi = acos(-1.0);
const int eps = 1e-10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 1005;

ll t, n, a, b, c;
int main()
{
//    ios::sync_with_stdio(false);
    scanf("%lld", &t);
    while (t--)
    {
        scanf("%lld%lld", &a, &b);
        if ((a & b)==0)
        {
            printf("%lld\n", min(a,b));
            continue;
        }
        printf("%lld\n", (a & b));
    }
    return 0;
}
