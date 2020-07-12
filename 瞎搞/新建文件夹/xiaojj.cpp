#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long ll;
#define PI 3.1415927
#define M(a) memset(a, 0, sizeof(a))
const int INF = 0x3f3f3f3f;
inline int lowbit(int x) { return x & (-x); }
inline int geteins(int x)
{
    int ans = 0;
    while (lowbit(x))
    {
        ans++;
        x -= lowbit(x);
    }
    return ans;
}
int bitcount(unsigned int n)
{
    unsigned int cnt = 0;

    while (n)
    {
        n &= (n - 1);
        cnt++;
    }

    return cnt;
}
int main()

{
    int x;
    while (~scanf("%d", &x))
        printf("%d\n", __builtin_popcountll(x));

    //	system("pause");
    return 0;
}
