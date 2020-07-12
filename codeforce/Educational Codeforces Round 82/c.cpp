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
ll t, n;
string str, ans;

void solve()
{
    cin >> t;
    while (t--)
    {
        cin >> str;
        ans = "";
        int j = 0;
        int flag = 0;
        map<char, bool> M;
        for (int i = 0; i < str.size(); i++)
        {
            if(M[str[i]] != 1)
            {
                if (j == ans.size() - 1)
                {
                    ans += str[i];
                    j++;
                    M[str[i]] = 1;
                }
                else if (j == 0)
                {
                    ans = str[i] + ans;
                    M[str[i]] = 1;
                }
                else
                {
                    flag = 1;
                    puts("NO");
                    break;
                }
            }
            else
            {
                if (j > 0 && ans[j - 1] == str[i])
                {
                    j--;
                }
                else if (j < ans.size() - 1 && ans[j + 1] == str[i])
                {
                    j++;
                }
                else
                {
                    flag = 1;
                    puts("NO");
                    break;
                }
            }
//            cout << ans << endl;
        }
        if (flag == 0)
        {
            puts("YES");
            cout << ans;
            for (int i = 0; i < 26; i++)
            {
                char ss = 'a' + i;
                if(M[ss] != 1)
                    cout << ss ;
            }
            puts("");
        }

    }
}
/*
10
5 2 2
6 1 3
5 2 10
gfsdsdsa




5
9
13
*/
int main()
{
//    cin >> str;
//    cout << 'a' + str << endl;
    solve();
//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    return 0;
}

