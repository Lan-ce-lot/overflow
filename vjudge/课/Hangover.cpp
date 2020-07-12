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
int t, n;



int a, b, c;

/*
1
ABCD EFGH even
ABCI EFJK up
ABIJ EFGH even


*/

bool vis[maxn];
string str1[3], str2[3], heve[3];
void solve()
{
    cin >> t;
    while (t--)
    {
        memset(vis, 0, sizeof vis);
        map<char, int> M;
        for (int i = 0; i < 3; i++)
        {
            cin >> str1[i] >> str2[i] >> heve[i];
        }

        for (int i = 0; i < 3; i++)
        {
            if (heve[i] == "up")
            {
                for (int j = 0; j < str1[i].size(); j++)
                {
                        M[str1[i][j]] ++;
                        M[str2[i][j]] --;
                }
            }
            else if (heve[i] == "down")
            {
                for (int j = 0; j < str1[i].size(); j++)
                {
                        M[str1[i][j]] --;
                        M[str2[i][j]] ++;
                }
            }
        }
        for (int i = 0; i < 3; i++)
        {
            if (heve[i] == "even")
            {
                for (int j = 0; j < str1[i].size(); j++)
                {
                    vis[str1[i][j]] = 1;
                    vis[str2[i][j]] = 1;
                }
            }
        }
        char fake;
        int MAX = -1;
        for (int i = 'A'; i <= 'L'; i++)
        {
            if (vis[i] != 1 && MAX <= abs(M[i]))
            {
                MAX = abs(M[i]);
                fake = i;
            }
        }
        cout<< fake << " is the counterfeit coin and it is ";
        if(M[fake]>0)
            cout<<"heavy."<<endl;
        else
            cout<<"light."<<endl;
    }
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}
