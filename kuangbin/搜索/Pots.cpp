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

struct node
{
    int a, b, step;
    string str;
    node(int aa = 0, int bb = 0, int ss = 0, string str1 = "") : a(aa), b(bb), step(ss), str(str1) {}
};
int t, n, A, B, C;
bool vis[maxn + 1][maxn + 1];
map <int, string> mm;
/*
FILL(1)
FILL(2)
DROP(1)
DROP(2)
POUR(1,2)
POUR(2,1)
*/
node top;
void bfs()
{
    queue <node> q;
    vis[0][0] = 1;
    q.push(node(0, 0, 0, ""));

    while (!q.empty())
    {

        top = q.front();
        if (top.a == C || top.b == C)
        {
            cout << top.step << endl << top.str;
            return ;
        }
        q.pop();
        for (int i = 0; i < 6; i++)
        {
            if (i == 0)
            {
                if (!vis[A][top.b])
                {
                    vis[A][top.b] = 1;
                    q.push(node(A, top.b, top.step + 1, top.str + mm[i]));
                }
            }
            else if (i == 1)
            {
                if (!vis[top.a][B])
                {
                    vis[top.a][B] = 1;
                    q.push(node(top.a, B, top.step + 1, top.str + mm[i]));
                }
            }
            else if (i == 2)
            {
                if (!vis[0][top.b])
                {
                    vis[0][top.b] = 1;
                    q.push(node(0, top.b, top.step + 1, top.str + mm[i]));
                }
            }
            else if (i == 3)
            {
                if (!vis[top.a][0])
                {
                    vis[top.a][0] = 1;
                    q.push(node(top.a, 0, top.step + 1, top.str + mm[i]));
                }
            }
            else if (i == 4)
            {
                int aa, bb;
                if ((top.a + top.b) / B)
                {
                    bb = B;
                    aa = (top.a + top.b) - B;
                }
                else
                {
                    bb = top.a + top.b;
                    aa = 0;
                }
                if (!vis[aa][bb])
                {
                    vis[aa][bb] = 1;
                    q.push(node(aa, bb, top.step + 1, top.str + mm[i]));
                }
            }
            else
            {
                int aa, bb;
                if ((top.a + top.b) / A)
                {
                    aa = A;
                    bb = (top.a + top.b) - A;
                }
                else
                {
                    aa = top.a + top.b;
                    bb = 0;
                }
                if (!vis[aa][bb])
                {
                    vis[aa][bb] = 1;
                    q.push(node(aa, bb, top.step + 1, top.str + mm[i]));
                }
            }
        }
    }
    cout << "impossible\n";
}




void solve()
{

    while (~scanf("%d%d%d", &A, &B, &C))
    {

        bfs();
    }
}

int main()
{
    mm[0] = "FILL(1)\n";
    mm[1] = "FILL(2)\n";
    mm[2] = "DROP(1)\n";
    mm[3] = "DROP(2)\n";
    mm[4] = "POUR(1,2)\n";
    mm[5] = "POUR(2,1)\n";
//    ios::sync_with_stdio(false);
    solve();

    return 0;
}

