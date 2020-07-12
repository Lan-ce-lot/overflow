/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description:
 ************************************************************************/
//#include <bits/stdc++.h>
//#pragma comment(linker, "/STACK:102400000,102400000")//add_stack
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
typedef pair<int, int> PII;
const double pi = acos(-1.0);
const double eps = 1e-6;
const int mod = 1e9 + 7;
#define debug(a) cout << "*" << a << "*" << endl
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 1000005;
//sacnf("%lf") printf("%f")
ll read()
{
    ll x = 0,f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
	{
		if (ch == '-')
		f = -1;
		ch = getchar();
	}
    while (ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
    return x * f;
}

vector<int> add(vector<int> &A, vector<int> &B)
{
    vector<int> C;

    int t = 0;
    for (int i = 0; i < A.size() || i < B.size(); i++)
    {
        if (i < A.size())
            t += A[i];
        if (i < B.size())
            t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }
    if (t)
        C.push_back(1);
    reverse(C.begin(), C.end());
    return C;
}



ll t, n, m, r, c;

void solve()
{
    string a, b;
    cin >> t;
    while (t--)
    {
        cin >> a;
        int flag = 0, pos = 0;
//        cout << *a.begin() << endl;
        if (*a.begin() == '+' || *a.end() == '+')
        {
            cout << "skipped" << endl;
            break;
        }
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] == '+')
            {
                if (pos)
                {
                    flag = 1;
                }
                pos = i;
            }

        }
        if (flag)
        {
            cout << "skipped" << endl;
            break;
        }
debug(pos);
//        b = b.substr(pos + 1, a.size() - pos);
//        a = a.substr(0, pos);
//
////        debug(a);
////        debug(b);
//        vector<int> A, B;
//        for (int i = a.size() - 1; i >= 0; i--)
//        {
//            A.push_back(a[i] - '0');
//        }
//        for (int i = b.size() - 1; i >= 0; i--)
//        {
//            B.push_back(b[i] - '0');
//        }
//
//        auto C = add(A, B);
//
//        for (auto i : C)
//        {
//            cout << i;
//        }
//        puts("");

    }

}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

