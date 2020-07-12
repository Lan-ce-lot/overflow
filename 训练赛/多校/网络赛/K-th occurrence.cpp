//#include<bits/stdc++.h>
#include<queue>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<string.h>
#include<cmath>
#include<vector>
#include<map>
#define E (2.71828182)
#define PI (3.1415926535898)
#define    max(a,b)    ((a)>(b)?(a):(b))
#define    min(a,b)    ((a)>(b)?(b):(a))
#define    mem(a,b)    memset(a,b,sizeof(a))
#define    _max(a,b,c)    (max(a,b)>c?max(a,b):c)
#define mod    1000000007
#include<set>
#define gc getchar
#define debug(a) cout << "*" << a << "*" << endl
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
const long long  MAX_V = 5005, INF = 2147483647, MOD = 100000007;
#include <iostream>
using namespace std;

int a[100005], b[100005], c[100005], cnt, x;
int m, n;
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
    {
        cin >> x;
        b[100000 - i] = x;
    }
    for (int i = 100000 - m + 1; i <= 100000; i++)
    {
        if (c[b[i]] == 0)
        {
            c[b[i]]++;
            if (cnt != m + 1)
            cout << b[i] << ' ';
            else
            cout << b[i] << endl;
            cnt++;
        }
        else if (cnt == m - 1)
        break;
    }
    for (int i = 0; i < n; i++)
    {
        if (c[a[i]] == 0)
        {
            c[a[i]]++;
            if (cnt != m + 1)
            cout << a[i] << ' ';
            else
            cout << a[i] << endl;
            cnt++;
        }
        else if (cnt == m - 1)
        break;
    }
}
