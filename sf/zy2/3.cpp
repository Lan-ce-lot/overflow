#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e7 + 10;
/*
4
8 10 11 9
0 375 4218 31
6
17 20 24 19 22 25
16 110 1703 47 406 3468
5
359999 431998 518397 300000 746491
31 47 47 31 78
0
*/
int n, scale[N], Time[N];

long double f1[N], f2[N], f3[N], f4[N], f5[N], f6[N];

long double avg1, avg2, avg3, avg4, avg5, avg6;

long double variance[7];

long double get_var(long double f[])
{
    long double avg = accumulate(f, f + n, 0ll) / n;
    long double res = 0;
    for (int i = 0; i < n; i++)res += (f[i] - avg) * (f[i] - avg);
    res = sqrt(res);
    res /= avg;
    return fabs(res);
}


ll fact(ll num)
{
    ll res = 1;
    for (ll i = 2; i <= num; i++)res *= i;
    return res;
}
signed main()
{
    while (cin >> n, n)
    {
        for (ll i = 0; i < n; i++)cin >> scale[i];
        for (ll i = 0; i < n; i++)
        {
            cin >> Time[i];
            if (!Time[i])Time[i] = 1;
            f1[i] = 1. * scale[i] / Time[i];
            f2[i] = 1. * scale[i] * log(scale[i]) / Time[i];
            f3[i] = 1. * scale[i] * scale[i] / Time[i];
            f4[i] = 1. * scale[i] * scale[i] * scale[i] / Time[i];
            if (scale[i] <= 30)
                f5[i] = 1. * pow(2, scale[i]) / Time[i];
            else
                f5[i] = 1. * Time[i] / pow(2, scale[i]);
            if (scale[i] <= 20)
                f6[i] = 1. * fact(scale[i]) / Time[i];
            else
                f6[i] = 1. * Time[i] / fact(scale[i]);
        }
        variance[1] = get_var(f1);
        variance[2] = get_var(f2);
        variance[3] = get_var(f3);
        variance[4] = get_var(f4);
        variance[5] = get_var(f5);
        variance[6] = get_var(f6);
        double ans = LONG_MAX;
        int number = -1;
        for (int i = 1; i <= 6; i++)
            if (ans - variance[i] > 0)
            {
                ans = variance[i];
                number = i;
            }
        cout << number << endl;
    }
}
