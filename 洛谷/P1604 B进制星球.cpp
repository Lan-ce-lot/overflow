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
string a, b;
vector <int > A, B, C;
map<char, int> M;
map<int, char> P;
vector<int> add(vector<int> &A, vector<int> &B)
{
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
        C.push_back(t % n);
        t /= n;
    }
    if (t)
    {
        C.push_back(t);
    }
    return C;
}

void solve()
{
    for (int i = 0; i < 10; i++)
    {
        M['0' + i] = i;
        P[i] = '0' + i;
    }
    for (int i = 10; i < 36; i++)
    {
        M['A' + i - 10] = i;
        P[i] = 'A' + i - 10;
    }
    cin >> n;
    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; i--)
    {
        A.push_back(M[a[i]]);
    }
    for (int i = b.size() - 1; i >= 0; i--)
    {
        B.push_back(M[b[i]]);
    }


    C = add(A, B);
    string ans = "";
    reverse(C.begin(), C.end());
    for (auto i : C)
        ans += P[i];
        cout << ans ;
    puts("");


}

int main()
{
    solve();
//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    return 0;
}

