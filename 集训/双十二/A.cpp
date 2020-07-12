#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<algorithm> 
using namespace std;
typedef long long ll;
#define PI 3.1415927
const int INF=0x3f3f3f3f;
ll a[101], n, ans = 0x3f3f3f3f;
int main() {
    scanf("%lld", &n);
    for (ll i = 1; i <= n; i++) 
	scanf("%lld", a + i);
    for (ll i = 1; i <= n; i++)
	 {
        ll sum = 0;
        for (ll j = 1; j <= n; j++) 
			sum += a[j] * 2 * (abs(i - j) + abs(j - 1) + abs(1 - i));
        ans = std::min(ans, sum);
    }
    printf("%lld\n", ans);
    return 0;
}
