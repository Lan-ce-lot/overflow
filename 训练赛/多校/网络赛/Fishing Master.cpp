/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description:
 ************************************************************************/
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
const int maxn = 1e5 + 5;

ll t, n, k;
ll time[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--)
    {
        ll ans = 0, res = 0;
        cin >> n >> k;
        ans = k * n;
        for (int i = 0; i < n; i++)
        {
            cin >> time[i];
            ans += time[i];
        }
        sort(time, time + n, greater<int> ());
        for (int i = 0; i < n - 1; i++)//如果time[i]个大于等于k，就用time[i],否则用n*k(大于time[i]的第一个)
        {
            if (time[i] > k )
            {

                if (time[i + 1] >= k)
                {
                    res += (time[i] / k ) * k;
                    i += time[i] / k - 1;
                }
                else
                {
                    if (i + time[i] / k < n - 1)
                    {
                        res += time[i];
                        i += time[i] / k ;
                    }
                    else
                    {

                    }
                }
            }

            else
            {
                i != n - 1 ? res += time[i] : 0;
            }

        }
        cout << ans - res << endl;

    }
    return 0;
}
/*
100
3 5
9 4 4
3 5
5 2 3
3 5
9 5 5
3 5
5 5 8
2 4
3 3
3 5
4 2 3
3 5
9 7 2
5 5
9 7 5 3 2
*/
/*

23
17
24


33
*/
