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
int t, n, m;
int a[maxn], ans = 0;
void solve()
{
    for (int z = 1; z < 10; z++)
    {
        for (int j = 1; j <= z; j++)
        {

            memset(a, 0, sizeof a);
            ans = 0;
            for (int k = 0; k < j; k++)
            {
                a[k] = 1;
            }sort(a,a+z);int temp = 0;
            do{
ans = 0;

            for(int i=0;i<z;i++)
            {
            	printf("%d ",a[i]);
			}
			int con = 0;
			for (int i = 0; i < z; i++)
            {
                if (a[i] == 0)
                {
                    con ++;
                }
                else
                {
                    ans += (z - i) * con;
                    con = 0;
                    ans += z - i;
                }

            }
            puts("");
            //debug(ans);
            temp = max(temp, ans);
        }while(next_permutation(a,a+z));
        debug(temp);

        }
    }
    cin >> t;
    while (t--)
    {
        cin >> n >>m;
    }
}

int main()
{
    solve();
//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    return 0;
}

