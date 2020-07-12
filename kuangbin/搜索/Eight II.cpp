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

string ans_str;
string str1;
string str2;
int FAC[10] =
{
    1,
    1,
    2,
    6,
    24,
    120,
    720,
    5040,
    40320,
    362880
};

int t, n, tager;
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};//r, d, l, u
string mm = "rdlu";
bool vis[362880];

struct node
{
    int step;
    int state[10];
    int n;//0-8
    string way;
};

int cantor(int *a, int n)
{
    int x = 0;
    for (int i = 0; i < n; ++i)
    {
        int smaller = 0;  // 在当前位之后小于其的个数
        for (int j = i + 1; j < n; ++j)
        {
            if (a[j] < a[i])
                smaller++;
        }
        x += FAC[n - i - 1] * smaller; // 康托展开累加
    }
    return x;  // 康托展开值
}
node top;
void change(string str, int a[])
{
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            a[i] = str[i] - '0';
        }
        else
        {
            a[i] = 9;
        }
    }
}
bool test(int x, int y)
{

    if (x < 0 || x >= 3 || y < 0 || y >= 3)
        return 0;
    return 1;

}
        node te;
void bfs()
{
    queue <node> q;
    change(str1, top.state);
    top.step = 0;
    top.way = "";
    for (int i = 0; i < 9; i++)
    {
        if (top.state[i] == 9)
            top.n = i;
    }
    q.push(top);
    vis[cantor(top.state, 9)] = 1;
    while (!q.empty())
    {
        top = q.front();
        if (cantor(top.state, 9) == tager)
        {

            return;
        }
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                te.state[j] = top.state[j];
            }
            int xx = top.n / 3 + dir[i][0];
            int yy = top.n % 3 + dir[i][1];
            if (test(xx, yy))
            {

                te.n = xx * 3 + yy ;
                te.state[te.n] = 9;
                te.state[top.n] = top.state[te.n];
//                for (int k = 0; k < 9; k++)
//                {
//                    cout << te.state[k];
//                    if ((k + 1) % 3 == 0)
//                        puts("");
//                }

                te.step = top.step + 1;
                te.way = top.way + mm[i];
                if (!vis[cantor(te.state, 9)])
                {
                    q.push(te);
                    vis[cantor(te.state, 9)] = 1;

                }
            }

        }
    }
}



void solve()
{
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        memset(vis, 0, sizeof(vis));
        cin >> str1 >> str2;
        int str22[10];
        change(str2, str22);
        tager = cantor(str22, 9);
        bfs();


        cout << "Case " << i << ": " << top.step << endl;
        cout << top.way << endl;
    }
}





int main()
{
//    ios::sync_with_stdio(false);

    solve();

    return 0;
}

