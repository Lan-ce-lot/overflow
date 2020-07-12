
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
const int maxn = 100005;
ll a, b;
unsigned long long c;
int main()
{
    while (~scanf("%lld %lld", &a, &b))
    {
        if (a > 0 && b > 0)
        {
            c = (unsigned long long)(a + b);
            printf("%llu\n", c);
        }
        else if (a < 0 && b < 0)
        {
            c = (unsigned long long)( -a - b);
            printf("-%llu\n", c);
        }
        else
            printf("%lld\n", a + b);
    }

    return 0;
}

