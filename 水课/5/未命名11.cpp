#include <iostream>
#include <algorithm>
using namespace std;
#define LL long long
LL n, m, a, b;
int t;
int main() {
scanf("%d", &t);
while(t--) {
scanf("%lld%lld%lld%lld", &n, &m, &a, &b);
n--, m--, a--, b--;
if (a > b) swap(a, b), swap(n, m);
if (n == 0 || m == 0) printf("%d\n", (a == 0 && b == 0) ? 0 : -1);
else if (n == 1 || m == 1) {
if (m == 1) swap(a, b), swap(n, m);
if (a == 0) printf("%lld\n", (b % 4 == 0) ? b / 2 : -1);
else printf("%lld\n", (b % 4 == 2) ? b / 2 : -1);
}
else if (a == 2 && b == 2) printf("4\n");
else if (a == 0 && b == 1) printf("3\n");
else if (a == 0 && b == 3) printf("%d\n", (m == 3) ? 5 : 3);
else if (a == 1 && b == 1) printf("%d\n", (m == 2 && n == 2) ? -1 : 4);
else if (2 * a <= b) printf("%lld\n", a + (b - 2 * a) / 4 * 2 + (b - 2*a)%4);
else printf("%lld\n", (a + b) / 3 + (a + b) % 3);
}
return 0;
}

