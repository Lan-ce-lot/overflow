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
typedef pair<int, int> PII;
const double pi = acos(-1.0);
const int eps = 1e-10;
const int mod = 1e9 + 7;
#define debug(a) cout << "*" << a << "*" << endl
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 100005;

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
int t, n;

vector<int> add(vector<int> &A, vector<int> &B)
{
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size() || i < B.size(); i++)
    {
        if (i < A.size())
        {
            t += A[i];
        }
        if (i < B.size())
        {
            t += B[i];
        }
            C.push_back(t % 10);
            t /= 10;

    }
    if (t)
        C.push_back(1);
//    while (C.size() > 1 && C[C.size() - 1] == 0)
//    {
//        C.pop_back();
//    }
    reverse(C.begin(), C.end());
    return C;
}


string str_a, str_b;
void solve()
{

    vector<int> A, B, C;
    cin >> str_a >> str_b;
    for (int i = str_a.size() - 1; i >= 0; i--)
    {
        A.push_back(str_a[i] - '0');
    }
    for (int i = str_b.size() - 1; i >= 0; i--)
    {
        B.push_back(str_b[i] - '0');
    }
//    debug()
    C = add(A, B);
    for (auto i : C)
    {

        cout << i ;
    }
    puts("");

}

int main()
{
    solve();
//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    return 0;
}

