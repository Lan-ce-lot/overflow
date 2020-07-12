#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
const double I = (sqrt((long double)5) + (long double)1) / (long double)2;
#define debug(a) cout << "*" << a << "*" << endl
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 1000005;

int t, n, a, b, k;
void solve()
{
    while (cin >> a >> b) printf("%d\n", min(a, b) != int(abs(b - a) * I));
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

