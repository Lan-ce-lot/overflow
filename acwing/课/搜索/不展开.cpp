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
#include <unordered_map>
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
int t, n, dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
string str;
string endd = "12345678x";



int bfs(string str)
{
    unordered_map<string, int> M;
    queue<string> Q;

    Q.push(str);
    M[str] = 0;
    while (Q.size())
    {
        auto top = Q.front();
        if (top == endd)
        {
            return M[top];
        }
        Q.pop();
        int pos = top.find('x');
        int x = pos / 3, y = pos % 3;
        int temp = M[top];
        for (int i = 0; i < 4; i++)
        {
            int ax = x + dir[i][0], ay = y + dir[i][1];
            if (ax >= 0 && ax < 3 && ay >= 0 && ay < 3)
            {
                swap(top[ax * 3 + ay], top[pos]);
                if (!M.count(top))
                {
                    Q.push(top);
                    M[top] = temp + 1;
                }
                swap(top[ax * 3 + ay], top[pos]);

            }
        }
    }
    return -1;
}

void solve()
{
    for (int i = 0; i < 9; i++)
    {
        char c[2];
        cin >> c;
        str += c;
    }
//    debug(str);
    cout << bfs(str) << endl;
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

