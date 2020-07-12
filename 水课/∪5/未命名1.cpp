#include <iostream>
#include <algorithm>
using namespace std;
#define LL long long
LL gcd(LL x, LL y) {
return y ? gcd(y, x % y) : x;
}
int main()
{
int n = 45;
LL ans = 1;
for (int i = 1; i <= n; i++) {
if (i != 43) ans = ans / gcd(ans, i) * i;
}
printf("%lld\n", ans);
return 0;
}

