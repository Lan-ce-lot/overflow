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
#define debug(a) cout << "*" << a << "*" << endl
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 1005;
int t, n;
vector<string> S;
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
int a[4];
int num[10][4];
void solve()
{
    S.clear();
    n = read();
    int ans = 0;
    memset(num, 0, sizeof(num));
    for (int i = 0;i < n; i++)
    {
        string str;
        cin >> str;
        S.push_back(str);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            num[S[i][j] - '0'][j]++;
        }
    }
//    for (int i = 0; i < 10; i++)
//    {
//        for (int j = 0; j < 4; j++)
//        {
//            cout << num[i][j] <<' ';
//        }
//        puts("");
//    }

    int flag = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j != i)
            {
                if (S[i] == S[j])
                {
                    flag = 1;
                    ans++;
                    int flag2 = 0;

                    for (int x = 0; x < 10; x++)
                    {
                        for (int y = 0; y < 4; y++)
                        {
                            if (num[x][y] == 0)
                            {

                                S[i][y] = char(x + '0');
//                                debug(S[i][y]);

                                num[S[i][y] - '0'][y]++;
                                flag2 = 1;
                                break;
                            }
                        }
                        if(flag2)
                            break;
                    }
                }

            }
        }
    }
    if (!flag)
    {
        cout << 0 << endl;
        for (int i = 0; i < n; i++)
        {
            cout << S[i] << endl;
        }
    }
    else
    {
        cout << ans << endl;
        for (int i = 0; i < n; i++)
        {
            cout << S[i] << endl;
        }
    }




}



int main()
{
//    ios::sync_with_stdio(false);
    t = read();
    while (t--)
    {
        solve();
    }
    return 0;
}
/*
2
2
1337
1337
*/
